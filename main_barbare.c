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
typedef struct {int matricule; int x; int y;} t_fourmi;//matricule represente le numero de la fourmi, x et y sa position 

/* A AJOUTER AU MAKEFILE*/
// tableau de structure permettant de connaitre toutes les fourmis
t_fourmi population[Z];
 
 // definition d'une énumération de type t_case pour la création des differentes cases du labyrinthe
 typedef enum {vide, mur, base, eau, dodo, manger, fourmi} t_case; // vide correspond a une case vide, mur a un mur, eau dodo et manger à differents point importants, ainsi que la fourmi
 
 /*A AJOUTER AU MAKEFILE*/
 //definition d'une enumeration correspondant a la direction vers laquelle se deplacer
 typedef enum {droite, gauche, haut, bas} t_direction; 
 
 //definition de la matrice labyrinthe representant la table de jeu de type t_case
 t_case labyrinthe[N][N];
 
 //definition de la matrice stock contenant les stocks des points utiles du jeu de type int
 int stock[N][N];

//definition du nombre de fourmi reellement presente dans le labyrinthe 
int nb_fourmi = 0;
 
 
 /*A AJOUTER AU MAKEFILE */
 /* fonction permettant l'affichage d'un certain nombre de ligne vide */
 void affiche_entrer(int tmp){
 	int i = 0;
 	for (i = 0; i < tmp; i++){
 		printf("\n");
 	}
 }
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
 void recherche_base(t_case labyrinthe[N][N], int *x, int *y){
 	int i = 0, j = 0;
	for (i = 0; i < N; i++){
		for (j = 0; j < N; j ++){
			if (labyrinthe[i][j] == base){
				*x = i;
				*y = j;
			}
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
	printf("\n\nSaisissez le nombre de eau que vous voudriez voir apparaitre sur le labyrinthe (entre 2 et 7): ");
	nb_eau=verif_saisie(2,7);
	printf("Saisissez le nombre de pique-niques que vous voudriez voir apparaitre sur le labyrinthe (entre 3 et 8): ");
	nb_manger=verif_saisie(3,8);
	printf("Saisissez le nombre de dortoir que vous voudriez voir apparaitre sur le labyrinthe (entre 1 et 5): ");
	nb_dodo=verif_saisie(1,5);
	gen_points_eau(labyrinthe, nb_eau);
	gen_points_dodo(labyrinthe, nb_dodo);
	gen_points_manger(labyrinthe, nb_manger);
}

/*fonction d'affichage du labyrinthe */
void affiche_lab(t_case labyrinthe[N][N]){
	int i = 0, j = 0;
	t_case tmp;
	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++){
			tmp = labyrinthe[i][j];
			switch(tmp){
				case mur:
					printf("&");
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
				case fourmi:
					printf("x");
					break;
			}
		}
		affiche_entrer(1);
	}
	affiche_entrer(1);
}


/*A AJOUTER AU MAKEFILE */
/*fonction permettant le deplacement des fourmis dans le labyrinthe de facon aleatoire */
void mv_fourmi(t_fourmi population[Z], int a_deplacer){
	t_direction direction;
	labyrinthe[population[a_deplacer].x][population[a_deplacer].y] = base; //traiter en fonction des cas pour que ça devienne base, repas, dodo,eau...	
 	int ok = 0; //ok permet de savoir si le deplacement peut se faire
 	int choix;
 	//on recupere les coordonnees en x et y de la fourmi dont les deplacements sont a verifier
 	//ajouter la verif des murs...*/
 	while (ok == 0){ 
 		printf("\nChoisissez une direction: \n 1-- gauche\n 2--droite\n 3-- haut\n 4--bas\n Votre choix: ");
 		scanf("%i", &choix);	
 		
 		switch (choix){
 			case 1 : if (population[a_deplacer].y - 1 >= 0 ) ok = 1; break;
 			
 			case 2 : if (population[a_deplacer].y + 1 <= 11) ok = 1; break;
 			
 			case 3: if (population[a_deplacer].x + 1 <= 11) ok = 1; break;
 			
 			case 4: if (population[a_deplacer].x - 1 >= 0) ok = 1; break;
 		}
		if (ok == 0){
			printf("\nLa fourmi ne peut satisfaire votre demande de deplacement, veuillez entrez une nouvelle direction:\n");
		}
	}
	
	switch (choix){
		case 1 : population[a_deplacer].y = population[a_deplacer].y-1; break;
		
		case 2 : population[a_deplacer].y = population[a_deplacer].y+1; break;
		
		case 3 : population[a_deplacer].x = population[a_deplacer].x-1; break;
		
		case 4 : population[a_deplacer].x = population[a_deplacer].x+1; break;
	}	
	labyrinthe[population[a_deplacer].x][population[a_deplacer].y] = fourmi;
}

 /* A AJOUTER AU MAKEFILE*/
/*fonction permettant le pop des fourmis*/
void gen_fourmi(t_case labyrinthe[N][N], t_fourmi population[Z]){
	int x = 0, y = 0, tmp = 0;
	//printf("Entrez le nombre de fourmi que vous voudriez voir apparaitre sur le labyrinthe : (entre 3 et 7)\n");
	//scanf("%i", &tmp);
	//while...
	recherche_base(labyrinthe, &x, &y);
	labyrinthe[x][y] = fourmi;
	population[nb_fourmi].matricule = nb_fourmi;
	population[nb_fourmi].x = x;
	population[nb_fourmi].y = y;
	nb_fourmi++;
}

int main (void){
	// modif gen fourmi ajouter boucle?
	affiche_entrer(10);
	init_labyrinthe(labyrinthe);
	vide_stock(stock);
	gen_labyrinthe(labyrinthe);
	gen_points(labyrinthe);
	gen_stock(labyrinthe, stock);
	affiche_lab(labyrinthe);
	gen_fourmi(labyrinthe, population); /*A AJOUTER AU MAKEFILE*/
	affiche_lab(labyrinthe);
	mv_fourmi(population, population[nb_fourmi].matricule);
	affiche_lab(labyrinthe);
	mv_fourmi(population, population[nb_fourmi].matricule);
	affiche_lab(labyrinthe);
	
	return EXIT_SUCCESS;
}
