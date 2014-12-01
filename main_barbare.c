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
 
 //definition de la matrice labyrinthe representant la table de jeu dans laquelle est stocke les fourmis et les murs de type t_case
 t_case labyrinthe[N][N];
 
 //definition de la matrice emplacement permettant de connaitre ce que contient une case du labyrinthe de type t_case
 //contient murs, bases, eau, dodo, repas
 t_case emplacement[N][N];
 
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


/*A AJOUTER AU MAKEFILE */
/*fonction permettant le deplacement des fourmis dans le labyrinthe de facon aleatoire, renvoi 0 si l'utilisateur veut quiter */
int mv_fourmi(int a_deplacer){
 	int choix = 0, x = 0, y = 0, ok = 0; //ok permet de savoir si le deplacement peut se faire
 	//on recupere les coordonnees en x et y de la fourmi dont les deplacements sont a verifier
 	
 	
 	//LES MURS SE DECALENT AVEC LA FOURMI 
 	x = population[a_deplacer].x;
 	y = population[a_deplacer].y;
 	while (ok == 0){ 
 		printf("\nChoisissez une direction: \n 1-- Gauche\n 2-- Droite\n 3-- Haut\n 4-- Bas\n 5-- Quitter\n Votre choix: ");
 		scanf("%i", &choix);	
 		switch (choix){
 			case 1: if (population[a_deplacer].y - 1 >= 0 && emplacement[x][y-1] != mur) ok = 1; break;
 			
 			case 2: if (population[a_deplacer].y + 1 <= 11 && emplacement[x][y+1] != mur) ok = 1; break;
 			
 			case 3: if (population[a_deplacer].x + 1 <= 11 && emplacement[x+1][y] != mur) ok = 1; break;
 			
 			case 4: if (population[a_deplacer].x - 1 >= 0 && emplacement[x-1][y] != mur) ok = 1; break;
 			
 			case 5: return 0; break;
 		}
 		
		if (ok == 0){
			printf("\nLa fourmi ne peut satisfaire votre demande de deplacement, veuillez entrez une nouvelle direction:\n");
		}
	}
	
	labyrinthe[population[a_deplacer].x][population[a_deplacer].y] = vide;
	
	switch (choix){
		case 1 : population[a_deplacer].y = population[a_deplacer].y-1; break;
		
		case 2 : population[a_deplacer].y = population[a_deplacer].y+1; break;
		
		case 3 : population[a_deplacer].x = population[a_deplacer].x-1; break;
		
		case 4 : population[a_deplacer].x = population[a_deplacer].x+1; break;
	}	
	
	labyrinthe[population[a_deplacer].x][population[a_deplacer].y] = fourmi;
	return 1;
}

 /* A AJOUTER AU MAKEFILE*/
/*fonction permettant le pop des fourmis*/
void gen_fourmi(void){
	int x = 0, y = 0, i = 0, tmp = 0, fin_prog = 1; //fin_prog permet de savoir si le programme doit se poursuivre
	recherche_base(&x, &y);
	printf("Entrez le nombre de fourmi que vous voudriez voir apparaitre sur le labyrinthe (entre 1 et 3): ");
	tmp = verif_saisie(1,3);
	for (i = 0; i < tmp; i++){
		while (fin_prog == 1){
			labyrinthe[x][y] = fourmi;
			affiche_lab();
			population[nb_fourmi].matricule = nb_fourmi;
			population[nb_fourmi].x = x;
			population[nb_fourmi].y = y;
			fin_prog = mv_fourmi(population[nb_fourmi].matricule);
			/*affiche_lab();
			mv_fourmi(population[nb_fourmi].matricule);
			affiche_lab();
			mv_fourmi(population[nb_fourmi].matricule);
			affiche_lab();
			mv_fourmi(population[nb_fourmi].matricule);
			affiche_lab();
			mv_fourmi(population[nb_fourmi].matricule);
			affiche_lab();
			mv_fourmi(population[nb_fourmi].matricule);
			affiche_lab();
			mv_fourmi(population[nb_fourmi].matricule);
			affiche_lab();
			mv_fourmi(population[nb_fourmi].matricule);
			affiche_lab();*/
			nb_fourmi++;
		}
	}	
}

int main (void){
	affiche_entrer(50);
	init_labyrinthe();
	vide_stock();
	gen_labyrinthe();
	gen_points();
	gen_stock();
	affiche_lab();
	gen_fourmi(); /*A AJOUTER AU MAKEFILE*/
	/*affiche_lab();
	mv_fourmi(population[nb_fourmi].matricule);
	affiche_lab();
	mv_fourmi(population[nb_fourmi].matricule);
	affiche_lab();*/
	
	return EXIT_SUCCESS;
}
