#include <stdio.h>

int divisao_segura(int dividendo, int divisor) {
	int ret; //variável para retorno
	
	if(divisor == 0)
		ret = 0; //se o divisor é zero, não posso fazer a divisão
	else
		ret = dividendo / divisor; //senão, posso dividir com segurança
	return ret; //retorno a variável com a resposta
}

int main() {
	printf("O resultado eh: %d", divisao_segura(5,2)); //testando a função
	getch();
	return 0;
}
