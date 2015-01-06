/*definition des fonctions permettant de gerer les stocks de chaques points, de la cration au retrait */

#include "header.h"


/*fonction permettant de definir une quantite de nourriture, d'eau, de dodo que possede la fourmi */
void gen_stock_fourmi(int id_fourmi){
	population[id_fourmi].eau = 40;
	population[id_fourmi].repas = 30;
	population[id_fourmi].dodo = 20;
}
