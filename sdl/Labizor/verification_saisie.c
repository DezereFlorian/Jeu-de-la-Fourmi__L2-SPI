/**
* \file verification_saisie.c
* \brief Page permettant de vérifier la saisie de l'utilisateur
* \author Jean-baptiste Dubois, Provost Valentin, Dezere Florian
* \version 1.0
* \date 6 Janvier 2014
*
*/



#include "header.h"

/**
*\fn int verif_saisie (int petit, int grand)
*\brief Fonction permettant de verifier si la saisie de l'utilisateur est correcte
*\param int petit, int grand paramètre pour verifier si le nombre entrer n'est pas trop grand ou trop petit
*\return renvoi le nombre entrer par l'utilisateur
*/


 int verif_saisie (int petit, int grand){
 	int output = 0;
 	scanf("%i", &output);
 	while (output < petit || output > grand){
 		printf("Entrez une valeur correcte, qui soit comprise entre %i et %i : ",petit, grand);
 		scanf("%i",&output);
 	}
 	return output;
 }
