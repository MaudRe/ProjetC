#ifndef _MES_FONCTIONS_
#define _MES_FONCTIONS_

typedef struct _liste{
	int k;
	struct _liste * suivant;
}*Liste;
char **creer_tableau(size_t lignes, size_t colonnes);
char **recup_codons(char **tableau, char *seq1,size_t nb_codons,size_t nb_columns);
void affiche_tableau(char **tableau, size_t lignes, size_t colonnes);
Liste compt_occur_codons(char **tableau1,char **tableau2, size_t lignes2, size_t colonnes2, size_t lignes1);
void afficher_liste_frequents(Liste occur_codons);
char retire_doublon(char **tableau);

#endif
