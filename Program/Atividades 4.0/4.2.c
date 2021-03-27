#include <stdio.h>

//Dupla: Eduardo Bastos e Victor Kist

float calcCircunferenciaCirculo() {
	float raio;
	
	printf("Digite o valor do raio: ");
	scanf("%f", &raio);

	return 2 * 3.14 * raio;
}

float calcAreaCirculo() {
	float raio;
	
	printf("Digite o valor do raio: ");
	scanf("%f", &raio);
	return 3.14 * raio * raio;
}

float calcAreaSuperficieEsfera() {
	float raio;
	
	raio = calcAreaCirculo();

	return 4 * raio;
}

float calcVolumeEsfera(){
	float raio;
	
	printf("Digite o valor do raio: ");
	scanf("%f", &raio);
	return 4 * 3.14 * raio * raio * raio / 3;
}

float calcAreaSuperficieCilindro() {
	float raio, altura, areaBase, areaLateral;

	printf("Digite o valor do raio: ");
	scanf("%f", &raio);
	areaBase = 2 * 3.14 * raio * 2;

	printf("Digite o valor da altura: ");
	scanf("%f", &altura);
	areaLateral = 2 * 3.14 * raio * altura;

	return areaBase + areaLateral;
}

float calcVolumeCilindro() {
	float raio, altura;

	raio = calcAreaCirculo();
	printf("Digite o valor da altura: ");
	scanf("%f", &altura);
	
	return raio * altura;
}

int main() {
	int operacao;
	float resultado = 0;

	printf("\n----Bem vindo a calculadora geometrica----\n");
	printf("Escolha uma opcao:\n");
	printf("1 - Comprimento da circunferencia\n");
	printf("2 - Area do circulo\n");
	printf("3 - Area da superficie da esfera\n");
	printf("4 - Volume da esfera\n");
	printf("5 - Area da superficie do cilindro\n");
	printf("6 - Volume do cilindro\n");
	printf("------------------------------------------\n");
	scanf("%d", &operacao);

	switch(operacao) {//ESCOLHA
		case 1:
			resultado = calcCircunferenciaCirculo();//chamada da função
			break;
		case 2:
			resultado = calcAreaCirculo();
			break;
		case 3:
			resultado = calcAreaSuperficieEsfera();
			break;
		case 4:
			resultado = calcVolumeEsfera();
			break;
		case 5:
			resultado = calcAreaSuperficieCilindro();
			break;
		case 6:
			resultado = calcVolumeCilindro();
			break;
		deafult: 
			printf("\nOpcao invalida.");
			break;		
	}
	
	printf("\nO resultado da conta equivale a: %.2f", resultado);

	return 0;
}
