#include <stdlib.h>
#include <stdio.h>

int main(){
	int n;
	printf("Entrez le nombre de cotes :\n");
	scanf("%d", &n);

	do{
	int* tab = (int*) malloc(n * sizeof(int*));
	int nbPositif = 0, nbNegatif = 0;

	for(int *ptr=tab; ptr-tab<n; ptr++){
		printf("Entrez la cote n° %d\n", (int)(ptr-tab)+1);
		scanf("%d", ptr);
		if(*ptr>=0) nbPositif++;
		else nbNegatif++;
	}

	int* tabPositif = (int*) malloc(nbPositif * sizeof(int));
	int* tabNegatif = (int*) malloc(nbNegatif * sizeof(int));
	int* ptrP = tabPositif;
	int* ptrN = tabNegatif;

	for (int *ptr=tab; ptr-tab<n; ptr++){
		if(*ptr>=0) {
			*ptrP = *ptr;
			ptrP++;
		}
		else {
			*ptrN = *ptr;
			ptrN++;
		}
	}
	free(tab);
	if(nbPositif>0){
		printf("Cotes positives\n");
		for (int *ptr=tabPositif; ptr-tabPositif<nbPositif; ptr++){
			printf("%d ", *ptr);	
		}
	}
	free(tabPositif);
	if(nbNegatif>0){
		printf("\nCotes Negatives\n");
		for (int *ptr=tabNegatif; ptr-tabNegatif<nbNegatif; ptr++){
			printf("%d ", *ptr);	
		}
	}
	free(tabNegatif);
	printf("\n");

	printf("Entrez un nouveau nombre de cotes (0 pour arreter)\n");
	scanf("%d", &n);
	}while(n>0);
}