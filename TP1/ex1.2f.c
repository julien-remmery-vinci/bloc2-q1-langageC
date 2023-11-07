#include <stdlib.h>
#include <stdio.h>

int main() {
	int entier1, entier2;

	printf("Entrer un entier : ");
	scanf("%d", &entier1);
	printf("Entrer un deuxieme entier : ");
	scanf("%d", &entier2);

	int quotient = 0, reste = 0;

	if(entier1 > entier2){
		while(entier1>=entier2){
			entier1 -= entier2;
			quotient++;
		}
		reste = entier1;
	}else{
		while(entier2>=entier1){
			entier2 -= entier1;
			quotient++;
		}
		reste = entier2;
	}
	printf("Résultat : \n");
	printf("- quotient : %d\n", quotient);
	printf(" -reste : %d\n", reste);
}