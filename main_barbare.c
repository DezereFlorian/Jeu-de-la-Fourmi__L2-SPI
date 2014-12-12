 // definition des bibliotheques a inclure pour le bon fonctionnement du programme
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h> //importation necessaire pour la fonction rand 

 //definition des variables globales
 #define N 12 // taille du labyrinthe en largeur et longueur
 #define Z 50 // taille du tableau de populaton, soit un maximum de 50 fourmi dans le tableau A AJOUTER

/* A AJOUTER AU MAKEFILE*/
// structure necessaire a la connaissance d'une fourmi, avec sa place en x, y et son numero d'immatriculation
typedef struct {int matricule; int x; int y; int eau; int dodo; int repas; int total_mv;} t_fourmi;//matricule represente le numero de la fourmi, x et y sa position dans le labyrinthe, eau, dodo, repas la quantite d'eau de repas et de dodo que la fourmi possede, total_mv le nombre total de deplacement de la fourmi, GERER TOTAL_MOUV

/* A AJOUTER AU MAKEFILE*/
// tableau de structure permettant de connaitre toutes les fourmis
t_fourmi population[Z];
 
 // definition d'une énumération de type t_case pour la création des differentes cases du labyrinthe
 typedef enum {vide, mur, base, eau, dodo, manger, fourmi} t_case; // vide correspond a une case vide, mur a un mur, eau dodo et manger à differents point importants, ainsi que la fourmi
 
 //definition de la matrice labyrinthe representant la table de jeu dans laquelle est stocke les fourmis et les murs de type t_case
 t_case labyrinthe[N][N];
 
 //definition de la matrice emplacement permettant de connaitre ce que contient une case du labyrinthe de type t_case
 //contient murs, bases, eau, dodo, repas
 t_case emplacement[N][N];
 
 //definition de la matrice stock contenant les stocks des points utiles du jeu de type int
 int stock[N][N];

//definition du nombre de fourmi reellement presente dans le labyrinthe 
int nb_fourmi = 0;
 
 //FOURMI DE MATRICULE 0 EST LA FOURMI DU JOUEUR
 
 /*A AJOUTER AU MAKEFILE */
 /* fonction permettant l'affichage d'un certain nombre de ligne vide */
 void affiche_entrer(int tmp){
 	int i = 0;
 	for (i = 0; i < tmp; i++){
 		printf("\n");
 	}
 }
 
  /* fonction d'initialisation de la matrice du labyrinthe a vide*/
 void init_labyrinthe(void){
	int i = 0, j = 0;
	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++){
			labyrinthe[i][j] = vide;
			emplacement[i][j] = vide;
		}
	}
 }
 
 
 /*fonction de mise a zero de la matrice contenant le stock disponible de chaque point important*/ 
 void vide_stock(void){
	int i = 0, j = 0;
	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++){
			stock[i][j] = 0;
		}
	}
 }
 
 /*A AJOUTER AU MAKEFILE */
 /*fonction permettant de verifier si la saisie de l'utilisateur est correcte*/
 int verif_saisie (int petit, int grand){
 	int output = 0;
 	scanf("%i", &output);
 	while (output < petit || output > grand){
 		printf("Entrez une valeur correcte, qui soit comprise entre %i et %i : ",petit, grand);
 		scanf("%i",&output);
 	}
 	return output;
 }
 
 /* A AJOUTER AU MAKEFILE*/
 /*fonction permettant la recherche de la base du labyrinthe pour le pop des fourmis*/
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
 
 /*fonction qui permet de creer un stock aleatoire pour chaque point important*/
void gen_stock (void){
	int i = 0, j = 0; 
	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++){
			if (emplacement[i][j] == eau || emplacement[i][j] == dodo || emplacement[i][j] == manger){ //verifie si la case represente un point d'eau, de manger ou de dodo 
				stock[i][j] = rand () %451 + 50; //on genre un stock compris entre 50 et 500 ressources que l'on stocke dans la matrice stock associe au labyrinthe
			}
		}
	}
}

