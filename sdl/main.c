#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL_image.h>



int main(int argc, char *argv[])
{
    SDL_Surface *ecran = NULL, *imageDeFond = NULL, *zozor = NULL;
    SDL_Rect positionFond, positionZozor;
    SDL_Event event;

    int continuer = 1;




    if (SDL_Init(SDL_INIT_VIDEO) == -1) // D�marrage de la SDL. Si erreur :
    {
        fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError()); // �criture de l'erreur
        exit(EXIT_FAILURE); // On quitte le programme
    }
    else{
            // Le pointeur qui va stocker la surface de l'�cran

        SDL_Init(SDL_INIT_VIDEO);
         /* Chargement de l'ic�ne AVANT SDL_SetVideoMode */
        SDL_WM_SetIcon(SDL_LoadBMP("image/sdl_icone.bmp"), NULL);

        /* Choisir la taille de l'�cran */
        ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

        SDL_WM_SetCaption("Chargement d'images en SDL", NULL);

        /* Chargement d'images Bitmap dans une surface */
        imageDeFond = IMG_Load("image/mur.png");
        zozor = IMG_Load("image/zozor.png");

        /* On rend le bleu derri�re Zozor transparent : */
        SDL_SetColorKey(zozor, SDL_SRCCOLORKEY, SDL_MapRGB(zozor->format, 0, 0, 255));


        positionFond.x = 0;
        positionFond.y = 0;

        positionZozor.x =  ecran->w / 2 - zozor->w / 2;
        positionZozor.y = ecran->h / 2 - zozor->h / 2;

        /* On blitte l'image sur le fond : */
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_BlitSurface(zozor, NULL, ecran, &positionZozor);

        /*repetition des touches*/
        SDL_EnableKeyRepeat(10, 10);



            if (ecran == NULL) // Si l'ouverture a �chou�, on le note et on arr�te
            {
                fprintf(stderr, "Impossible de charger le mode vid�o : %s\n", SDL_GetError());
                exit(EXIT_FAILURE);
            }

        SDL_WM_SetCaption("Labyrinthe", NULL);

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
                                case SDLK_UP: // Fl�che haut
                                    positionZozor.y = positionZozor.y-4;
                                    break;
                                case SDLK_DOWN: // Fl�che bas
                                    positionZozor.y = positionZozor.y+4;
                                    break;
                                case SDLK_RIGHT: // Fl�che droite
                                    positionZozor.x = positionZozor.x+4;
                                    break;
                                case SDLK_LEFT: // Fl�che gauche
                                    positionZozor.x = positionZozor.x-4;
                                    break;
                            }
                            break;
                    }
                    /* On efface l'�cran */
                    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 33, 185, 29));
                    /* On place Zozor � sa nouvelle position */
                    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
                    SDL_BlitSurface(zozor, NULL, ecran, &positionZozor);
                    /* On met � jour l'affichage */
                    SDL_Flip(ecran);
                }

                SDL_FreeSurface(imageDeFond); // Lib�ration de la surface
                SDL_FreeSurface(zozor);

        }

    SDL_Quit();

    return EXIT_SUCCESS;


}


