/**
* \file stock.c
* \brief D�finition des fonctions permettant de gerer les stocks de chaques points, de la cr�ation au retrait
* \author Jean-baptiste Dubois, Provost Valentin, Dezere Florian
* \version 1.0
* \date 6 Janvier 2014
*
*/



#include "header.h"

/**
*\fn void gen_stock_fourmi(int id_fourmi)
*\brief Fonction permettant de definir une quantite de nourriture, d'eau, de dodo que poss�de Zozor
*\param int id_fourmi est l'identifiant de Zozor
*/


void gen_stock_fourmi(int id_fourmi){
	population[id_fourmi].eau = 40;
	population[id_fourmi].repas = 30;
	population[id_fourmi].dodo = 20;
}
