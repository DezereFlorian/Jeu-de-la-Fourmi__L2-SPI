/**
* \file fourmi.c
* \brief Page contenant les fonctions relatives a la de la fourmi et de tout ce qui y touche
* \author Jean-baptiste Dubois, Provost Valentin, Dezere Florian
* \version 1.0
* \date 6 Janvier 2014
*
*/


#include "header.h"

/**
*\fn void gen_fourmi(void)
*\brief Fonction permettant le pop des fourmis
*/


void gen_fourmi(void){
	int x = 0, y = 0, i = 0, tmp = 0; //fin_prog permet de savoir si le programme doit se poursuivre
	recherche_base(&x, &y);
	printf("Entrez le nombre de fourmi que vous voudriez voir apparaitre sur le labyrinthe en plus de celle que vous controlerez (entre 1 et 3): ");
	int nb_fourmi;
	//tmp = verif_saisie(1,3);
	for (i = 0; i < tmp; i++)
    {
			labyrinthe[x][y] = fourmi;
			population[nb_fourmi].matricule = nb_fourmi;
			population[nb_fourmi].x = x;
			population[nb_fourmi].y = y;
			population[nb_fourmi].total_mv = 0;
			gen_stock_fourmi(population[nb_fourmi].matricule);
			mv_fourmi(population[nb_fourmi].matricule);
			nb_fourmi++;
	}
}




/**
*\fn void etat_fourmi(int id_fourmi)
*\brief Fonction permettant d'afficher l'etat de Zozor, sa quantite de repas, d'eau et de sommeil disponible
*\param int id_fourmi est l'identifiant de Zozor
*/

void etat_fourmi(int id_fourmi){
	printf("La fourmi numero %i possede %i quantite d'eau, %i quantite de repas et %i quantite de sommeil.",id_fourmi, population[id_fourmi].eau, population[id_fourmi].repas, population[id_fourmi].dodo);
	affiche_entrer(1);
	if (population[id_fourmi].eau <= 15){
		printf("Pensez serieusement a vous diriger vers un point d'eau pour recharger votre stock d'eau.");
	}

	if (population[id_fourmi].repas <= 20){
		printf("Pensez serieusement a vous diriger vers un point de repas pour recharger votre stock de repas.");
	}

	if (population[id_fourmi].dodo <= 5){
		printf("Pensez serieusement a vous diriger vers un point de sommeil pour recharger votre stock de sommeil.");
	}
}


/**
*\fn  void recherche_base(int *x, int *y)
*\brief Fonction permettant la recherche de la base du labyrinthe pour le pop de Zozor
*\param int *x, int *y  sont des pointeurs qui permettent de récuperer les valeurs pour la base
*/

 void recherche_base(int *x, int *y){
 	int i = 0, j = 0;
	for (i = 0; i < N; i++){
		for (j = 0; j < N; j ++){
			if (emplacement[i][j] == base){
				*x = i;
				*y = j;
			}
		}
	}
 }
