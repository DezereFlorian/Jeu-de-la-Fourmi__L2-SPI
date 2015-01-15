/**
* \file header.h
* \brief Header contenant les definition des fonctions necessaire au main.c
* \author Jean-baptiste Dubois, Provost Valentin, Dezere Florian
* \version 1.0
* \date 6 Janvier 2014
*
*/



	  // definition des bibliotheques a inclure pour le bon fonctionnement du programme
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h> //importation necessaire pour la fonction rand
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

 //definition des variables globales
 #define N 13 // taille du labyrinthe en largeur et longueur
 #define Z 50 // taille du tableau de populaton, soit un maximum de 50 fourmi dans le tableau A AJOUTER
 #define Taille_Bloc 52 //Taille d'un bloc carré en px
 #define nbEau 4
 #define nbManger 5
 #define nbDodo 2

/**
* \struct t_fourmi
* \brief structure necessaire a la connaissance de Zozor, avec sa place en x, y et son numero d'immatriculation
*/

// structure necessaire a la connaissance d'une fourmi, avec sa place en x, y et son numero d'immatriculation
typedef struct {int matricule; int x; int y; int eau; int dodo; int repas; int total_mv;} t_fourmi;//matricule represente le numero de la fourmi, x et y sa position dans le labyrinthe, eau, dodo, repas la quantite d'eau de repas et de dodo que la fourmi possede, total_mv le nombre total de deplacement de la fourmi

// tableau de structure permettant de connaitre toutes les Zozor
t_fourmi population[Z];

/**
* \enum t_case
* \brief definition d'une énumération de type t_case pour la création des differentes cases du labyrinthe
*/

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
void gen_labyrinthe(SDL_Surface *ecran, SDL_Surface *imageDeFond,SDL_Rect positionFond);
 void affiche_lab(void);
 void gen_points_eau (SDL_Surface *ecran, SDL_Surface *imageDeFond,SDL_Rect positionFond);
 void gen_points_repas (SDL_Surface *ecran, SDL_Surface *imageDeFond,SDL_Rect positionFond);
 void gen_points_dodo (SDL_Surface *ecran, SDL_Surface *imageDeFond,SDL_Rect positionFond);
 void gen_points (SDL_Surface *ecran, SDL_Surface *imageDeFond,SDL_Rect positionFond);
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
  void afficher_entrer(int tmp);
 void aleatoire (void);
void positionner_element(SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Surface *element_SDL, SDL_Rect positionFond, int x, int y);
void deplacement_fourmi(SDL_Surface *ecran, SDL_Surface *fourmi_SDL, SDL_Surface *imageDeFond,SDL_Rect positionFond, SDL_Rect positionFourmi);
SDL_Rect getBasePos(void);
void afficher_labyrinthe(SDL_Surface *ecran, SDL_Surface *imageDeFond, SDL_Rect positionFond);
void troll_case_SDL(SDL_Surface *ecran, SDL_Surface *imageDeFond,SDL_Rect positionFond);
int verif_mur_fourmi_troll_case(int x, int y, SDL_Surface *ecran, SDL_Surface *imageDeFond,SDL_Rect positionFond);
