/**
* \file stock.c
* \brief Définition des fonctions permettant de gerer les stocks de chaques points, de la création au retrait
* \author Jean-baptiste Dubois, Provost Valentin, Dezere Florian
* \version 1.0
* \date 6 Janvier 2014
*
*/



#include "header.h"

/**
*\fn void gen_stock(void)
*\brief Fonction permettant de definir une quantite aléatoire de repas, d'eau ou de sommeil sur chaque point correspondant
*/

void gen_stock (void){
	int i = 0, j = 0; 
	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++){
			if (emplacement[i][j] == eau || emplacement[i][j] == dodo || emplacement[i][j] == manger){ //verifie si la case represente un point d'eau, de manger ou de dodo 
				stock[i][j] = rand () %451 + 50; //on genre un stock compris entre 50 et 500 ressources que l'on stocke dans la matrice stock associe au labyrinthe
			}
		}
	}
}
