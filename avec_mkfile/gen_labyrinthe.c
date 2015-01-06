/**
* \file gen_labyrinthe.c
* \brief Page contenant les fonctions relatives a la creation du labyrinthe, et la mise en place des points strategiques
* \author Jean-baptiste Dubois, Provost Valentin, Dezere Florian
* \version 1.0
* \date 6 Janvier 2014
*
*/



#include "header.h"

/**
*\fn void init_matrice()
*\brief Fonction permettant de generer aleatoirement un labyrinthe, pas eu le temps de l'ajouter au moteur.c
*/
/* Fonction permettant de generer aleatoirement un labyrinthe, pas eu le temps de l'ajouter au moteur.c
void init_matrice() //initialise la matrice entière, en attribuant tous les murs, en attribuant les coordonnées de ladite case, et en notant ce qu'elle contient. Sans stock pour le moment puisqu'elles sont toutes vides.
{
	int k, l;
	for(k=0;k<N;k++)
	{
		for(l=0;l<N;l++)
		{
			labyrinthe[k][l].i = k;
			labyrinthe[k][l].j = l;
			labyrinthe[k][l].haut = true;
			labyrinthe[k][l].droit = true;
			labyrinthe[k][l].bas = true;
			labyrinthe[k][l].gauche = true;
			labyrinthe[k][l].contenu = vide;
		}
	}
}

void choisir_case() //choisit la première case qui sera utilisée
{
	int x, y;
	x = (rand() % 10);
	y = (rand() % 10);
	cc = labyrinthe[x][y];
}

void afficher()
{
	int k, l;
    for(l=0;l<N;l++)
    {
        printf("+--");
    }
    l=0;
    printf("+\n");
    for(k=0;k<N;k++)
    {
        for(l=0;l<N;l++)
        {
        	if (k==0 && l==0)
        		printf("|");
            if(labyrinthe[k][l].droit) // si mur à droite, alors affichage d'un mur sur la droite
            {
            	printf("  |");
			}
            else{
            	printf("   ");
			}
        }
        printf("\n+");
        for(l=0;l<N;l++)
        {
            if(labyrinthe[k][l].bas) // si mur en bas, alors affichage d'un mur en bas
                printf("--+");
            else
                printf("  +");
        }
        if (k == N-1)
        	printf("\n");
        else
        	printf("\n|");
    }
}

bool verif_voisin() // vérifie pour chaque voisin si celui-ci a tous ses murs, puis les ajoute dans un tableau de voisins vers lesquels casser un mur. Si aucun voisin n'a tous ses murs, renvoie 0
{
	int x = cc.i;
	int y = cc.j;
	if(x+1<N)
	{
		if(labyrinthe[x+1][y].bas && labyrinthe[x+1][y].droit && labyrinthe[x+1][y].haut && labyrinthe[x+1][y].gauche)
		{
			voisins[nb] = labyrinthe[x+1][y];
			nb++;
		}
	}
	if(x-1>-1)
	{
		if(labyrinthe[x-1][y].bas && labyrinthe[x-1][y].droit && labyrinthe[x-1][y].haut && labyrinthe[x-1][y].gauche)
		{
			voisins[nb] = labyrinthe[x-1][y];
			nb++;
		}
	}
	if(y+1<N)
	{
		if(labyrinthe[x][y+1].bas && labyrinthe[x][y+1].droit && labyrinthe[x][y+1].haut && labyrinthe[x][y+1].gauche)
		{
			voisins[nb] = labyrinthe[x][y+1];
			nb++;
		}
	}
	if(y-1>-1)
	{
		if(labyrinthe[x][y-1].bas && labyrinthe[x][y-1].droit && labyrinthe[x][y-1].haut && labyrinthe[x][y-1].gauche)
		{
			voisins[nb] = labyrinthe[x][y-1];
			nb++;
		}
	}
	return (nb>0);
}

void choisir_voisin() // détermine le voisin vers lequel on va, et donc vers qui on va casser le mur
{
	int n;
	n = rand() % nb;
	casetmp = voisins[n];
	nb = 0;
}

void supprimer_mur()
{
	int x1 = cc.i;
	int x2 = casetmp.i;

	int y1 = cc.j;
	int y2 = casetmp.j;

	if(x1>x2) //si le déplacement se fait vers le haut
	{
		cc.haut = false;
		labyrinthe[cc.i][cc.j].haut = false;
		casetmp.bas = false;
		labyrinthe[casetmp.i][casetmp.j].bas = false;
	}
	else if(x2>x1) //si le déplacement se fait vers le bas
	{
		cc.bas = false;
		labyrinthe[cc.i][cc.j].bas = false;
		casetmp.haut = false;
		labyrinthe[casetmp.i][casetmp.j].haut = false;
	}
	if(y1>y2) //si le déplacement se fait vers la gauche
	{
		cc.gauche = false;
		labyrinthe[cc.i][cc.j].gauche = false;
		casetmp.droit = false;
		labyrinthe[casetmp.i][casetmp.j].droit = false;
	}
	else if(y2>y1) //si le déplacement se fait vers la droite
	{
		cc.droit = false;
		labyrinthe[cc.i][cc.j].droit = false;
		casetmp.gauche = false;
		labyrinthe[casetmp.i][casetmp.j].gauche = false;
	}
}

void changer_case() // permet de continuer à "creuser" le labyrinthe
{
	cc = casetmp;
}

void initpile(void)
{
    sommet=-1;
}

void empiler(t_case c)
{
    if (sommet < 120-1)
    {
        sommet++;
        pile[sommet] = c;
    }
}

void depiler(t_case *c)
{
    if(sommet > -1)
    {
        *c = pile[sommet];
        sommet--;
    }
}

int pilevide()
{
    return (sommet== -1);
}

int main(int argc, char *argv[])
{
	srand(time(NULL));

	init_matrice();

	choisir_case();
	// ces deux lignes seront à retirer pour l'affichage en SDL
	afficher();
	printf("\n\n\n___________________________________\n\n\n");

	empiler(cc);

	while(!pilevide()) //tant que la pile n'est pas vide, ça veut dire qu'il reste potentiellement des cases non accessibles
	{
		if(verif_voisin())
		{
			choisir_voisin();
			supprimer_mur();
			changer_case();
			empiler(cc);
			// ces deux lignes seront à retirer pour l'affichage en SDL
			afficher();
			printf("\n\n\n___________________________________\n\n\n");
		}
		else
		{
			depiler(&casetmp);
			depiler(&cc);
			empiler(cc);
		}
	}
	//ligne à retirer ou adapter pour l'affichage en SDL
	afficher();

}*/

