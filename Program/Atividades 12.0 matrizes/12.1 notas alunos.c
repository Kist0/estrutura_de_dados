#include <stdio.h>
#include <locale.h>

void main() {
	int qtd, i, j;
	float media;
	
	setlocale(LC_ALL, "portuguese");
	
	printf("Quantos alunos possui a classe? ");
	scanf("%d", &qtd);
	float notas[qtd][4];
	
	for (i=0; i<qtd; i++) {
		printf("Nota do %d° aluno\n", i+1);
		for (j=0; j<4; j++) {
			scanf("%f", &notas[i][j]);
			fflush(stdin);
		}
	}
	
	for (i=0; i<qtd; i++) {
		media=0;
		for (j=0; j<4; j++)
			media += notas[i][j];
		printf("A média do %d° aluno é %.2f\n", i+1, media/4);
	}
}
