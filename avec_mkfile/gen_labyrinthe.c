/* Page contenant les fonctions relatives a la creation du labyrinthe, et la mise en place des points strategiques */

#include "header.h"


/* fonction de genration du labyrinthe*/
void gen_labyrinthe(t_case labyrinthe[N][N]){
	//declaration des variables necessaire au traitement
	FILE* fic_mur = fopen("init_mur_lab.txt", "r"); // permet la recuperation des murs du labyrinthe
	FILE* fic_base = fopen("init_base_lab.txt", "r"); //permet de recuperer la base de pop des fourmis
	int i = 0, j = 0;
	//recuperation des murs du labyrinthe avec une boucle do while
	do {
	fscanf(fic_mur, "%i", &i);
	fscanf(fic_mur, "%i", &j);
	labyrinthe[i][j] = mur;
	} while (!feof(fic_mur));
	//recupeartion de la base des fourmis 
	do {
	fscanf(fic_base, "%i", &i);
	fscanf(fic_base, "%i", &j);
	labyrinthe[i][j] = base;
	} while (!feof(fic_base));
	//fermeture des fichiers 
	fclose(fic_mur);
	fclose(fic_base);
}


/*fonction de genration des differents points d'eau dans le labyrinthe */
void gen_points_eau (t_case labyrinthe[N][N], int nb_eau){
	int i = 0, j =0; /*declaration des variables permettant de stocker les coordonnees d'un point d'eau*/
	int compteur = 0;
	for (compteur = 0; compteur < nb_eau; compteur ++){
		i = rand () % 12;
		j = rand () % 12;
		if (labyrinthe[i][j] != vide){
			while (labyrinthe[i][j] != vide){
				i = rand () % 12;
				j = rand () % 12;
			}
		}
		labyrinthe[i][j] = eau;
	}
}

/*fonction de genration des differents points de repas dans le labyrinthe */
void gen_points_repas(t_case labyrinthe[N][N], int nb_repas){
	int i = 0, j =0; /*declaration des variables permettant de stocker les coordonnees d'un point de repas*/
	int compteur = 0;
	for (compteur = 0; compteur < nb_repas; compteur ++){
		i = rand () % 12;
		j = rand () % 12;
		if (labyrinthe[i][j] != vide){
			while (labyrinthe[i][j] != vide){
				i = rand () % 12;
				j = rand () % 12;
			}
		}
		labyrinthe[i][j] = repas;
	}
}


/*fonction de genration des differents points de dodo dans le labyrinthe */
void gen_points_dodo (t_case labyrinthe[N][N], int nb_dodo){
	int i = 0, j =0; /*declaration des variables permettant de stocker les coordonnees d'un point de dodo*/
	int compteur = 0;
	for (compteur = 0; compteur < nb_dodo; compteur ++){
		i = rand () % 12;
		j = rand () % 12;
		if (labyrinthe[i][j] != vide){
			while (labyrinthe[i][j] != vide){
				i = rand () % 12;
				j = rand () % 12;
			}
		}
		labyrinthe[i][j] = dodo;
	}
}


/* fonction de genration aleatoire des differents points utiles */
void gen_points (t_case labyrinthe[N][N]){
	int nb_repas = 0, nb_dodo = 0, nb_eau = 0;
	printf("Passons maintenant a la genration des differents points utiles comme les dortoirs, les points d'eaux, les pique-niques\n\n");
	printf("\nSaisissez le nombre de point d'eau que vous voudriez voir apparaitre sur le labyrinthe (entre 2 et 7): ");
	scanf("%i", &nb_eau);
	printf("Saisissez le nombre de pique-niques que vous voudriez voir apparaitre sur le labyrinthe (entre 3 et 8): ");
	scanf("%i",&nb_repas);
	printf("Saisissez le nombre de dortoir que vous voudriez voir apparaitre sur le labyrinthe (entre 1 et 5): ");
	scanf("%i",&nb_dodo);
	gen_points_eau(labyrinthe, nb_eau);
	gen_points_dodo(labyrinthe, nb_dodo);
	gen_points_repas(labyrinthe, nb_repas);
}