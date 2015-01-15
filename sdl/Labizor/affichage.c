/**
* \file affichage.c
* \brief Definition des fonctions d'affichage
* \author Jean-baptiste Dubois, Provost Valentin, Dezere Florian
* \version 1.0
* \date 6 Janvier 2014
*
*/



#include "header.h"

/**
*\fn void affiche_lab(void)
*\brief Fonction d'affichage du labyrinthe
*/

void affiche_lab(void){
	int i = 0, j = 0;
	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++){
			switch(emplacement[i][j]){
				case mur:
					printf("&");
					break;
				/*case base:
					printf("*");
					break;*/
				case eau:
					printf("o");
					break;
				case manger:
					printf("R");
					break;
				case dodo:
					printf("D");
					break;
				case vide:
					printf(" ");
					break;
			}
			if (labyrinthe[i][j] == fourmi){
				printf("x");
			}
		}
		affiche_entrer(1);
	}
	affiche_entrer(2);
}

/**
*\fn void affiche_entrer(int tmp)
*\brief Fonction permettant l'affichage d'un certain nombre de ligne vide
*\param int tmp nombre de retour chariot à afficher
*/

 void afficher_entrer(int tmp){
 	int i = 0;
 	for (i = 0; i < tmp; i++){
 		printf("\n");
 	}
 }
  void affiche_entrer(int tmp){
 	int i = 0;
 	for (i = 0; i < tmp; i++){
 		printf("\n");
 	}
 }


void pause(void){
    int continuer = 1;
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
                                //arrête le jeu
                                case SDLK_a:
                                        continuer = 0;
                                break;

                            }
                        break;

                    }

                }
}


void positionner_element(SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Surface *element_SDL, SDL_Rect positionFond, int x, int y){



            SDL_Rect positionElement;

            positionElement.x = Taille_Bloc * x + 42;
            positionElement.y = Taille_Bloc * y + 46;
            printf("x %d , y %d",positionElement.x,positionElement.y);


    SDL_BlitSurface(element_SDL, NULL, ecran, &positionElement);


    SDL_Flip(ecran);


}

void afficher_labyrinthe(SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionFond)
{

    SDL_Surface *manger_SDL = NULL,
                *dodo_SDL = NULL,
                *mur_SDL = NULL,
                *eau_SDL = NULL;

    manger_SDL = IMG_Load("image/carotte.png");
    dodo_SDL = IMG_Load("image/lit.png");
    eau_SDL = IMG_Load("image/eau.png");
    mur_SDL = IMG_Load("image/mur.png");
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 33, 185, 29));

    /* Blit du fond sur l'ecran */
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
    int i = 0, j = 0;
    afficher_matrice();
	for (i = 0; i < N; i++)
    {
		for (j = 0; j < N; j++)
		{

                if(labyrinthe[i][j] == mur)
                {
                    positionner_element(ecran, imageDeFond, mur_SDL, positionFond, i, j);
                }
                else if(labyrinthe[i][j] == eau)
                {
                    positionner_element(ecran, imageDeFond, eau_SDL, positionFond, i, j);
                }
                else if(labyrinthe[i][j] == manger)
                {
                    positionner_element(ecran, imageDeFond, manger_SDL, positionFond, i, j);
                }
                else if(labyrinthe[i][j] == dodo)
                {
                    positionner_element(ecran, imageDeFond, dodo_SDL, positionFond, i, j);
                }
		}
	}
}

void afficher_matrice()
{
      int i = 0, j = 0;
	for (i = 0; i < N; i++)
    {
        printf("\n");
		for (j = 0; j < N; j++)
		{
		    printf(" [%d] ",labyrinthe[i][j]);
		}
    }
}
