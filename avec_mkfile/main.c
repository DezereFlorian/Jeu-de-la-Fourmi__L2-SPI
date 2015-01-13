
/**
* \file main.c
* \brief Simulation de la vie d'un groupe de Zozor dans un labyrinthe
* \author Jean-baptiste Dubois, Provost Valentin, Dezere Florian
* \version 1.0
* \date 6 Janvier 2014
*
*/

#include "header.h"


int main (void)
{
	affiche_entrer(50);
	aleatoire();
	init_labyrinthe();
	vide_stock();
	gen_labyrinthe();
	gen_points();
	gen_stock();
	gen_fourmi();

	return EXIT_SUCCESS;
}
