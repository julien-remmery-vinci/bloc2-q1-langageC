#include <stdio.h>
#include <stdlib.h>

void permutterEntiers(int* a, int* b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void permutterStrings(char** a, char** b){
	char** tmp = a;
	a = b;
	b = tmp;
}

void permutterTab(int* a, int* b){
	int* tmp = a;
	a = b;
	b = tmp;
}

int main(int argc, char const *argv[])
{
	
}