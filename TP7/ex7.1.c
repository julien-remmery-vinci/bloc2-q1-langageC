#include <stdio.h>
#include <stdlib.h>

//EXAMEN
bool chargerEntiers(const char* chemin, int** tab, int* logicSize, int* physicSize);

bool chargerMots(char* chemin, char*** tab, int* logicSize, int* physicSize);

int separerMots(char* tab, int* physicSize);