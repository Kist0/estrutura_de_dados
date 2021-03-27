#include <stdio.h>

tabela(){
	
	printf("Especificação		Codigo		Preco\n");
	printf("Cachorro quente		100		1,20\n");
	printf("Bauru simples		101		1,30\n");
	printf("Bauru com ovo		102		1,50\n");
	printf("Hamburguer		103		1,20\n");
	printf("Cheeseburguer		104		1,30\n");
	printf("Refrigerante		105		1,00\n\n");
}

float calculo(){
	float preco;
	int codigo, qtd;
	
	printf("Digite o codigo do produto: ");
	scanf("%d", &codigo);
	printf("Digite a quantidade: ");
	scanf("%d", &qtd);
	switch(codigo){
		case 100:
			preco = 1.2 * qtd;
			printf("O valor a ser pago eh de %.2f reais\n\n", preco);
			break;
		case 101:
			preco = 1.3 * qtd;
			printf("O valor a ser pago eh de %.2f reais\n\n", preco);
			break;
		case 102:
			preco = 1.5 * qtd;
			printf("O valor a ser pago eh de %.2f reais\n\n", preco);
			break;
		case 103:
			preco = 1.2 * qtd;
			printf("O valor a ser pago eh de %.2f reais\n\n", preco);
			break;
		case 104:
			preco = 1.3 * qtd;
			printf("O valor a ser pago eh de %.2f reais\n\n", preco);
			break;
		case 105:
			preco = 1 * qtd;
			printf("O valor a ser pago eh de %.2f reais\n\n", preco);
			break;
	}
	return preco;
}

void main(){
	float codigo, qtd;
	float precotot;
	
	tabela();
	precotot = calculo();
	precotot = calculo() + precotot;
	precotot = calculo() + precotot;
	printf("O preco total a ser pago eh: %.2f", precotot);
}
