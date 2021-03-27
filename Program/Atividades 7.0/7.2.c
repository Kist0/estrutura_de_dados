/* Prof. Ivan L. Suptitz (09/10/2020)
Exerc?cio 7.1: Deselvolver as fun??es necess?rias para o funcionamento do programa.
Observe que est?o declarados somente os prot?tipos
Deve ser desenhado um ret?ngulo usando os caracteres de contorno da tabela ASCII Extendida
https://theasciicode.com.ar/

Dica: a fun??o strlen() retorna o comprimento de uma string

Exerc?cio 7.2: Adicione mais um prot?tipo e implemente a fun??o para:
imprimir todos os caracteres da tabela ASCII acompanhado do seu c?digo. Ex:
...
65 A
66 B
...
*/

#include <stdio.h>
#include <string.h>

void caractere();//prot?tipos

void main(){
	caractere();
	
}

void caractere() {
	int i;
	
	for (i=0; i<=255; i++) {
		printf("%d - ", i);
		printf("%c\n", i);
	}
}
