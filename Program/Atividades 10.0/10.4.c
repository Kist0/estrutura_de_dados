#include <stdio.h>
#include <locale.h>

void main() {
	setlocale(LC_ALL, "portuguese");
	int num, cont=0, soma=0;
	
	printf("Digite os números (0 para sair): ");
	do {
		scanf("%d", &num);
		if ((num % 2) == 0 && num != 0) {
			soma += num;
			cont++;
		}
	}while (num != 0);
	printf("A média dos números fornecidos é %.2f", (float)soma/cont);
}
