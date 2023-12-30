#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * PRE : n : nombre entier positif
 * RES : vrai si n est premier ; faux sinon 
 */

bool isPrime(int n){
	for (int i = 2; i < n; ++i)
	{
		if(n%i==0) return false;
	}
	return true;
}

int main(int argc, char const *argv[])
{
	printf("%d\n", isPrime(7));
}