/*definition des fonctions d'affichage*/

#include "header.h"

/*fonction d'affichage du labyrinthe */
void affiche_lab(t_case labyrinthe[N][N]){
	int i = 0, j = 0;
	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++){
			switch(labyrinthe[i][j]){
				case mur:
					printf("U");
					break;
				case base:
					printf("*");
					break;
				case eau:
					printf("o");
					break;
				case repas:
					printf("R");
					break;
				case dodo:
					printf("D");
					break;
			}
		}
		printf("\n");
	}
}