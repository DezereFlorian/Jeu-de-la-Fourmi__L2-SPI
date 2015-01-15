/**
* \file deplacement.c
* \brief Page contenant le deplacement de Zozor
* \author Jean-baptiste Dubois, Provost Valentin, Dezere Florian
* \version 1.0
* \date 6 Janvier 2014
*
*/

#include "header.h"


/**
*\fn int verif_deplacement(int id_fourmi)
*\brief Fonction permettant de verifier si Zozor peut se deplacer
*\param int id_fourmi est l'identifiant de Zozor
*\return renvoi vrai si le déplacement peut avoir lieu sinon faux
*/


int verif_deplacement(int id_fourmi){
	//renvoi vrai si le deplacement peut avoir lieu
	if (population[id_fourmi].eau <= 0 || population[id_fourmi].dodo <= 0 || population[id_fourmi].repas <= 0){
		printf("La fourmi ne peut pas se deplacer, plus assez de ressources...\n");
		return 0;
	}
	else return 1;
}



/**
*\fn void mv_fourmi(int id_fourmi)
*\brief Fonction permettant le deplacement des fourmis dans le labyrinthe de façon aleatoire
*\param int id_fourmi est l'identifiant de Zozor
*/


void mv_fourmi(int id_fourmi){
 	int choix = 0, x = 0, y = 0, ok = 0, fin_fct = 0, mouvement = 0, fin_jeu = 0; //ok permet de savoir si le deplacement peut se faire, fin_fct permet de savoir si le programme doit continuer, mouvement permet de savoir si une fourmi a assez de ressource pour se deplacer
 	//on recupere les coordonnees en x et y de la fourmi dont les deplacements sont a verifier

 	//remplacer 100 par 5
 	//LES MURS SE DECALENT AVEC LA FOURMI
 	x = population[id_fourmi].x;
 	y = population[id_fourmi].y;
 	mouvement = verif_deplacement(id_fourmi);
 	if (mouvement == 0) fin_fct = 100;
 	while (fin_fct != 100){
	 	while (ok == 0 && fin_fct != 100){
	 		affiche_lab();
	 		etat_fourmi(id_fourmi);
	 		printf("\nChoisissez la direction vers laquelle la fourmi doit aller: \n 1-- Gauche\n 2-- Droite\n 3-- Haut\n 4-- Bas\n 5-- Ne pas bouger\n Votre choix: ");
	 		choix = verif_saisie(1,5);

	 		switch (choix){
	 			case 1: if (population[id_fourmi].y - 1 >= 0 && emplacement[x][y-1] != mur) ok = 1; break;

	 			case 2: if (population[id_fourmi].y + 1 <= 11 && emplacement[x][y+1] != mur) ok = 1; break;

	 			case 3: if (population[id_fourmi].x + 1 <= 11 && emplacement[x+1][y] != mur) ok = 1; break;

	 			case 4: if (population[id_fourmi].x - 1 >= 0 && emplacement[x-1][y] != mur) ok = 1; break;

	 			case 5: fin_fct = 100; break;
	 		}
	 		if (fin_fct != 100 && ok == 1){

	 			labyrinthe[population[id_fourmi].x][population[id_fourmi].y] = vide;

	 			switch (choix){
					case 1 : population[id_fourmi].y = population[id_fourmi].y-1; break;

					case 2 : population[id_fourmi].y = population[id_fourmi].y+1; break;

					case 3 : population[id_fourmi].x = population[id_fourmi].x-1; break;

					case 4 : population[id_fourmi].x = population[id_fourmi].x+1; break;
				}

				labyrinthe[population[id_fourmi].x][population[id_fourmi].y] = fourmi;

				if (emplacement[population[id_fourmi].x][population[id_fourmi].y] == troll_case){

					fin_jeu = end_game();

					if (fin_jeu >= 3){
						population[id_fourmi].eau = 0;
						population[id_fourmi].repas = 0;
						population[id_fourmi].dodo = 0;
					}

					afficher_entrer(3);
					printf("PERDU! Sans visiblement aucune raison apparente... dommage pour vous");
				}

				population[id_fourmi].total_mv = population[id_fourmi].total_mv + 1;

				if (population[id_fourmi].total_mv%2 == 0){
					population[id_fourmi].eau = population[id_fourmi].eau - 1;

				}

				if (population[id_fourmi].total_mv%5 == 0){
					population[id_fourmi].dodo = population[id_fourmi].dodo - 1;
				}

				population[id_fourmi].repas = population[id_fourmi].repas - 1;
			}

			else {
				if (ok == 0 && fin_fct != 100){
					printf("\nLa fourmi ne peut satisfaire votre demande de deplacement, veuillez entrez une nouvelle direction:\n");
				}
				fin_fct++;

				mouvement = verif_deplacement(id_fourmi);
				if (mouvement == 0) fin_fct = 100;
			}
		}
		ok = 0;
	}
}

