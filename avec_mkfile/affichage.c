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

 void affiche_entrer(int tmp){
 	int i = 0;
 	for (i = 0; i < tmp; i++){
 		printf("\n");
 	}
 }
