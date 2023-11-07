#include <stdlib.h>
#include <stdio.h>

int main() {
	char c = 'A';
	while(c<='Z'){
		printf("Caractère = '%c'  code déc. = '%d'  code hexa. = '%x'\n", c, c, c);
		c++;
	}
	c = '1';
	while(c<='9'){
		printf("Caractère = '%c'  code déc. = '%d'  code hexa. = '%x'\n", c, c, c);
		c++;
	}
}