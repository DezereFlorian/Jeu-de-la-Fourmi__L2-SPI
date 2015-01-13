labyzor.exe : main.o affichage.o stock.o mise_a_0.o gen_labyrinthe.o fourmi.o deplacement.o fin_de_jeu.o verification_saisie.c aleatoire.c
	gcc -o labyrinthe main.o affichage.o stock.o mise_a_0.o gen_labyrinthe.o fourmi.o deplacement.o fin_de_jeu.o verification_saisie.c aleatoire.c
	
main.o : main.c
	gcc -o main.o -c main.c -Wall
	
affichage.o : affichage.c
	gcc -o affichage.o -c affichage.c -Wall
	
stock.o : stock.c
	gcc -o stock.o -c stock.c -Wall
	
mise_a_0.o : mise_a_0.c
	gcc -o mise_a_0.o -c mise_a_0.c -Wall
	
deplacement.o : deplacement.c 
	gcc -o deplacement.o -c deplacement.c -Wall
	
fin_de_jeu.o : fin_de_jeu.c 
	gcc -o fin_de_jeu.o -c fin_de_jeu.c -Wall
	
verification_saisie.o : verification_saisie.c
	gcc -o verification_saisie.o -c verification_saisie.c -Wall
	
aleatoire.o : aleatoire.c 
	gcc -o aleatoire.o -c aleatoire.c -Wall

fourmi.o : fourmi.c 
	gcc -o fourmi.o -c fourmi.c -Wall
	
gen_labyrinthe.o : gen_labyrinthe.c header.h header_fourmi.h
	gcc -o gen_labyrinthe.o -c gen_labyrinthe.c -Wall
	
clean:
	rm *.o
