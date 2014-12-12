#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>


/*void menu(int * continuer)
{
SDL_Event event;
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
                                    case SDLK_j:
                                                    SDL_BlitSurface(&eau, NULL, ecran, &positionEau);
                                                    SDL_BlitSurface(&lit, NULL, ecran, &positionLit);
                                                    SDL_BlitSurface(&nourriture, NULL, ecran, &positionNourriture);
                                                    SDL_BlitSurface(&zozor, NULL, ecran, &positionZozor);

                                                    SDL_Flip(&ecran);
                                    break;

                                   case SDLK_r:
                                                    SDL_FillRect(&ecran, NULL, SDL_MapRGB(ecran->format, 33, 185, 29));

                                                    SDL_BlitSurface(&imageDeFond, NULL, ecran, &positionFond);

                                                    SDL_Flip(&ecran);
                                    break;


                                }
                            break;

                    }

}*/
