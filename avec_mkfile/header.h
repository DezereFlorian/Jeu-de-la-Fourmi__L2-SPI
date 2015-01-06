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
 
 // definition d'une énumération de type t_case pour la création des differentes cases du labyrinthe
 typedef enum {vide, mur, base, eau, dodo, repas} t_case; // vide correspond a une case vide, mur a un mur, eau dodo et repas à differents point importants
 
 //definition de la matrice labyrinthe representant la table de jeu de type t_case
 t_case labyrinthe[N][N];
 
 //definition de la matrice stock contenant les stocks des points utiles du jeu de type int
 int stock[N][N];
 
 //declaration de toutes les fonctions du programmes
 void init_labyrinthe(t_case labyrinthe[N][N]);
 void vide_stock(int stock[N][N]);
 void gen_labyrinthe(t_case labyrinthe[N][N]);
 void affiche_lab(t_case labyrinthe[N][N]);
 void gen_points_eau (t_case labyrinthe[N][N], int nb_eau);
 void gen_points_eau (t_case labyrinthe[N][N], int nb_repas);
 void gen_points_eau (t_case labyrinthe[N][N], int nb_dodo);
 void gen_points (t_case labyrinthe[N][N]);
 void gen_stock (t_case labyrinthe[N][N], int stock[N][N]);
 