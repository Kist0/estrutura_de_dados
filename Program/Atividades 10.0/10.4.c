#include <stdio.h>
#include <locale.h>

void main() {
	setlocale(LC_ALL, "portuguese");
	int num, cont=0, soma=0;
	
	printf("Digite os n�meros (0 para sair): ");
	do {
		scanf("%d", &num);
		if ((num % 2) == 0 && num != 0) {
			soma += num;
			cont++;
		}
	}while (num != 0);
	printf("A m�dia dos n�meros fornecidos � %.2f", (float)soma/cont);
}