/* fonction de genration du labyrinthe*/
void gen_labyrinthe(void){
	//declaration des variables necessaire au traitement
	FILE* fic_mur = fopen("init_mur_lab.txt", "r"); // permet la recuperation des murs du labyrinthe
	FILE* fic_base = fopen("init_base_lab.txt", "r"); //permet de recuperer la base de pop des fourmis
	int i = 0, j = 0;
	//recuperation des murs du labyrinthe avec une boucle do while
	do {
		fscanf(fic_mur, "%i", &i);
		fscanf(fic_mur, "%i", &j);
		emplacement[i][j] = mur;
	} while (!feof(fic_mur));
	//recupeartion de la base des fourmis 
	do {
		fscanf(fic_base, "%i", &i);
		fscanf(fic_base, "%i", &j);
		emplacement[i][j] = base;
	} while (!feof(fic_base));
	//fermeture des fichiers 
	fclose(fic_mur);
	fclose(fic_base);
}


/*fonction de genration des differents points d'eau dans le labyrinthe */
void gen_points_eau (int nb_eau){
	int i = 0, j =0; /*declaration des variables permettant de stocker les coordonnees d'un point d'eau*/
	int compteur = 0;
	for (compteur = 0; compteur < nb_eau; compteur ++){
		do{
			i = rand () % 12;
			j = rand() % 12;
		}
		while(emplacement[i][j] != vide);
		emplacement[i][j] = eau;
	}
}


/*fonction de genration des differents points de manger dans le labyrinthe */
void gen_points_manger(int nb_manger){
	int i = 0, j =0; /*declaration des variables permettant de stocker les coordonnees d'un point de manger*/
	int compteur = 0;
	for (compteur = 0; compteur < nb_manger; compteur ++){
		do{
			i = rand () % 12;
			j = rand() % 12;
		}
		while(emplacement[i][j] != vide);
		emplacement[i][j] = manger;
	}
}


/*fonction de genration des differents points de dodo dans le labyrinthe */
void gen_points_dodo (int nb_dodo){
	int i = 0, j =0; /*declaration des variables permettant de stocker les coordonnees d'un point de dodo*/
	int compteur = 0;
	for (compteur = 0; compteur < nb_dodo; compteur ++){
		do{
			i = rand () % 12;
			j = rand() % 12;
		}
		while(emplacement[i][j] != vide);
		emplacement[i][j] = dodo;
	}
}


/* fonction de genration aleatoire des differents points utiles */
void gen_points (void){
	int nb_manger = 0, nb_dodo = 0, nb_eau = 0;
	printf("Passons maintenant a la genration des differents points utiles comme les dortoirs, les points d'eaux, les pique-niques");
	printf("\n\nSaisissez le nombre de eau que vous voudriez voir apparaitre sur le labyrinthe (entre 2 et 7): ");
	nb_eau=verif_saisie(2,7);
	printf("Saisissez le nombre de pique-niques que vous voudriez voir apparaitre sur le labyrinthe (entre 3 et 8): ");
	nb_manger=verif_saisie(3,8);
	printf("Saisissez le nombre de dortoir que vous voudriez voir apparaitre sur le labyrinthe (entre 1 et 5): ");
	nb_dodo=verif_saisie(1,5);
	gen_points_eau(nb_eau);
	gen_points_dodo(nb_dodo);
	gen_points_manger(nb_manger);
}

/*fonction d'affichage du labyrinthe */
void affiche_lab(void){
	int i = 0, j = 0;
	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++){
			switch(emplacement[i][j]){
				case mur:
					printf("&");
					break;
				/*case base:
					printf("*");
					break;*/
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
			if (labyrinthe[i][j] == fourmi){
				printf("x");
			}
		}
		affiche_entrer(1);
	}
	affiche_entrer(2);
}

