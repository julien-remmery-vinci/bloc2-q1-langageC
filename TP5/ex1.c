#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
	char** motsMajuscules = (char **) malloc(argc * sizeof(char*));
	if(motsMajuscules == NULL) exit(1);
	for (int i = 0; i < argc; ++i)
	{
		motsMajuscules[i] = (char*) malloc(strlen(argv[i+1]+1) * sizeof(char));
		if(motsMajuscules[i] == NULL) exit(1);
		for (int j = 0; j < strlen(argv[i+1]); ++j)
		{
			motsMajuscules[i][j] = toupper(argv[i][j]);
		}
 	}
	for(int i = 1;i<argc;i++){
		printf("%s ", motsMajuscules[i]);
	}
	printf("\n");
	for(int i=1;i<argc;i++){
		printf("%s ", argv[i]);
	}
	printf("\n");
	for (int i = 0; i < argc; ++i)
		free(motsMajuscules[i]);
	free(motsMajuscules);
}