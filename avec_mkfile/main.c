/* ---- Simulation de la vie d'un groupe de fourmi dans un labyrinthe ---- 
		Jean-baptiste Dubois, Provost Valentin, 
		Dezere Florian */
		
#include "header.h"


int main (void){
	init_labyrinthe(labyrinthe);
	vide_stock(stock);
	gen_labyrinthe(labyrinthe);
	gen_points(labyrinthe);
	gen_stock(labyrinthe, stock);
	affiche_lab(labyrinthe);
	return EXIT_SUCCESS;
}