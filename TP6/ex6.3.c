#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

void choisirAction(int *choix){
	printf("MENU:\n");
	printf("	1) Création d’une image de dimensions précisées par l’utilisateur avec valeurs aléatoires pour les pixels\n");
	printf("	2) Création d’une image de dimensions précisées par l’utilisateur avec valeurs prédéfinies pour les pixels\n");
	printf("	3) Affichage de l’image\n");
	printf("	4) Changement de la taille de l’image\n");
	printf("	5) Affichage de l’histogramme de l’image\n");
	printf("	6) Suppression de l’image\n");
	printf("	7) Rotation de l'image de 90°\n");
	printf("	8) Quitter le programme\n");
	scanf("%d", choix);
}

int** creerImageAleatoire(int nbLignes, int nbColonnes, int profondeurBits){
	int ** image = (int**) malloc(nbLignes*sizeof(int*));
	if(image==NULL) exit(1);
	for (int i = 0; i < nbLignes; ++i){
		image[i] = (int*) malloc(nbLignes*sizeof(int));
	}
	time_t t;
	time(&t);
	srand((unsigned int)t);
	for (int i = 0; i < nbLignes; ++i)
	{
		for (int j = 0; j < nbColonnes; ++j)
		{
			image[i][j] = rand() % (int) pow(2, profondeurBits);
		}
	}
	return image;
}

int** creerImagePredefinie(int nbLignes, int nbColonnes, int profondeurBits){
	int** image = (int**) malloc(nbLignes*sizeof(int*));
	if(image==NULL) exit(1);
	for (int i = 0; i < nbLignes; ++i){
		image[i] = (int*) malloc(nbLignes*sizeof(int));
	}
	for (int i = 0; i < nbLignes; ++i)
	{
		for (int j = 0; j < nbColonnes; ++j)
		{
			image[i][j] = (i+1) % (int) (pow(2, profondeurBits))-1;
		}
	}
	return image;
}

void afficherImage(int ** image, int nbLignes, int nbColonnes){
	printf("Affichage de l'image:\n");
	for (int i = 0; i < nbLignes; ++i)
	{
		for(int* ptrColonne = image[i]; ptrColonne-image[i]<nbColonnes;++ptrColonne)
		{
			printf("%d", *ptrColonne);
		}
		printf("\n");
	}
}

int** changerTailleImage(int** image, int nbLignes, int nbColonnes, int newLignes, int newColonnes){
	if(newLignes==nbLignes&&newColonnes==nbColonnes)
		printf("Les dimensions entrées sont identiques aux précedentes!\n");
	else if(newLignes >= nbLignes && newColonnes >= nbColonnes){
		if(newLignes==nbLignes){
			//realloc colonnes
			for (int i = 0; i < nbLignes; ++i)
			{
				image[i] = (int*) realloc(image[i], newColonnes*sizeof(int));
				if(image[i]==NULL) exit(1);
				for (int j = nbColonnes; j < newColonnes; ++j)
				{
					image[i][j] = 0;
				}
			}
		}
		else if(newColonnes==nbColonnes){
			//realloc lignes
			image = (int**) realloc(image, newLignes*sizeof(int*));
			if(image==NULL) exit(1);
			for (int i = nbLignes; i < newLignes; ++i)
			{
				image[i] = (int*) malloc(nbColonnes*sizeof(int*));
				if(image[i]==NULL) exit(1);
				for (int j = 0; j < nbColonnes; ++j)
				{
					image[i][j] = 0;
				}			
			}
		}
		else{
			//realloc lignes et colonnes
			//alloc lignes
			image = (int**) realloc(image, newLignes*sizeof(int*));
			if(image==NULL) exit(1);
			for (int i = nbLignes; i < newLignes; ++i)
			{
				image[i] = (int*) malloc(nbColonnes*sizeof(int*));
				if(image[i]==NULL) exit(1);
				for (int j = 0; j < nbColonnes; ++j)
				{
					image[i][j] = 0;
				}			
			}
			//alloc colonnes
			for (int i = 0; i < newLignes; ++i)
			{
				image[i] = (int*) realloc(image[i], newColonnes*sizeof(int));
				if(image[i]==NULL) exit(1);
				for (int j = nbColonnes; j < newColonnes; ++j)
				{
					image[i][j] = 0;
				}
			}
		}
	}
	else if(newLignes <= nbLignes && newColonnes <= nbColonnes){
		if(newLignes==nbLignes){
			//realloc colonnes
			for (int i = 0; i < nbLignes; ++i)
			{
				image[i] = (int*) realloc(image[i], newColonnes*sizeof(int));
				if(image[i]==NULL) exit(1);
			}
		}
		else if(newColonnes==nbColonnes){
			//realloc lignes
			image = (int**) realloc(image, newLignes*sizeof(int*));
			if(image==NULL) exit(1);
		}
		else{
			//realloc lignes et colonnes
			image = (int**) realloc(image, newLignes*sizeof(int*));
			if(image==NULL) exit(1);
			for (int i = 0; i < newLignes; ++i)
			{
				image[i] = (int*) realloc(image[i], newColonnes*sizeof(int));
				if(image[i]==NULL) exit(1);
			}
		}	
	}
	else printf("La taille entrée ne correspond ni à un découpage ni à un agrandissement!\n");
	return image;
}

