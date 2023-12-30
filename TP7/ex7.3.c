#include <stdio.h>
#include <stdlib.h>

#define POWER 2

/* Crée un tableau avec les puissances d’un nombre
* PRE: n: nombre entier strictement positif
* RES: renvoie un tableau de taille n+1 contenant les puissances de n
* PROBLEME: renvoie l'adresse d'une variable initialisée dans la fonction, n'existe donc pas en dehors
*/
// int* creerTable (int n) {
// 	int t[n+1];
// 	t[0] = 1;
// 	for (int i=1; i<=n; i++)
// 		t[i] = t[i-1] * n;
// 	return (int*)t;
// }

/* Crée un tableau avec les puissances d’un nombre
* PRE: n: nombre entier strictement positif
* RES: renvoie un tableau de taille n+1 contenant les puissances de n
*/
int* creerTable (int n) {
	int* t = (int*) malloc((n+1)*sizeof(int));
	t[0] = 1;
	for (int i=1; i<=n; i++)
		t[i] = t[i-1] * n;
	return (int*)t;
}

int main(int argc, char const *argv[])
{
	int* tab = creerTable(POWER);
	for (int i = 0; i < POWER+1; ++i)
		printf("%d\n", tab[i]);
}