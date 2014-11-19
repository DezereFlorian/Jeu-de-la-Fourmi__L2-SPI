 // definition des bibliotheques a inclure pour le bon fonctionnement du programme
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h> //importation necessaire pour la fonction rand 

 //definition des variables globales
 #define N 12 // taille du labyrinthe en largeur et longueur
 
 // definition d'une énumération de type t_case pour la création des differentes cases du labyrinthe
 typedef enum {vide, mur, base, eau, dodo, manger} t_case; // vide correspond a une case vide, mur a un mur, eau dodo et manger à differents point importants
 
 //definition de la matrice labyrinthe representant la table de jeu de type t_case
 t_case labyrinthe[N][N];
 
 //definition de la matrice stock contenant les stocks des points utiles du jeu de type int
 int stock[N][N];
 
  /* fonction d'initialisation de la matrice du labyrinthe a vide*/
 void init_labyrinthe(t_case labyrinthe[N][N]){
	int i = 0, j = 0;
	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++){
			labyrinthe[i][j] = vide;
		}
	}
 }
 
 
 /*fonction de mise a zero de la matrice contenant le stock disponible de chaque point important*/ 
 void vide_stock(int stock[N][N]){
	int i = 0, j = 0;
	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++){
			stock[i][j] = 0;
		}
	}
 }
 
 /*fonction qui permet de creer un stock aleatoire pour chaque point important*/
void gen_stock (t_case labyrinthe[N][N], int stock[N][N]){
	int i = 0, j = 0; 
	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++){
			if (labyrinthe[i][j] == eau || labyrinthe[i][j] == dodo || labyrinthe[i][j] == manger){ //verifie si la case represente un point d'eau, de manger ou de dodo 
				stock[i][j] = rand () %451 + 50; //on genre un stock compris entre 50 et 500 ressources que l'on stocke dans la matrice stock associe au labyrinthe
			}
		}
	}
}

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
		do{
			i = rand () % 12;
			j = rand() % 12;
		}
		while(labyrinthe[i][j] != vide);
		labyrinthe[i][j] = eau;
	}
}


/*fonction de genration des differents points de manger dans le labyrinthe */
void gen_points_manger(t_case labyrinthe[N][N], int nb_manger){
	int i = 0, j =0; /*declaration des variables permettant de stocker les coordonnees d'un point de manger*/
	int compteur = 0;
	for (compteur = 0; compteur < nb_manger; compteur ++){
		i = rand () % 12;
		j = rand () % 12;
		if (labyrinthe[i][j] != vide){
			while (labyrinthe[i][j] != vide){
				i = rand () % 12;
				j = rand () % 12;
			}
		}
		labyrinthe[i][j] = manger;
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
	int nb_manger = 0, nb_dodo = 0, nb_eau = 0;
	printf("Passons maintenant a la genration des differents points utiles comme les dortoirs, les points d'eaux, les pique-niques");
	printf("\n\nSaisissez le nombre de point d'eau que vous voudriez voir apparaitre sur le labyrinthe (entre 2 et 7): ");
	scanf("%i", &nb_eau);
	printf("Saisissez le nombre de pique-niques que vous voudriez voir apparaitre sur le labyrinthe (entre 3 et 8): ");
	scanf("%i",&nb_manger);
	printf("Saisissez le nombre de dortoir que vous voudriez voir apparaitre sur le labyrinthe (entre 1 et 5): ");
	scanf("%i",&nb_dodo);
	gen_points_eau(labyrinthe, nb_eau);
	gen_points_dodo(labyrinthe, nb_dodo);
	gen_points_manger(labyrinthe, nb_manger);
}

/*fonction d'affichage du labyrinthe */
void affiche_lab(t_case labyrinthe[N][N]){
	int i = 0, j = 0;
	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++){
			switch(labyrinthe[i][j]){
				case mur:
					printf("U");
					break;
				case base:
					printf("*");
					break;
				case eau:
					printf("o");
					break;
				case manger:
					printf("R");
					break;
				case dodo:
					printf("D");
					break;
				case vide:
					printf(" ");
					break;
			}
		}
		printf("\n");
	}
}
/* il faut absolument modifier cette affichage pourri et trouver un truc qui claque !!! */

int main (void){
	init_labyrinthe(labyrinthe);
	vide_stock(stock);
	gen_labyrinthe(labyrinthe);
	gen_points(labyrinthe);
	gen_stock(labyrinthe, stock);
	affiche_lab(labyrinthe);
	return EXIT_SUCCESS;
}
