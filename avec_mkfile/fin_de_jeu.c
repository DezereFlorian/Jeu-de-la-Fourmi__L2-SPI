/* Page contenant la fin de jeu */

#include "header.h"

/* fonction permettant de savoir si la troll case met fin a la partie */
int end_game(void){
	int sortie = 0;
	return sortie = rand() %6 + 1;
}

/*fonction permettant la generation de la troll case, qui peut mettre fin a la partie*/
void gen_troll_case (void){
	int j = 0, i = 0;
	
	do{
		i = rand() % 12;
		j = rand() % 12;
	}
	while(emplacement[i][j] != vide);
	emplacement[i][j] = troll_case;
}