int* calculerHistogramme(int** image, int nbLignes, int nbColonnes, int nbElements, int profondeurBits){
	int* histogramme = (int*) malloc(nbElements*sizeof(int));
	if(histogramme==NULL) exit(1);
	for (int i = 0; i < nbLignes; ++i)
	{
		for(int* ptrColonne = image[i]; ptrColonne-image[i]<nbColonnes;++ptrColonne)
		{
			histogramme[*ptrColonne]++;
		}
	}
	for (int *ptr=histogramme; ptr-histogramme<pow(2, profondeurBits); ++ptr)
	{
		if(*ptr > 0) 
			printf("#pixels de valeur %d: %d\n", (int)(ptr-histogramme), *ptr);
	}
	free(histogramme);
	printf("Nombre de pixels dans l'image: %d\n", nbElements);
	return histogramme;
}

int** rotationImage(int** image, int nbLignes, int nbColonnes){
	int** imageRotation = (int**) malloc(nbLignes*sizeof(int*));
	if(imageRotation==NULL) exit(1);
	for (int i = 0; i < nbLignes; ++i)
	{
		imageRotation[i] = (int*) malloc(nbColonnes*sizeof(int));
		if(imageRotation[i]==NULL) exit(1);
	}
	for (int i = 0; i < nbLignes; ++i)
	{
		for (int j = 0; j < nbColonnes; ++j)
		{
			imageRotation[j][(nbLignes-1)-i] = image[i][j];
		}
	}
	// for (int i = 0; i < nbLignes; ++i)
	// 	free(image[i]);
	// free(image);
	// printf("%p\n", (void*)&image);
	// image = imageRotation;
	return imageRotation;
}

void freeImage(int** image, int nbLignes){
	if(image==NULL) printf("Aucune image à libérer\n");
	else{
		for (int i = 0; i < nbLignes; ++i)
			free(image[i]);
		free(image);
	}
}

int main(int argc, char const *argv[]){
	int ** image = NULL;
	int nbLignes = 0, nbColonnes = 0, profondeurBits = 0, newLignes = 0, newColonnes = 0, nbElements = 0;
	int choix;
	choisirAction(&choix);
	while(choix != 8){
		switch(choix){
			case 1:
				printf("Entrez le nombre de lignes: ");
				scanf("%d", &nbLignes);
				printf("Entrez le nombre de colonnes: ");
				scanf("%d", &nbColonnes);
				printf("Entrer la profondeur de bits: ");
				scanf("%d", &profondeurBits);
				image = creerImageAleatoire(nbLignes, nbColonnes, profondeurBits);
				break;
			case 2:
				printf("Entrez le nombre de lignes: ");
				scanf("%d", &nbLignes);
				printf("Entrez le nombre de colonnes: ");
				scanf("%d", &nbColonnes);
				printf("Entrer la profondeur de bits: ");
				scanf("%d", &profondeurBits);
				image = creerImagePredefinie(nbLignes, nbColonnes, profondeurBits);
				break;
			case 3:
				if(image==NULL) printf("Pas d'image existante!\n");
				else afficherImage(image, nbLignes, nbColonnes);
				break;
			case 4:
				printf("Entrez les nouvelles dimensions de l'image (nombre de lignes puis de colonnes): ");
				scanf("%d %d", &newLignes, &newColonnes);
				image = changerTailleImage(image, nbLignes, nbColonnes, newLignes, newColonnes);
				nbLignes=newLignes;
				nbColonnes=newColonnes;
				break;
			case 5:
				nbElements = nbLignes*nbColonnes;
				calculerHistogramme(image, nbLignes, nbColonnes, nbElements, profondeurBits);
				break;
			case 6:
				printf("Liberation de la memoire dynamique\n");
				freeImage(image, nbLignes);
				break;
			case 7:
				if(image==NULL) printf("Pas d'image existante\n");
				else image = rotationImage(image, nbLignes, nbColonnes);
				break;
			case 8:
				printf("Sortie du programme\n");
				freeImage(&image, nbLignes);
				exit(1);
		}
		choisirAction(choix);
	}
}