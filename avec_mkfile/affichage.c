/*definition des fonctions d'affichage*/

#include "header.h"

/*fonction d'affichage du labyrinthe */
void affiche_lab(t_case labyrinthe[N][N]){
	int i = 0, j = 0;
	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++){
			if (labyrinthe[i][j] == mur){
				printf("U");
			} else {
				if (labyrinthe[i][j] == base){
						printf("*");
				} else {
					if (labyrinthe[i][j] == eau){
						printf("o");
					} else {
						if (labyrinthe[i][j] == repas){
						printf("R");
						} else {
							if (labyrinthe[i][j] == dodo){
								printf("D");
							}
						}
					}
				}
			}
		}
	}
}