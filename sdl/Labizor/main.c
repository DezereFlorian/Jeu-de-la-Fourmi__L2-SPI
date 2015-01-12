// menu du jeu permet de choisir entre la règle ou jouer
#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "header.h"





void jouerGUI (SDL_Surface *ecran, SDL_Surface *fourmi_SDL, SDL_Surface *imageDeFond, SDL_Rect positionFond, SDL_Rect positionFourmi)
{
    printf("je vais bientot mourir");
	//affiche_entrer(50);
	aleatoire();
	init_labyrinthe();
	vide_stock();
	gen_labyrinthe(ecran, imageDeFond, positionFond);
	gen_points(ecran, imageDeFond, positionFond);
	gen_stock();
	gen_fourmi();
	deplacement_fourmi(ecran, fourmi_SDL, imageDeFond, positionFond, positionFourmi);


}



int main(int argc, char *argv[])
{

printf("\ntypeCase : vide : %d",vide);
printf("\ntypeCase : mur : %d",mur);
printf("\ntypeCase : base : %d",eau);
printf("\ntypeCase : dodo : %d",dodo);
printf("\ntypeCase : manger : %d",manger);
printf("\ntypeCase : fourmi : %d",fourmi);
printf("\ntypeCase : troll_case : %d",troll_case);
printf("\ntypeCase : base : %d",base);

 SDL_Surface    *ecran = NULL,
                *imageDeFond = NULL,
                *imageDeFondMenu = NULL,
                *fourmi_SDL = NULL,
                *eau_SDL = NULL,
                *manger_SDL = NULL,
                *dodo_SDL= NULL,
                *jouer_SDL = NULL,
                *regle_SDL = NULL,
                *imageRegle_SDL = NULL,
                *quitter_SDL = NULL,
                *mur_SDL = NULL,
                *base_SDL = NULL;

    SDL_Rect positionFond,
             positionFourmi,
             positionJouer,
             positionRegle,
             positionImageRegle,
             positionQuitter;


    TTF_Font *police = NULL,
             *policeRegle = NULL;

    Mix_Music *musiqueMenu;

    SDL_Color couleurNoire = {0, 0, 0};

    SDL_Event event;

    int continuer = 1;




    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    if (SDL_Init(SDL_INIT_VIDEO) == -1) // Démarrage de la SDL. Si erreur :
    {
        fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError()); // Écriture de l'erreur
        exit(EXIT_FAILURE); // On quitte le programme
    }
        else if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) //Initialisation de l'API Mixer
        {
            printf("%s", Mix_GetError());
        }

        else  if(TTF_Init() == -1)
        {
            fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
            exit(EXIT_FAILURE);
        }

            else
            {
            /* Titre de la fenêtre */
            SDL_WM_SetCaption("Le Labyzor", NULL);



             /* Chargement de l'icône  */
            SDL_WM_SetIcon(IMG_Load("image/zozor_icone1.png"), NULL);

            /* Choisir la taille de l'écran */
            ecran = SDL_SetVideoMode(760, 768, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);



            /* Chargement d'images Bitmap dans une surface */
            imageDeFondMenu = IMG_Load("image/FondMenu.png");

            imageRegle_SDL = IMG_Load("image/FondRegle.png");

            imageDeFond = IMG_Load("image/Fond.png");

            fourmi_SDL = IMG_Load("image/zozor.png");

            eau_SDL = IMG_Load("image/eau.png");
            dodo_SDL = IMG_Load("image/lit.png");
            manger_SDL = IMG_Load("image/carotte.png");
            mur_SDL = IMG_Load("image/mur.png");

            /* Chargement de la police */
            police = TTF_OpenFont("texte/angelina.ttf", 80);
            policeRegle = TTF_OpenFont("texte/angelina.ttf", 60);




            jouer_SDL = TTF_RenderText_Blended(police, "j : Jouer", couleurNoire);
            regle_SDL = TTF_RenderText_Blended(police, "r : Regle", couleurNoire);
            quitter_SDL = TTF_RenderText_Blended(police, "q : Quitter", couleurNoire);


            musiqueMenu = Mix_LoadMUS("musique/Mexican.mp3");
            Mix_VolumeMusic(MIX_MAX_VOLUME / 4); //Mettre le volume à la moitié





            positionFond.x = 0;
            positionFond.y = 0;
            positionJouer.x = 260;
            positionJouer.y = 370;
            positionRegle.x = 75;
            positionRegle.y = 53;

            positionQuitter.x = 440;
            positionQuitter.y = 633;

           // positionFourmi.x =  ecran->w / 2 - fourmi_SDL->w / 2;
            //positionFourmi.y = ecran->h / 2 - fourmi_SDL->h / 2;

            positionFourmi = getBasePos();


            /*repetition des touches*/
            SDL_EnableKeyRepeat(10, 10);

            /* On efface l'écran */
            SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 33, 185, 29));

            /* Blit du texte sur l'ecran */
            SDL_BlitSurface(imageDeFondMenu, NULL, ecran, &positionFond);

            SDL_BlitSurface(jouer_SDL, NULL, ecran, &positionJouer);
            SDL_BlitSurface(regle_SDL, NULL, ecran, &positionRegle);
            SDL_BlitSurface(quitter_SDL, NULL, ecran, &positionQuitter);

            Mix_PlayMusic(musiqueMenu, -1);
            /* mis à jour de l'écran */
            SDL_Flip(ecran);

            /* Gestion des touches au clavier */
            SDL_Event event;
                while(continuer)
                        {
                            SDL_WaitEvent(&event);

                            switch(event.type)
                            {
                                 case SDL_QUIT:
                                        continuer = 0;
                                    break;

                                case SDL_KEYDOWN:
                                    switch(event.key.keysym.sym)
                                    {
                                        //choisir de jouer
                                        case SDLK_j:
                                                  jouerGUI(ecran, fourmi_SDL, imageDeFond, positionFond, positionFourmi);
                                                  //printf("jouer");

                                        break;

                                        //choisir la règle
                                       case SDLK_r:
                                                    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 33, 185, 29));
                                                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);

                                                    jouer_SDL = TTF_RenderText_Blended(policeRegle, "j : Jouer", couleurNoire);

                                                    positionImageRegle.x = 50;
                                                    positionImageRegle.y = 50;
                                                    positionJouer.x = 310;
                                                    positionJouer.y = 650;

                                                    SDL_BlitSurface(imageRegle_SDL, NULL, ecran, &positionFond);
                                                    SDL_BlitSurface(jouer_SDL, NULL, ecran, &positionJouer);
                                                    SDL_Flip(ecran);

                                        break;

                                        //arrête le jeu
                                        case SDLK_a:
                                                continuer = 0;
                                        break;

                                    }
                                break;

                        }








                    if (ecran == NULL) // Si l'ouverture a échoué, on le note et on arrête
                    {
                    fprintf(stderr, "Impossible de charger le mode vidéo : %s\n", SDL_GetError());
                    exit(EXIT_FAILURE);
                    }


                }
                /* Libération de la surface */
                SDL_FreeSurface(imageDeFond);
                SDL_FreeSurface(fourmi_SDL);
                SDL_FreeSurface(jouer_SDL);
                SDL_FreeSurface(regle_SDL);
                SDL_FreeSurface(quitter_SDL);
                Mix_FreeMusic(musiqueMenu);
                TTF_CloseFont(police);


            }
            Mix_CloseAudio();
            TTF_Quit();
            SDL_Quit();
            return EXIT_SUCCESS;

}
