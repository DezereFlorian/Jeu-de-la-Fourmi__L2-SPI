/* ---- Simulation de la vie d'un groupe de fourmi dans un labyrinthe ---- 
		Jean-baptiste Dubois, Provost Valentin, 
		Dezere Florian */
		
#include "header.h"


int main (void){
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
