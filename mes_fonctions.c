#include <stdlib.h> //inclusion de bibliotheques 
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
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


Liste compt_occur_codons(char **tableau1,char **tableau2, size_t lignes2, size_t colonnes2, size_t lignes1){
	int occ_cod_i = 0;
	int c=0;
	int max_occ =0;
	char *max_occurence = malloc(3*sizeof(char*));
	char *tempo = malloc(4*sizeof(char*));
	
	for(int l=0; l<lignes1;l++){
			occ_cod_i=0;
			for(int i=0; i<lignes2; i++){
				for(int k=0;k<colonnes2;k++){
					if(tableau1[l][k]==tableau2[i][k]){
						c+=1;
					}
				}
				if(c==3){
					occ_cod_i +=1;
			}
			c=0;
		}
		if(tableau1[l][0]!='0'){
		printf("Pour codon %c%c%c : %d occurences \n",tableau1[l][0],tableau1[l][1],tableau1[l][2],occ_cod_i);
		if(occ_cod_i>max_occ){
			free(max_occurence);
			char *max_occurence = malloc(3*sizeof(char*));
			max_occurence[0] = tableau1[l][0];
			max_occurence[1] = tableau1[l][1];
			max_occurence[2] = tableau1[l][2];
			max_occ=occ_cod_i;
		} else if(occ_cod_i==max_occ){
			tempo[0]=',';
			tempo[1]=tableau1[l][0];
			tempo[2]=tableau1[l][1];
			tempo[3]=tableau1[l][2];
			strcat(max_occurence,tempo);
			}
		}
	}
	printf("Le maximum d'occurence est pour les condons %s avec %d occurences \n",max_occurence,max_occ);
}


char test(char **tableau, size_t lignes, size_t colonnes){
	int codi = 0;
	int c=0;
	int nb_c=0;
	for(int l=0; l<lignes;l++){
		for(int i=0; i<lignes; i++){
			for(int k=0;k<colonnes;k++){
				if(i!=l){
				if(tableau[l][k]==tableau[i][k]){
					c+=1;
					}
				}
			}
			if(c==3){
				for(int kb=0;kb<colonnes;kb++){
					tableau[l][kb]= '0';
					}
					codi++;
				}
			c=0;
			nb_c++;
		}

	}
	printf("Nous avons  %d doublons \n",codi);
	return **tableau;
}

