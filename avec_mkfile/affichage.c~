/*definition des fonctions d'affichage*/

#include "header.h"

/*fonction d'affichage du labyrinthe */
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

 /* fonction permettant l'affichage d'un certain nombre de ligne vide */
 void affiche_entrer(int tmp){
 	int i = 0;
 	for (i = 0; i < tmp; i++){
 		printf("\n");
 	}
 }
