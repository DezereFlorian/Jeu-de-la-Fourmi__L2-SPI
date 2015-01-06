/* Page permettant de verifier la saisie de l'utilisateur*/

#include "header.h"

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
