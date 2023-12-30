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
	if(tab==NULL) exit(1);
	for (int i = 1; i <= n; ++i)
		if(isPrime(i)){
			tab[*sz] = i;
			++*sz;
		}
	return tab;
}

/**
 * PRE : t : tableau de longueur sz
 * POST : t représente un tableau trié contenant les sz premiers nombres premiers.
 * RES : vrai en cas de succès ; faux sinon
 */
bool first_prime_numbers (int* t, int sz){
	int n = 2;
	int szr;
	int* pn = prime_numbers(n, &szr);
	while (szr < sz) {
		n = n * 2;
		pn = prime_numbers(n, &szr);
	}
	// copier les sz premiers entiers de pn dans t
	for (int i = 0; i < sz; ++i)
	{
		t[i] = pn[i];
	}
	return true;
}

int main(int argc, char const *argv[])
{
	printf("%d\n", isPrime(7));
	int sz = 25;
	int* t = (int*) malloc(sz*sizeof(int));
	if(t==NULL) exit(1);
	first_prime_numbers(t, sz);
	for (int i = 0; i < sz; ++i)
		printf("[%d] : %d\n", i, t[i]);
	free(t);
}