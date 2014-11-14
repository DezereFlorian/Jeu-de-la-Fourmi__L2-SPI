/*definition des fonctions permettant de gerer les stocks de chaques points, de la cration au retrait */

#include "header.h"


/*fonction qui permet de creer un stock aleatoire pour chaque point important*/
void gen_stock (t_case labyrinthe[N][N], int stock[N][N]){
	int i = 0, j = 0; 
	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++){
			if (labyrinthe[i][j] == eau || labyrinthe[i][j] == dodo || labyrinthe[i][j] == repas){ //verifie si la case represente un point d'eau, de repas ou de dodo 
				stock[i][j] = rand () %451 + 50; //on genre un stock compris entre 50 et 500 ressources que l'on stocke dans la matrice stock associe au labyrinthe
			}
		}
	}
}