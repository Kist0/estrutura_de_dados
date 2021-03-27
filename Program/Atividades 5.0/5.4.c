#include <stdio.h>
#include <locale.h>

void main() {
	setlocale(LC_ALL, "Portuguese");
	int x, i;
	
	printf("De quantos alunos você deseja coletar notas? ");
	scanf("%d", &x);
	float notasAlunos[x];
	printf("Digite a nota dos alunos (enter após cada número): ");
		
	for (i=0; i<x; i++) {
		scanf("%f", &notasAlunos[i]);
		fflush(stdin);
	}
	
	for (i=0; i<x; i++) {
		if (notasAlunos[i] >= 10)
			printf("A nota do %d° aluno é %.1f, Parabéns\n", i+1, notasAlunos[i]);
		else
			printf("A nota do %d° aluno é %.1f\n", i+1, notasAlunos[i]);
	}
			
}
