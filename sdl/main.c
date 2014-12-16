#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

int main(int argc, char *argv[])
{
    SDL_Surface *ecran = NULL,
                *imageDeFond = NULL,
                *imageDeFondMenu = NULL,
                *zozor = NULL,
                *eau = NULL,
                *nourriture = NULL,
                *lit = NULL,
                *jouer = NULL,
                *regle = NULL,
                *imageRegle = NULL,
                *quitter = NULL;

    SDL_Rect positionFond,
             positionZozor,
             positionEau,
             positionLit,
             positionNourriture,
             positionJouer,
             positionRegle,
             positionImageRegle,
             positionQuitter;

    TTF_Font *police = NULL,
             *policeRegle = NULL;

    Mix_Music *musique,
              *musiqueRegle,
              *musiqueMenu;

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
            ecran = SDL_SetVideoMode(1020, 720, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);



            /* Chargement d'images Bitmap dans une surface */
            imageDeFondMenu = IMG_Load("image/FondMenu.png");

            imageDeFond = IMG_Load("image/Fond.png");

            zozor = IMG_Load("image/zozor.png");

            eau = IMG_Load("image/eau.png");
            lit = IMG_Load("image/lit.png");
            nourriture = IMG_Load("image/carotte.png");

            /* Chargement de la police */
            police = TTF_OpenFont("texte/angelina.ttf", 80);
            policeRegle = TTF_OpenFont("texte/angelina.ttf", 60);




            jouer = TTF_RenderText_Blended(police, "Jouer", couleurNoire);
            regle = TTF_RenderText_Blended(police, "Regle", couleurNoire);
            quitter = TTF_RenderText_Blended(police, "Quitter", couleurNoire);

            musique = Mix_LoadMUS("musique/libere_delivre.mp3");
            musiqueRegle = Mix_LoadMUS("musique/Hip_Hop_Chicken.mp3");
            musiqueMenu = Mix_LoadMUS("musique/Mexican.mp3");
            Mix_VolumeMusic(MIX_MAX_VOLUME / 8); //Mettre le volume à la moitié

            positionFond.x = 0;
            positionFond.y = 0;
            positionEau.x = 120;
            positionEau.y = 240;
            positionNourriture.x = 340;
            positionNourriture.y = 150;
            positionLit.x = 600;
            positionLit.y = 349;



            positionJouer.x = 430;
            positionJouer.y = 390;
            positionRegle.x = 130;
            positionRegle.y = 120;

            positionQuitter.x = 740;
            positionQuitter.y = 550;

            positionZozor.x =  ecran->w / 2 - zozor->w / 2;
            positionZozor.y = ecran->h / 2 - zozor->h / 2;


            /*repetition des touches*/
            SDL_EnableKeyRepeat(10, 10);

            /* On efface l'écran */
            SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 33, 185, 29));

            /* Blit du texte sur l'ecran */
            SDL_BlitSurface(imageDeFondMenu, NULL, ecran, &positionFond);
            SDL_BlitSurface(jouer, NULL, ecran, &positionJouer);
            SDL_BlitSurface(regle, NULL, ecran, &positionRegle);
            SDL_BlitSurface(quitter, NULL, ecran, &positionQuitter);

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
                                        case SDLK_j:
                                                    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 33, 185, 29));
                                                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);

                                                    SDL_BlitSurface(eau, NULL, ecran, &positionEau);
                                                    SDL_BlitSurface(lit, NULL, ecran, &positionLit);
                                                    SDL_BlitSurface(nourriture, NULL, ecran, &positionNourriture);
                                                    SDL_BlitSurface(zozor, NULL, ecran, &positionZozor);


                                                    Mix_PlayMusic(musique, -1);

                                                    while(continuer)
                                                        {
                                                            SDL_WaitEvent(&event);

                                                            switch(event.type)
                                                            {
                                                                 case SDL_QUIT: continuer = 0;
                                                                    break;

                                                                case SDL_KEYDOWN:
                                                                    switch(event.key.keysym.sym)
                                                                    {
                                                                        case SDLK_UP:
                                                                            if(positionZozor.y > 50){
                                                                            positionZozor.y = positionZozor.y-4;
                                                                            }

                                                                            break;
                                                                        case SDLK_DOWN:
                                                                            if(positionZozor.y < 620){
                                                                            positionZozor.y = positionZozor.y+4;
                                                                            }

                                                                            break;
                                                                        case SDLK_LEFT:
                                                                            if(positionZozor.x > 50){
                                                                            positionZozor.x = positionZozor.x-4;
                                                                            }

                                                                            break;
                                                                        case SDLK_RIGHT:
                                                                            if(positionZozor.x < 920){
                                                                            positionZozor.x = positionZozor.x+4;
                                                                            }

                                                                            break;

                                                                        case SDLK_ESCAPE:
                                                                            continuer = 0;
                                                                            break;

                                                                    }
                                                                break;

                                                        }
                                                        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 33, 185, 29));
                                                        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);

                                                        SDL_BlitSurface(eau, NULL, ecran, &positionEau);
                                                        SDL_BlitSurface(lit, NULL, ecran, &positionLit);
                                                        SDL_BlitSurface(nourriture, NULL, ecran, &positionNourriture);
                                                        SDL_BlitSurface(zozor, NULL, ecran, &positionZozor);
                                                        SDL_Flip(ecran);
                                                    }

                                        break;

                                       case SDLK_r:
                                                    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 33, 185, 29));
                                                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                                                    Mix_PlayMusic(musiqueRegle, -1);
                                                    jouer = TTF_RenderText_Blended(policeRegle, "Jouer", couleurNoire);

                                                    positionImageRegle.x = 50;
                                                    positionImageRegle.y = 50;
                                                    positionJouer.x = 460;
                                                    positionJouer.y = 600;
                                                    SDL_BlitSurface(jouer, NULL, ecran, &positionJouer);
                                                    SDL_BlitSurface(imageRegle, NULL, ecran, &positionImageRegle);
                                                    SDL_Flip(ecran);

                                        break;

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
                SDL_FreeSurface(zozor);
                SDL_FreeSurface(jouer);
                SDL_FreeSurface(regle);
                SDL_FreeSurface(quitter);
                Mix_FreeMusic(musique);
                TTF_CloseFont(police);


            }
            Mix_CloseAudio();
            TTF_Quit();
            SDL_Quit();
            return EXIT_SUCCESS;

}
