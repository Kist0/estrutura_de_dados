#include <stdio.h>
#include <locale.h>

void main() {
	setlocale(LC_ALL, "portuguese");
	float desconto, precos[] = {23.99, 44.89, 78.10, 12.10, 89.78, 100.00, 250.00, 38.80, 74.87, 11.54, 57.35};
	int i;
	
	printf("Digite a porcentagem de desconto dos produtos da loja: ");
	scanf("%f", &desconto);
	//if (desconto < 1)
	//	desconto = desconto * 100;
	
	for (i=0; i<=precos[]; i++) {
		precos[i] = precos[i] - (precos[i] * desconto / 100);
		printf("%.2f \n", precos[i]);
	}
}
