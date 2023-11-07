#include <stdlib.h>
#include <stdio.h>

int main() {
	int entier;
	do{
		printf("Entrer un entier strictement positif : ");
		scanf("%d",&entier);
	}while(entier < 1);
	for (int i = 1; i <= entier; ++i)
	{
		if(entier % i == 0){
			printf("%d\n", i);
		}
	}
}