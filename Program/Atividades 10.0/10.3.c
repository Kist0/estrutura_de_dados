#include <stdio.h>

void main() {
	int num, s=0;
	
	printf("Digite um n�mero ");
	do {
		scanf("%d", &num);
		s += num;
	}while (s < 30);
	printf("\nChegou a 30");
}