/**
*\fn void gen_labyrinthe(void)
*\brief Fonction de generation du labyrinthe
*/

void gen_labyrinthe(void){
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

/**
*\fn void gen_points_eau (int nb_eau)
*\brief Fonction de genration des differents points d'eau dans le labyrinthe
*\param int nb_eau nombre de point d'eau a généré
*/


void gen_points_eau (int nb_eau){
	int i = 0, j =0; /*declaration des variables permettant de stocker les coordonnees d'un point d'eau*/
	int compteur = 0;
	for (compteur = 0; compteur < nb_eau; compteur ++){
		do{
			i = rand() % 12;
			j = rand() % 12;
		}
		while(emplacement[i][j] != vide);
		emplacement[i][j] = eau;
	}
}


/**
*\fn void gen_points_repas(int nb_manger)
*\brief Fonction de generation des differents points de manger dans le labyrinthe
*\param int nb_manger nombre de point pour manger a généré
*/

void gen_points_repas(int nb_manger){
	int i = 0, j =0; /*declaration des variables permettant de stocker les coordonnees d'un point de manger*/
	int compteur = 0;
	for (compteur = 0; compteur < nb_manger; compteur ++){
		do{
			i = rand() % 12;
			j = rand() % 12;
		}
		while(emplacement[i][j] != vide);
		emplacement[i][j] = manger;
	}
}

/**
*\fn void gen_points_dodo (int nb_dodo)
*\brief Fonction de generation des differents points de dodo dans le labyrinthe
*\param int nb_dodo nombre de point pour dormir a généré
*/
/*fonction de genration des differents points de dodo dans le labyrinthe */
void gen_points_dodo (int nb_dodo){
	int i = 0, j =0; /*declaration des variables permettant de stocker les coordonnees d'un point de dodo*/
	int compteur = 0;
	for (compteur = 0; compteur < nb_dodo; compteur ++){
		do{
			i = rand() % 12;
			j = rand() % 12;
		}
		while(emplacement[i][j] != vide);
		emplacement[i][j] = dodo;
	}
}


/**
*\fn void gen_points (void)
*\brief Fonction de generation aleatoire des differents points utiles
*/
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
	gen_points_repas(nb_manger);
	gen_troll_case();
}
