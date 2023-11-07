#include <stdlib.h>
#include <stdio.h>
#define MAX 50

int main(){
	int somme = 0, nbEtudiants = 0, val, tab[MAX];
	do{
		if(scanf("%d", &val)==EOF) break;
		nbEtudiants++;
		somme+=val;
		tab[nbEtudiants] = val;
	}while(nbEtudiants<MAX);
	double moyenne = (double)somme/(double)nbEtudiants;
	printf("moyenne : %f\n", moyenne);

	printf("Ecarts a la moyenne :\n");
	for(int i = 0;i<nbEtudiants;i++)
		printf("Note : %d, Ecart : %f\n", tab[i], (double)tab[i]-moyenne);
}