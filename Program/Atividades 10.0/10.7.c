#include <stdio.h>
#include <locale.h>

void main() {
	setlocale (LC_ALL, "portuguese");
	int c, i, cont=0, media=0, altura;
	
	printf("Quantos alunos a classe possui? ");
	scanf("%d", &c);
	for (i=0; i<c; i++) {
		printf("Altura do %d° aluno (em cm): ", i+1);
		scanf("%d", &altura);
		media += altura;
		if (altura >= 160 && altura <= 175)
			cont++;
	}
	printf("A altura média da turma é %.2f\n", (float)media / c);
	printf("Na turma há %d aluno(s) entre 160 e 175 cm", cont);
}
