#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

int main(int argc, char *argv[])
{
    SDL_Surface *ecran = NULL,
                *imageDeFond = NULL,
                *zozor = NULL,
                *eau = NULL,
                *nourriture = NULL,
                *lit = NULL,
                *jouer = NULL,
                *regle = NULL,
                *quitter = NULL;

    SDL_Rect positionFond,
             positionZozor,
             positionEau,
             positionLit,
             positionNourriture,
             positionJouer,
             positionRegle,
             positionQuitter;

    TTF_Font *police = NULL;

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

        else  if(TTF_Init() == -1)
        {
            fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
            exit(EXIT_FAILURE);
        }

            else
            {
            /* Titre de la fenêtre */
            SDL_WM_SetCaption("Labyrinthe", NULL);


             /* Chargement de l'icône  */
            SDL_WM_SetIcon(IMG_Load("image/zozor_icone1.png"), NULL);

            /* Choisir la taille de l'écran */
            ecran = SDL_SetVideoMode(1020, 720, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

            SDL_WM_SetCaption("Chargement d'images en SDL", NULL);

            /* Chargement d'images Bitmap dans une surface */
            imageDeFond = IMG_Load("image/Fond.png");
            zozor = IMG_Load("image/zozor.png");
            eau = IMG_Load("image/eau.png");
            lit = IMG_Load("image/lit.png");
            nourriture = IMG_Load("image/carotte.png");

            /* Chargement de la police */
            police = TTF_OpenFont("texte/angelina.ttf", 65);
            jouer = TTF_RenderText_Blended(police, "Jouer", couleurNoire);
            regle = TTF_RenderText_Blended(police, "Regle", couleurNoire);
            quitter = TTF_RenderText_Blended(police, "Quitter", couleurNoire);

            positionFond.x = 0;
            positionFond.y = 0;
            positionEau.x = 120;
            positionEau.y = 240;
            positionNourriture.x = 340;
            positionNourriture.y = 150;
            positionLit.x = 600;
            positionLit.y = 349;



            positionJouer.x = 320;
            positionJouer.y = 150;
            positionRegle.x = 400;
            positionRegle.y = 300;
            positionQuitter.x = 480;
            positionQuitter.y = 460;

            positionZozor.x =  ecran->w / 2 - zozor->w / 2;
            positionZozor.y = ecran->h / 2 - zozor->h / 2;


            /*repetition des touches*/
            SDL_EnableKeyRepeat(10, 10);

            /* On efface l'écran */
            SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 33, 185, 29));

            /* Blit du texte sur l'ecran */
            SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
            SDL_BlitSurface(jouer, NULL, ecran, &positionJouer);
            SDL_BlitSurface(regle, NULL, ecran, &positionRegle);
            SDL_BlitSurface(quitter, NULL, ecran, &positionQuitter);
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

                                                                            positionZozor.y = positionZozor.y-8;

                                                                            break;
                                                                        case SDLK_DOWN:

                                                                            positionZozor.y = positionZozor.y+8;

                                                                            break;
                                                                        case SDLK_RIGHT:

                                                                            positionZozor.x = positionZozor.x+8;

                                                                            break;
                                                                        case SDLK_LEFT:

                                                                            positionZozor.x = positionZozor.x-8;

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
                TTF_CloseFont(police);


            }
            SDL_Quit();
            TTF_Quit();
            return EXIT_SUCCESS;

}
