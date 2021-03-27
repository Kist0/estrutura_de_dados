#include <stdio.h>
#include <math.h>
#include <locale.h>

float bhaskara(float a, float b, float c, int raiz){
	float x, delta;
	
	delta = pow(b,2) - 4 * a * c;
	if (delta < 0) {
		printf("Esta funcao n�o tem raizes reais!\n");	//return 0 foi adicionado para o caso de n�o haver raiz real, n�o realizar as contas
		return 0;										//e consequ�ntiemente n�o mostrar mensagens desnecess�rias
	}
	if(raiz == 1)										//foi adicionado um "=" para que a valida��o fosse feita
 		x = (-b + sqrt(delta)) / (2*a);
 	else
 		x = (-b - sqrt(delta)) / (2*a);
	return x; 											//foi colocado um ";" nesta linha
}

void main() {
	float a, b, c, x1, x2;

	setlocale (LC_ALL, "portuguese");
	printf("Digite o valor A, B e C em sequ�ncia\n");
	scanf("%f %f %f", &a, &b, &c);
	x1 = bhaskara (a, b, c, 1);
	if (x1 != 0) {
		x2 = bhaskara (a, b, c, 0);
		printf("\n\nx%' = %.2f\n"
			   "x%'%' = %.2f", x1, x2);
	}
}
