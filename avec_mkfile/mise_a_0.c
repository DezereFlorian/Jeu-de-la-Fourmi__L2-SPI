/*definition des fonctions de mise a zero une matrice, ou de mise a l'etat vide */

#include "header.h"

 /* fonction d'initialisation de la matrice du labyrinthe a vide*/
 void init_labyrinthe(void){
	int i = 0, j = 0;
	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++){
			labyrinthe[i][j] = vide;
			emplacement[i][j] = vide;
		}
	}
 }
 
 /*fonction de mise a zero de la matrice contenant le stock disponible de chaque point important*/ 
 void vide_stock(void){
	int i = 0, j = 0;
	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++){
			stock[i][j] = 0;
		}
	}
 }
