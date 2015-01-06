#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define N 10
typedef enum { false, true } bool;
typedef enum { vide, base, eau, dodo, manger, fourmi} t_contenu;
typedef struct { int i; int j; bool haut; bool droit; bool bas; bool gauche; t_contenu contenu; int stock; } t_case;

t_case cc; //définition de la case courante
t_case casetmp; //définition de la case temporaire
t_case labyrinthe[N][N]; //définition de la matrice de cases
t_case voisins[4]; //définition d'un tableau de voisins
int nb = 0; // nombre de voisins dans le tableau voisins[]

t_case pile[120]; //définition de la pile
int sommet; //sommet de la pile

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
	
}
