#include <stdio.h>
#include <locale.h>

void main() {
	setlocale(LC_ALL, "Portuguese");
	int x, i;
	
	printf("De quantos alunos voc� deseja coletar notas? ");
	scanf("%d", &x);
	float notasAlunos[x];
	printf("Digite a nota dos alunos (enter ap�s cada n�mero): ");
		
	for (i=0; i<x; i++) {
		scanf("%f", &notasAlunos[i]);
		fflush(stdin);
	}
	
	for (i=0; i<x; i++) {
		if (notasAlunos[i] >= 10)
			printf("A nota do %d� aluno � %.1f, Parab�ns\n", i+1, notasAlunos[i]);
		else
			printf("A nota do %d� aluno � %.1f\n", i+1, notasAlunos[i]);
	}
			
}
