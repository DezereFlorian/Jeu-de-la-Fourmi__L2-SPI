/**
* \file mise_a_0.c
* \brief Définition des fonctions de mise a zero d'une matrice, ou de mise a l'état vide
* \author Jean-baptiste Dubois, Provost Valentin, Dezere Florian
* \version 1.0
* \date 6 Janvier 2014
*
*/

/*definition des fonctions de mise a zero une matrice, ou de mise a l'etat vide */

#include "header.h"

/**
*\fn  void init_labyrinthe(void)
*\brief Fonction d'initialisation de la matrice du labyrinthe a vide
*/

SDL_Rect getBasePos(void)
{
    SDL_Rect positionBase;
    int i = 0;
    int j = 0;
    FILE* fic_base = fopen("init_base_lab.txt", "r");
    do
    {
	fscanf(fic_base, "%i", &i);
	fscanf(fic_base, "%i", &j);
	positionBase.x = Taille_Bloc * i + 42;
	positionBase.y = Taille_Bloc * j + 46;
	}
	while (!feof(fic_base));

	//fermeture du fichier
	fclose(fic_base);

	return positionBase;

}


 void init_labyrinthe(void)
 {


	int i = 0, j = 0;
	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++){
			labyrinthe[i][j] = vide;
			emplacement[i][j] = vide;
		}
	}


 }


/**
*\fn  void vide_stock(void
*\brief Fonction de mise a zero de la matrice contenant le stock disponible de chaque point important
*/

 /*fonction de mise a zero de la matrice contenant le stock disponible de chaque point important*/
 void vide_stock(void){
	int i = 0, j = 0;
	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++){
			stock[i][j] = 0;
		}
	}
 }
