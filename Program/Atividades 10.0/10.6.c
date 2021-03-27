#include <stdio.h>
#include <locale.h>

void main() {
	setlocale (LC_ALL, "portuguese");
	int cpf, dependentes;
	float renda, imposto, sal_minimo;
	
	printf("Digite o valor do salário mínimo atual: R$");
	scanf("%f", &sal_minimo);
	do {
		
		if (cpf != 0) {
			printf("\n\nDigite seu CPF (sem . e -) (0 para sair): ");
			scanf("%d", &cpf);
			printf("\nDigite o número de dependentes: ");
			scanf("%d", &dependentes);
			printf("\nDigite sua renda mensal: R$ ");
			scanf("%f", &renda);
			
			//Para cada contribuinte será feito um desconto de 5% de salário mínimo por dependente
			if (dependentes != 0)
				renda = renda - (renda * dependentes*5 / 100);

			//calculo de imposto a pagar
			if (renda >= sal_minimo*2 && renda <= sal_minimo*3)
				imposto = renda * 5 / 100;
			else if (renda > sal_minimo*3 && renda <= sal_minimo*5)
				imposto = renda * 10 / 100;
			else if (renda > sal_minimo*5 && renda <= sal_minimo*7)
				imposto = renda * 15 / 100;
			else if (renda > sal_minimo*7)
				imposto = renda * 20 / 100;
			else if (renda < sal_minimo*2)
				imposto = 0;
		
		if (imposto == 0)
			printf("\nISENTO\n");
		else
			printf("Total de imposto a pagar é %.2f\n", imposto);
		}
		
	}while (cpf != 0);
}
