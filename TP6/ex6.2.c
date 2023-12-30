#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define INVITE_SIZE 60
#define BUF_SIZE 16 
#define MAX_LONG 27  // longueur maximale d'un mot

/**
 * PRE : t : tableau de chaînes de caractères de taille sz ne contenant pas de chaînes nulles.
 * POST : Les chaînes de caractères de t sont affichées sur stdout dans l’ordre des indices à raison d’une chaine par ligne.
 **/
void impTable (char** t, int sz){
	// affichage du tableau des arguments
    printf("Arguments:\n");
    for (int i=0; i<sz; i++){
        printf("  %d: %s\n", i, t[i]);
    }
}
/**
 * PRE : chaines: tableau de chaînes de caractères de taille n ne contenant pas de chaînes nulles mot: chaîne de caractères
 * RES : renvoie vrai si mot se trouve dans le tableau chaines ; faux sinon
 **/
bool rechercher (char** chaines, int n, char* mot){
    for (int i=0;i<n;i++) {
        if (!strcmp(mot, chaines[i])){
            return true;
        }
    }
    return false;
}
/**
 * PRE : inv : chaîne de caractères
 *		 s   : tableau de char de taille sz
 * OST : La fonction a affiché le message d’invitation inv sur stdout, ensuite elle a lu
 * sur stdin une chaîne de caractère d’au plus sz – 1 caractères, a vérifié qu’elle n’est
 * ni vide, ni trop longue et répété l’opération tant qu’une chaîne valide n’est pas
 * ntroduite, puis elle a remplacé le ‘\n’ par ‘\0’. La chaîne valide a été placée dans s.
 * RES : renvoie le nombre de caractères de la dernière chaîne lue ; -1 si fin de fichier [Ctrl-D] atteinte
 **/
int litEtValideChaine (char* inv, char* s, int sz){
	printf("%s", inv);
	while (fgets(s, sz, stdin) != NULL) {
		if(strlen(s) == 1) continue;

		if(s[strlen(s)-1] != '\n')
        // Variante 1: traitement du cas où le mot entré est trop long
        if (ligne[taille] != '\n') {
        	printf("Erreur: le mot entré est trop long.\n");

        	// vidage du buffer stdin
        	while (fgets(ligne, MAX_LONG+2, stdin) && ligne[strlen(ligne)-1] != '\n') ;
            
        	continue;
        }
	}

int main(int argc, char *argv[])
{
	int nbMots = argc-1;
	impTable(argv+1, nbMots);

    // recherche de mots lus au clavier
    bool present;
    int nbrAbsent = 0;
    printf("\nIntroduire des mots d'au plus %i lettres a rechercher :\n",MAX_LONG);
    char ligne[MAX_LONG+2];
    while (fgets(ligne, MAX_LONG+2, stdin) != NULL) {
        int taille = strlen(ligne)-1;

        // Variante 1: traitement du cas où le mot entré est trop long
        if (ligne[taille] != '\n') {
        	printf("Erreur: le mot entré est trop long.\n");

        	// vidage du buffer stdin
        	while (fgets(ligne, MAX_LONG+2, stdin) && ligne[strlen(ligne)-1] != '\n') ;
            
        	continue;
        }

        // remplacement de '\n' par '\0' dans la ligne lue
        ligne[taille] = '\0';
        printf("  '%s'  longueur = %d\n",ligne, (int)strlen(ligne));

        // recherche du mot entré dans le tableau argv
        present = rechercher(argv+1, argc-1, ligne);
        if (present) {
            printf("  '%s' est present dans la table\n", ligne);
        } else {
            printf("  '%s' est absent de la table\n", ligne);
            nbrAbsent++;
        }
    }
    
    // affichage des résultats
    printf("\n%d mots ont ete lus et n'etaient pas dans la table\n",nbrAbsent);
}