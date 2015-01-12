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
*\fn void gen_stock_fourmi(int id_fourmi)
*\brief Fonction permettant de definir une quantite de nourriture, d'eau, de dodo que possède Zozor
*\param int id_fourmi est l'identifiant de Zozor
*/


void gen_stock_fourmi(int id_fourmi)
{
	population[id_fourmi].eau = 40;
	population[id_fourmi].repas = 30;
	population[id_fourmi].dodo = 20;
}

 /*fonction qui permet de creer un stock aleatoire pour chaque point important*/
void gen_stock (void)
{
	int i = 0, j = 0;
	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++){
			if (labyrinthe[i][j] == eau || labyrinthe[i][j] == dodo || labyrinthe[i][j] == manger){ //verifie si la case represente un point d'eau, de manger ou de dodo
				stock[i][j] = rand () %451 + 50; //on genre un stock compris entre 50 et 500 ressources que l'on stocke dans la matrice stock associe au labyrinthe
			}
		}
	}
}

