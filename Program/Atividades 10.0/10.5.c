#include <stdio.h>
#include <ctype.h>

void main() {
	int num;
	char verific;
	
	printf("Tabuada até 10!\n");
	do {
		printf("Digite um número: ");
		scanf("%d", &num);
		printf("1x%d = %d\n", num, num * 1);
		printf("2x%d = %d\n", num, num * 2);
		printf("3x%d = %d\n", num, num * 3);
		printf("4x%d = %d\n", num, num * 4);
		printf("5x%d = %d\n", num, num * 5);
		printf("6x%d = %d\n", num, num * 6);
		printf("7x%d = %d\n", num, num * 7);
		printf("8x%d = %d\n", num, num * 8);
		printf("9x%d = %d\n", num, num * 9);
		printf("10x%d = %d\n", num, num * 10);
		printf("Deseja refazer a tabuada? (S/N) ");
		scanf("%s", &verific);
		verific = toupper(verific);
	}while (verific != 'N');
}
