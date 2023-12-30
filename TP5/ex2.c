#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAILLEMAX 27

int main(int argc, char const *argv[])
{
 	for(int i=1;i<argc;i++){
		printf("%d. %s\n", i,argv[i]);
	}
	int compteur = 0;
	char ligne[TAILLEMAX+2];
	while(fgets(ligne, TAILLEMAX, stdin) != NULL){
		while((fgets(ligne, TAILLEMAX, stdin) != NULL && ligne[strlen(ligne)-1] != '\n'));
		for (int i = 0; i < strlen(ligne); ++i)
		{
			if(ligne[i]=='\n') ligne[i]='\0';
		}
		printf("%s\n", ligne);
		printf("Taille: %d\n", (int) strlen(ligne));
		int present = 0;
		for (int i = 1; i < argc; ++i)
		{
			if(strcmp(argv[i], ligne) == 0){
				present = 1;
				break;
			}
		}
		if(present == 1)
			printf("%s: present\n", ligne);
		else
		{
			printf("%s: absent\n", ligne);
			compteur++;
		}
	}
	printf("Nombre de fois ou un mot lut n'a pas été trouvé dans argv: %d\n", compteur);
}