/*fonction permettant d'afficher l'etat d'une fourmi, sa quantite de repas, d'eau et de sommeil disponible*/
void etat_fourmi(int id_fourmi){
	printf("La fourmi numero %i possede %i quantite d'eau, %i quantite de repas et %i quantite de sommeil",id_fourmi, population[id_fourmi].eau, population[id_fourmi].repas, population[id_fourmi].dodo);
	
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

/*A AJOUTER AU MAKEFILE */
/*fonction permettant le deplacement des fourmis dans le labyrinthe de facon aleatoire */
void mv_fourmi(int id_fourmi){
 	int choix = 0, x = 0, y = 0, ok = 0, fin_fct = 0; //ok permet de savoir si le deplacement peut se faire, fin_fct permet de savoir si le programme doit continuer, cpt_tour represente le nombre max de tour que peux jouer la fourmi
 	//on recupere les coordonnees en x et y de la fourmi dont les deplacements sont a verifier
 	
 	
 	//LES MURS SE DECALENT AVEC LA FOURMI 
 	x = population[id_fourmi].x;
 	y = population[id_fourmi].y;
 	while (fin_fct < 5){
	 	while (ok == 0 && fin_fct < 5){ 
	 		affiche_lab();
	 		etat_fourmi(id_fourmi);
	 		printf("\nChoisissez la direction vers laquelle la fourmi doit aller: \n 1-- Gauche\n 2-- Droite\n 3-- Haut\n 4-- Bas\n 5-- Ne pas bouger\n Votre choix: ");
	 		scanf("%i", &choix);
	 		
	 		switch (choix){
	 			case 1: if (population[id_fourmi].y - 1 >= 0 && emplacement[x][y-1] != mur) ok = 1; break;
	 			
	 			case 2: if (population[id_fourmi].y + 1 <= 11 && emplacement[x][y+1] != mur) ok = 1; break;
	 			
	 			case 3: if (population[id_fourmi].x + 1 <= 11 && emplacement[x+1][y] != mur) ok = 1; break;
	 			
	 			case 4: if (population[id_fourmi].x - 1 >= 0 && emplacement[x-1][y] != mur) ok = 1; break;
	 			
	 			case 5: fin_fct = 5; break;
	 		}
	 		if (fin_fct < 5 && ok == 1){
	 		
	 			labyrinthe[population[id_fourmi].x][population[id_fourmi].y] = vide;
	 			
	 			switch (choix){
					case 1 : population[id_fourmi].y = population[id_fourmi].y-1; break;
		
					case 2 : population[id_fourmi].y = population[id_fourmi].y+1; break;
		
					case 3 : population[id_fourmi].x = population[id_fourmi].x-1; break;
		
					case 4 : population[id_fourmi].x = population[id_fourmi].x+1; break;
				}
				
				labyrinthe[population[id_fourmi].x][population[id_fourmi].y] = fourmi;
				
				population[id_fourmi].total_mv = population[id_fourmi].total_mv + 1;
	 		}
	 		
			if (ok == 0 && fin_fct < 5){
				printf("\nLa fourmi ne peut satisfaire votre demande de deplacement, veuillez entrez une nouvelle direction:\n");
			}
			fin_fct++;
		}
		ok = 0;
	}
}

/*fonction permettant de definir une quantite de nourriture, d'eau, de dodo que possede la fourmi */
void gen_stock_fourmi(int id_fourmi){
	population[id_fourmi].eau = 40;
	population[id_fourmi].repas = 60;
	population[id_fourmi].dodo = 20;
}

 /* A AJOUTER AU MAKEFILE*/
/*fonction permettant le pop des fourmis par l'utilisateur*/
void gen_fourmi(void){
	int x = 0, y = 0, i = 0, tmp = 0; //fin_prog permet de savoir si le programme doit se poursuivre
	recherche_base(&x, &y);
	printf("Entrez le nombre de fourmi que vous voudriez voir apparaitre sur le labyrinthe en plus de celle que vous controlerez (entre 1 et 3): ");
	tmp = verif_saisie(1,3);
	for (i = 0; i < tmp; i++){
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

int main (void){
	affiche_entrer(50);
	init_labyrinthe();
	vide_stock();
	gen_labyrinthe();
	gen_points();
	gen_stock();
	gen_fourmi();
	
	return EXIT_SUCCESS;
}
