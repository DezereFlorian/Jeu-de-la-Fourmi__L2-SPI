/* Page contenant le deplacement de la fourmi */

#include "header.h"

/* fonction permettant de verifier si la fourmi peut se deplacer*/
int verif_deplacement(int id_fourmi){
	//renvoi vrai si le deplacement peut avoir lieu 
	if (population[id_fourmi].eau <= 0 || population[id_fourmi].dodo <= 0 || population[id_fourmi].repas <= 0){
		printf("La fourmi ne peut pas se deplacer, plus assez de ressources...\n");
		return 0;
	}
	else return 1;
}

/*fonction permettant le deplacement des fourmis dans le labyrinthe de facon aleatoire */
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
