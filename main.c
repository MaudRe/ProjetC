#include <stdlib.h> //inclusion de bibliotheques 
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "mes_fonctions.h"


int main(int argc, char **argv){
	if(argc!=3){
			printf("Mauvais nombre d'arguments \n");
			exit(EXIT_FAILURE);
	}
	char *seq1=argv[1];
	char *seq2=argv[2];
	size_t longueur1 =strlen(seq1);
	size_t longueur2 =strlen(seq2);
	size_t nb_codons1 = longueur1-2;
	size_t nb_codons2 = longueur2-2;
	size_t nb_columns = 3;
	char **tableau1=creer_tableau(nb_codons1,nb_columns);
	tableau1= recup_codons(tableau1, seq1, nb_codons1, nb_columns);
	test(tableau1, nb_codons1, nb_columns);
	char **tableau2=creer_tableau(nb_codons2,nb_columns);
	tableau2= recup_codons(tableau2, seq2, nb_codons2, nb_columns);
	affiche_tableau(tableau1,nb_codons1,nb_columns);
	affiche_tableau(tableau2,nb_codons2,nb_columns);
	compt_occur_codons(tableau1, tableau2, nb_codons2, nb_columns, nb_codons1);
	return EXIT_SUCCESS;
}
