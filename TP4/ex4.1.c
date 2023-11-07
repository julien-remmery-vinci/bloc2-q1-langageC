#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int hauteur, largeur, entree;
	char joueur = 'X';
	printf("Entrez la hauteur: \n");
	scanf("%d", &hauteur);
	printf("Entrez la largeur: \n");
	scanf("%d", &largeur);
    char** grille = (char**) malloc(hauteur*sizeof(char*));
    if(grille == NULL) exit(1);
    for (int i = 0; i < hauteur; ++i){
    	grille[i] = (char*) malloc(largeur*sizeof(char));
    	if(grille[i] == NULL) exit(1);
    	for (int j = 0; j < largeur; ++j)
    	{
    		grille[i][j] = '.';
    	}
    }
    do{
    	//demande colonne de jeu
    	printf("Colonne joueur %c ? ", joueur);
    	scanf("%d", &entree);
    	if(entree > largeur){
    		for (int i = 0; i < hauteur; ++i){
    			grille[i] = (char*) realloc(grille[i], (largeur+entree)*sizeof(char));
    			if(grille[i] == NULL) exit(1);
    			for (int j = largeur; j < largeur+entree; ++j)
    				grille[i][j] = '.';
    		}
    		largeur = entree;
    	}
    	else if(entree < 0){
    		for (int i = 0; i < hauteur; ++i){
    			grille[i] = (char*) realloc(grille[i], abs(entree)*sizeof(char));
    			if(grille[i] == NULL) exit(1);
    		}
    		largeur = abs(entree);
    	}
    	for (int i = hauteur; i > 0; --i){
    		if(grille[i-1][entree-1]=='.'){
    			grille[i-1][entree-1] = joueur;
    			break;
    		}
    	}
    	//affichage grille
    	for (int i = 0; i < hauteur; ++i){
    		for (int j = 0; j < largeur; ++j)
    			printf("%c", grille[i][j]);
    		printf("\n");
    	}
    	//verification victoire
    	
    	if(joueur == 'X') joueur = 'O';
    	else joueur = 'X';
    }while(entree != 0);
    for (int i = 0; i < hauteur; ++i)
    	free(grille[i]);
    free(grille);
}