#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char** copierArgs (char** tab, int n, int* ncp);
void trier (char** tab, int n);
void afficher (char** tab, int n);


int main (int argc, char* argv[]) {
   // Copie profonde des arguments du programme
   int* size;
   char** tab = copierArgs(argv, argc-1, &size);
   if(tab == NULL) exit(1);
   // Affichage du tableau
   afficher(tab, size);

   // Tri du tableau
   tab = trier(tab, size);
   
   // Affichage du tableau trié
   afficher(tab, size);

   // Libération de la mémoire dynamique
   for (int i = 0; i < size; ++i)
      free(tab[i]);
   free(tab);
}

/**
 * PRE: tab: tableau de n chaînes de caractères
 * POST: *ncp: nombre de chaînes dans le tableau renvoyé
 * RES: renvoie un tableau contenant les chaînes de tab sans doublon
 *      (taille logique = taille physique); NULL si une erreur s'est produite
 */
char** copierArgs (char** tab, int n, int* ncp) {

   // TODO
   char** copieTab = (char**) malloc(n*sizeof(char*));
   if(copieTab == NULL) return NULL;
   for (int i = 0; i < n; ++i)
   {
      copieTab[i] = (char*) malloc(strlen(tab[i])*sizeof(char));
      if(copieTab[i] == NULL) return NULL;
      for (int j = 0; j < *ncp; ++j)
         if(strcmp(copieTab[j], tab[i+1]) == 0) break;
         if(j==*ncp-1){
            strcpy(copieTab[i], tab[i+1]);
            ++(*ncp);
         }
   }
   return copieTab;
}

/**
 * PRE: tab: tableau de n chaînes de caractères
 * POST: les n chaînes de tab sont triées par ordre alphabétique
 *       (algorithme: tri par sélection)
 */
void trier (char** tab, int n) {

   // TODO
   // Cette fonction ne devrait pas créer de nouvelles chaînes,
   // elle ne fait que manipuler des adresses.

}

/**
 * PRE: tab: tableau de n chaînes de caractères
 * POST: affiche les chaînes de tab (à raison d'une par ligne,
 *       précédée par leur numéro)
 */
void afficher (char** tab, int n) {

   // TODO

}
