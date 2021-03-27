#include <stdio.h>

void main() {
	int n, i;
	
	printf("Digite a quantidade de caracteres que sua palavra terá: ");
	scanf("%d", &n);
	char palavra[n];
	printf("Digite a palavra: ");
	scanf("%s", &palavra);
	for (i=0; i<=n; i++)
		printf("%c \n", palavra[i]);
}
