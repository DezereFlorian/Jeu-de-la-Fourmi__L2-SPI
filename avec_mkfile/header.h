/* Header contenant les definition des fonctions necessaire au main.c 
 */
 
	  // definition des bibliotheques a inclure pour le bon fonctionnement du programme
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h> //importation necessaire pour la fonction rand 

 //definition des variables globales
 #define N 12 // taille du labyrinthe en largeur et longueur
 #define Z 50 // taille du tableau de populaton, soit un maximum de 50 fourmi dans le tableau A AJOUTER

// structure necessaire a la connaissance d'une fourmi, avec sa place en x, y et son numero d'immatriculation
typedef struct {int matricule; int x; int y; int eau; int dodo; int repas; int total_mv;} t_fourmi;//matricule represente le numero de la fourmi, x et y sa position dans le labyrinthe, eau, dodo, repas la quantite d'eau de repas et de dodo que la fourmi possede, total_mv le nombre total de deplacement de la fourmi

// tableau de structure permettant de connaitre toutes les fourmis
t_fourmi population[Z];
 
 // definition d'une énumération de type t_case pour la création des differentes cases du labyrinthe
 typedef enum {vide, mur, base, eau, dodo, manger, fourmi, troll_case} t_case; // vide correspond a une case vide, mur a un mur, eau dodo et manger à differents point importants, ainsi que la fourmi
 
 //definition de la matrice labyrinthe representant la table de jeu dans laquelle est stocke les fourmis
 t_case labyrinthe[N][N];
 
 //definition de la matrice emplacement permettant de connaitre ce que contient une case du labyrinthe de type t_case
 //contient murs, bases, eau, dodo, repas
 t_case emplacement[N][N];
 
 //definition de la matrice stock contenant les stocks des points utiles du jeu de type int
 int stock[N][N];

/*
//definition du nombre de fourmi reellement presente dans le labyrinthe 
int nb_fourmi = 0;*/

 //declaration de toutes les fonctions du programmes
 void init_labyrinthe(void);
 void vide_stock(void);
 void gen_labyrinthe(void);
 void affiche_lab(void);
 void gen_points_eau (int nb_eau);
 void gen_points_repas (int nb_repas);
 void gen_points_dodo (int nb_dodo);
 void gen_points (void);
 void gen_stock (void);
 void gen_fourmi(void);
 void gen_stock_fourmi(int id_fourmi);
 void mv_fourmi(int id_fourmi);
 int end_game(void);
 int verif_deplacement(int id_fourmi);
 void etat_fourmi(int id_fourmi);
 void gen_troll_case (void);
 void recherche_base(int *x, int *y);
 int verif_saisie (int petit, int grand);
 void affiche_entrer(int tmp);
 void aleatoire (void);
