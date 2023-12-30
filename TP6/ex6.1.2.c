#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * PRE : n : nombre entier positif
 * RES : vrai si n est premier ; faux sinon 
 */

bool isPrime(int n){
	for (int i = 2; i < n; ++i)
		if(n%i==0) return 0;
	return 1;
}

/**
 * PRE : n >= 2
 * POST : sz est égal à la taille (physique et logique) du tableau renvoyé
 * RES : un tableau trié contenant tous les nombres premiers plus petits que n si
 * aucune erreur n’est survenue ; NULL si une erreur est survenue (sz est mis à 0)
 */
int* prime_numbers (int n, int* sz){
	int* tab = (int*) malloc(n*sizeof(int));
	if(tab==NULL) return NULL;
	for (int i = 2; i <= n; ++i)
		if(isPrime(i)){
			tab[*sz] = i;
			//++*sz;
			//*sz+=1;
			(*sz)++;
		}
	return tab;
}

int main(int argc, char const *argv[])
{
	printf("%d\n", isPrime(7));
	int sz = 0;
	int* tab = prime_numbers(100, &sz);
	if(tab==NULL) exit(1);
	for (int i = 0; i < sz; ++i)
		printf("[%d] : %d\n", i, tab[i]);
	free(tab);
}