void deplacement_fourmi(SDL_Surface *ecran, SDL_Surface *fourmi_SDL, SDL_Surface *imageDeFond,SDL_Rect positionFond, SDL_Rect positionFourmi){
    int continuer = 1;
     SDL_Event event;
     while(continuer)
                {
                    SDL_WaitEvent(&event);
                    SDL_EnableKeyRepeat(1000, 1000);
                    switch(event.type)
                    {
                        case SDL_QUIT:
                            continuer = 0;
                            exit(0);
                            break;
                        case SDL_KEYDOWN:
                            switch(event.key.keysym.sym)
                            {
                                case SDLK_UP: // Flèche haut


                                    if(verif_mur_fourmi_troll_case(positionFourmi.x, (positionFourmi.y - Taille_Bloc), ecran, imageDeFond, positionFond))
                                       {
                                            positionFourmi.y = positionFourmi.y - Taille_Bloc;
                                            afficher_labyrinthe(ecran, imageDeFond, positionFond);
                                            SDL_BlitSurface(fourmi_SDL, NULL, ecran, &positionFourmi);

                                       }


                                    break;
                                case SDLK_DOWN: // Flèche bas
                                    if(verif_mur_fourmi_troll_case(positionFourmi.x, (positionFourmi.y + Taille_Bloc), ecran, imageDeFond, positionFond))
                                       {
                                            positionFourmi.y = positionFourmi.y + Taille_Bloc;
                                            afficher_labyrinthe(ecran, imageDeFond, positionFond);
                                            SDL_BlitSurface(fourmi_SDL, NULL, ecran, &positionFourmi);

                                       }

                                    break;
                                case SDLK_RIGHT: // Flèche droite
                                    if(verif_mur_fourmi_troll_case((positionFourmi.x + Taille_Bloc), positionFourmi.y, ecran, imageDeFond, positionFond))
                                       {
                                        positionFourmi.x = positionFourmi.x + Taille_Bloc;
                                        afficher_labyrinthe(ecran, imageDeFond, positionFond);
                                        SDL_BlitSurface(fourmi_SDL, NULL, ecran, &positionFourmi);

                                       }

                                    break;
                                case SDLK_LEFT: // Flèche gauche
                                    if(verif_mur_fourmi_troll_case((positionFourmi.x - Taille_Bloc), positionFourmi.y, ecran, imageDeFond, positionFond))
                                       {
                                            positionFourmi.x = positionFourmi.x - Taille_Bloc;
                                            afficher_labyrinthe(ecran, imageDeFond, positionFond);
                                            SDL_BlitSurface(fourmi_SDL, NULL, ecran, &positionFourmi);

                                       }

                                    break;

                                     case SDLK_p:
                                                    if(Mix_PausedMusic() == 1)//Si la musique est en pause
                                                    {
                                                        Mix_ResumeMusic(); //Reprendre la musique
                                                    }
                                                    else
                                                    {
                                                        Mix_PauseMusic(); //Mettre en pause la musique
                                                    }
                                        break;

                                case SDLK_a:
                                    continuer = 0;

                                    break;
                            }
                            break;


                    }

                    /* On met à jour l'affichage */

                    SDL_Flip(ecran);


                }

}

int verif_mur_fourmi_troll_case(int x, int y, SDL_Surface *ecran, SDL_Surface *imageDeFond,SDL_Rect positionFond){
    int posMatX, posMatY;


    if(x<0 || y<0){
        return 0;
    }

        posMatX = (x - 42) / Taille_Bloc;
        posMatY = (y - 46) / Taille_Bloc;
        if(posMatX > N-1 || posMatY > N-1)
        {
            return 0;
        }

            if(labyrinthe[posMatX][posMatY] != mur) {
                return 1;
            }
            else if(labyrinthe[posMatX][posMatY] = troll_case)
            {

                troll_case_SDL(ecran, imageDeFond, positionFond);
                _sleep(5000);
                exit(0);
                printf("bloquer case : [%d , %d] posx %d , posy %d  typeCase %d\n",posMatX,posMatY,x,y,labyrinthe[posMatX][posMatY]);
                return 0;
            }

}

