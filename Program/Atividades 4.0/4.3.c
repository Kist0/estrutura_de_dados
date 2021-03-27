#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdbool.h>

void calculaCosseno() {
	int codigo;
	float catetoAdjacente, hipotenusa, angulo;
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	printf("[1] Para informar o �ngulo\n");
	printf("[2] Para informar os catetos e a hipotenusa\n");
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	scanf("%d", &codigo);
	
	if (codigo == 1) {
		printf("\nPara calcular o cosseno informe\n");
		printf("\nO �ngulo do cosseno: ");
		scanf("%f", &angulo);

		printf("\n\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
		printf("O valor do cosseno, que tem por �ngulo adjacente %.3f, equivale a: %.3f", angulo, cos(angulo));
		printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
		
	} else if (codigo == 2) {
		printf("\nPara calcular o cosseno informe\n");
		printf("\nO valor do cateto adjacente: ");
		scanf("%f", &catetoAdjacente);
		printf("\nO valor da hipotenusa: ");
		scanf("%f", &hipotenusa);
		
		printf("\n\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
		printf("O valor do cosseno, que tem por cateto adjacente %.3f e por hipotenusa %.3f, equivale a: %.3f", catetoAdjacente, hipotenusa, catetoAdjacente/hipotenusa);
		printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	} else {
		printf("\n\nValor inv�lido");
		calculaCosseno();
	}
	
}

void calculaSeno() {
	int codigo;
	float catetoOposto, hipotenusa, angulo;
	
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	printf("[1] Para informar o �ngulo\n");
	printf("[2] Para informar os catetos e a hipotenusa\n");
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	scanf("%d", &codigo);
	if (codigo == 1){
		printf("\nPara calcular o seno informe\n");
		printf("\nO �ngulo do seno: ");
		scanf("%f", &angulo);

		printf("\n\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
		printf("O valor do cosseno, que tem por �ngulo adjacente %.3f, equivale a: %.3f", angulo, sin(angulo));
		printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	}

	if (codigo == 2){	
		printf("\nPara calcular o seno informe\n");
		printf("\nO valor do cateto oposto: ");
		scanf("%f", &catetoOposto);
		printf("\nO valor da hipotenusa: ");
		scanf("%f", &hipotenusa);
		
		printf("\n\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
		printf("O valor do seno, que tem por cateto oposto %.3f e por hipotenusa %.3f, equivale a: %.3f", catetoOposto, hipotenusa, catetoOposto / hipotenusa);
		printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	}
}

void calculaTangente() {
	int codigo;
	float catetoOposto, catetoAdjacente, angulo;

	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	printf("[1] Para informar o �ngulo\n");
	printf("[2] Para informar os catetos\n");
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	scanf("%d", &codigo);
	if (codigo == 1){
		printf("\nPara calcular a tangente informe\n");
		printf("\nO �ngulo da tangente: ");
		scanf("%f", &angulo);

		printf("\n\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
		printf("O valor da tangente, que tem por �ngulo adjacente %.3f, equivale a: %.3f", angulo, tan(angulo));
		printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	}
	

	if (codigo == 2){
		printf("\nPara calcular a tangente informe\n");
		printf("\nO valor do cateto oposto: ");
		scanf("%f", &catetoOposto);
		printf("\nO valor da cateto adjacente: ");
		scanf("%f", &catetoAdjacente);
		
		printf("\n\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
		printf("O valor da tangente, que tem por cateto oposto %.3f e por cateto adjacente %.3f, equivale a: %.3f", catetoOposto, catetoAdjacente, catetoOposto / catetoAdjacente);
		printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	}
}

void calculaCossecante() {
	float seno;
	printf("\nPara calcular o cossecante informe\n");
	printf("\nO �ngulo do seno: ");
	scanf("%f", &seno);

	printf("\n\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	printf("O valor do cossecante, que tem por seno %.3f, equivale a: %.3f", seno, 1 / sin(seno));
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
}

void calculaSecante() {
	float cosseno;
	printf("\nPara calcular o cossecante informe\n");
	printf("\nO �ngulo do coseno: ");
	scanf("%f", &cosseno);

	printf("\n\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	printf("O valor do cossecante, que tem por seno %.3f, equivale a: %.3f", cosseno, 1 / cos(cosseno));
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	
}

void calculaCotangente() {
	float tangente;
	printf("\nPara calcular o cotangente informe\n");
	printf("\nO �ngulo da tangente: ");
	scanf("%f", &tangente);

	printf("\n\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	printf("O valor do cotangente, que tem por tangente %.3f, equivale a: %.3f", tangente, 1 / tan(tangente));
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
}

bool verificaCodigo(int codigo) { 
	switch (codigo) {
		case 1:
			calculaCosseno();
			return true;
			break;
		case 2:
			calculaSeno();
			return true;
			break;
		case 3:
			calculaTangente();
			return true;
			break;
		case 4: 
			calculaCossecante();
			return true;
			break;
		case 5:
			calculaSecante();
			return true;
			break;
		case 6:
			calculaCotangente();
			return true;
			break;
		default:
			return false;
			break;
	}
}

bool printMenu() {
	int codigo;
	bool continua = true;

	do {
		printf("\n\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
		printf("Bem vindo � sua calculadora de Fun��es Trigonom�tricas\n");
		printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
		printf("[1] C�lculo de Cosseno\n");
		printf("[2] C�lculo de Seno\n");
		printf("[3] C�lculo de Tangente\n");
		printf("[4] C�lculo de Cossencante\n");
		printf("[5] C�lculo de Secante\n");
		printf("[6] C�lculo de Cotangente\n");
		printf("-=-=-=-=-=-=-=-=-=-=-=-=-\n");
		printf("\nDigite o n�mero correspondente � fun��o desejada, caso deseje sair, digite qualquer outro valor: ");

		scanf("%d", &codigo);
		
		continua = verificaCodigo(codigo);
	} while (continua);
}

int main() {
	setlocale(LC_ALL, "Portuguese");

	printMenu();
}
