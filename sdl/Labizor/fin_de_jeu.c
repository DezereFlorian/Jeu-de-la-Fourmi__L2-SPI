/**
* \file fin_de_jeu.c
* \brief Page contenant la fin de jeu
* \author Jean-baptiste Dubois, Provost Valentin, Dezere Florian
* \version 1.0
* \date 6 Janvier 2014
*
*/



#include "header.h"

/**
*\fn int end_game(void)
*\brief Fonction permettant de savoir si la troll case met fin a la partie
*/


int end_game(void){
	int sortie = 0;
	return sortie = rand() %6 + 1;
}


/**
*\fn void gen_troll_case (void)
*\brief Fonction permettant la generation de la troll case, qui peut mettre fin a la partie
*/


void gen_troll_case (void){
	int j = 0, i = 0;

	do{
		i = rand() % N;
		j = rand() % N;
	}
	while(labyrinthe[i][j] != vide);
	labyrinthe[i][j] = troll_case;
}
