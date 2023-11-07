#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int main() {
	int fact = 1, n;
	int correct = 1;
	printf("Entrer un nombre : ");
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		fact *= i;
	}
	printf("Factorielle de %d : %d\n", n, fact);
	printf("Valeur maximale d'un int : %d\n", INT_MAX);
}