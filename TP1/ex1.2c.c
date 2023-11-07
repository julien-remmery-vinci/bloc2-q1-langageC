#include <stdlib.h>
#include <stdio.h>

int main() {
	int entier1, entier2;
	printf("Entrer un entier : ");
	scanf("%d",&entier1);
	printf("Entrer un deuxieme entier : ");
	scanf("%d",&entier2);
	int tmp = entier1;
	entier1 = entier2;
	entier2 = tmp;
	printf("Valeurs échangées :\n");
	printf("Entier 1 : %d\n", entier1);
	printf("Entier 2 : %d\n", entier2);
}