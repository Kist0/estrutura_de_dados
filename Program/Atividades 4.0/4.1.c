#include <stdio.h>

int divisao_segura(int dividendo, int divisor) {
	int ret; //vari�vel para retorno
	
	if(divisor == 0)
		ret = 0; //se o divisor � zero, n�o posso fazer a divis�o
	else
		ret = dividendo / divisor; //sen�o, posso dividir com seguran�a
	return ret; //retorno a vari�vel com a resposta
}

int main() {
	printf("O resultado eh: %d", divisao_segura(5,2)); //testando a fun��o
	getch();
	return 0;
}
