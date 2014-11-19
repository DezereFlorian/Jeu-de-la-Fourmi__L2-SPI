labyrinthe : main.o affichage.o stock.o mise_a_0.o gen_labyrinthe.o 
	gcc -o labyrinthe main.o affichage.o stock.o mise_a_0.o gen_labyrinthe.o 
	
main.o : main.c
	gcc -o main.o -c main.c -Wall
	
affichage.o : affichage.c
	gcc -o affichage.o -c affichage.c -Wall
	
stock.o : stock.c
	gcc -o stock.o -c stock.c -Wall
	
mise_a_0.o : mise_a_0.c
	gcc -o mise_a_0.o -c mise_a_0.c -Wall
	
gen_labyrinthe.o : gen_labyrinthe.c header.h
	gcc -o gen_labyrinthe.o -c gen_labyrinthe.c -Wall