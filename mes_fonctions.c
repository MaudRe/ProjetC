#include <stdlib.h> //inclusion de bibliotheques 
#include <stdio.h>
#include <stdbool.h>
#include "mes_fonctions.h"

/*Considérons deux séquences d’ADN s 1 et s 2 . Nous souhaitons déterminer
le ou les codons de s 1 le(s) plus fréquent(s) dans s 2 . Nous ne considérons les
séquences que dans un sens, et tous les cadres de lecture.
Par exemple, pour les séquences ATGGCGTTAGCAAGAATGA et AAATGCCCGTTAGAGTTA,
ce codon est TTA, présent dans s 1 et le plus fréquent dans s 2 .
Question : ecrire un programme en C (avec Makefile) respectant les règles
de programmation vues en cours, permettant de déterminer et afficher la liste
de ces codons. Les deux séquences seront données en arguments sur la ligne de
commande.*/


char **creer_tableau(size_t lignes, size_t colonnes){
	size_t **tableau;
	tableau=(size_t**)malloc(lignes*sizeof(size_t*));
	for(size_t k=0;k<lignes;k++){
		tableau[k]=(size_t*)calloc(colonnes,sizeof(size_t));
	}
	return tableau;
}



size_t longueur_chaine(char *chaine){
	int i=0;
	while(chaine[i]!='\0'){
		i++;
	}
	return i;
}

char **recup_codons(char **tableau, char *seq1,size_t nb_codons,size_t nb_columns){
	int s=0;
	for(int i=0; i<nb_codons; i++){
		for(int k=0;k<nb_columns;k++){
			tableau[i][k]=seq1[s+k];
		}
		s++;
	}
	return tableau;
}

void affiche_tableau(char **tableau, size_t lignes, size_t colonnes){
	printf("Tableau \n");	
	for(int l=0;l<lignes;l++){
		for(int c=0;c<colonnes;c++){
			printf("%c ",tableau[l][c]);
		}
		printf("\n");
	}
}

char retire_doublon(char **tableau){
	
}

Liste compt_occur_codons(char **tableau1,char **tableau2, size_t lignes2, size_t colonnes2, size_t lignes1){
	int occ_cod_i = 0;
	int c=0;
	for(int l=0; l<lignes1;l++){
		//printf("l : %d \n",l);
		for(int i=0; i<lignes2; i++){
			//printf("i : %d \n",i);
			for(int k=0;k<colonnes2;k++){
				//printf("k : %d \n",k);
				if(tableau1[l][k]==tableau2[i][k]){
					c+=1;
					}
			}
			if(c==3){
				occ_cod_i +=1;
				}
			c=0;
		}
		printf("Pour codon %d : %d occurences \n",l,occ_cod_i);
		occ_cod_i=0;
		//printf("\n");
	}
}


void afficher_liste_frequents(Liste occur_codons){
	
}

