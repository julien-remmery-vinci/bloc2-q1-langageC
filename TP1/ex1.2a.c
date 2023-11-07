#include <stdlib.h>
#include <stdio.h>

int main() {
	float i, j;
	printf("Entrer un entier : ");
	scanf("%f",&i);
	printf("Entrer un deuxième entier : ");
	scanf("%f",&j);
	float produit = i * j;
	printf("Produit = %f\n", produit);
}