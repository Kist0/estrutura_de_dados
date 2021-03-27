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
//#include <locale.h>

void linha_cima(int tam);//prot?tipos
void linha_meio(int tam, char conteudo[]);
void linha_baixo(int tam);

void main(){
	int t = 25;
	//setlocale(LC_ALL, "portuguese");     //se esta opção for "liberada" torna-ra os caracteres ASCII diferentes
	
	linha_cima(t);
	linha_meio(t, "os guri É Brabo");
	linha_baixo(t);
}

//implementa??o da fun??o
void linha_cima(int tam){
	int i;
	
	printf("%c", 201);
	for (i=0; i<tam; i++)
		printf("%c", 205);
	printf("%c\n", 187);
}

void linha_meio(int tam, char conteudo[]) {
	int i;
	
	printf("%c", 186);
	printf("%s", conteudo);
	for (i=0; i<tam - strlen(conteudo); i++)
		printf(" ");
	printf("%c\n", 186);
}

void linha_baixo(int tam){
	int i;	
	
	printf("%c", 200);
	for (i=0; i<tam; i++)
		printf("%c", 205);
	printf("%c\n", 188);
}
