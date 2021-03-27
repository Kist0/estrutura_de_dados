#include <stdio.h>
#include <string.h>

void main()
{
	int nrLinha = 3, nrColuna = 3, num = 8;  //Mudar para testes
	int matriz[nrLinha][nrColuna, i, j];

	for (i = 0; i < nrLinha; i++)
	{
		printf("Digite os valores para a %d linha:\n", i+1);
		for (j = 0; j < nrColuna; j++)
		{
			printf("Digite o valor correspondente a %d coluna: ", j+1);
			scanf("%d", &matriz[i][j]);
		}
	}

	for (i = 0; i < nrLinha; i++)
	{
		for (j = 0; j < nrColuna; j++)
		{
			printf("%d ", matriz[i][j]);
		}

		printf("\n");
	}

	mediaValores (num, nrLinha, nrColuna, matriz);
}

int mediaValores (int num, int nrLinha, int nrColuna, int matriz[nrLinha][nrColuna]) {
	int cont=0, soma=0, i, j, contNumMaior=0;

	for (i = 0; i < nrLinha; i++) {
		for (j = 0; j < nrColuna; j++) {
				soma += matriz[i][j];  			//somar todos os valores fornecidos
				cont++;  						//fazer a m�dia entre os valores
				if (matriz[i][j] > num)  		//informar quantos valores s�o maiores que determinado n�mero (informado pelo usu�rio)
					contNumMaior++;
		}
	}

	printf("A m�dia dos valores � %.2f\nExistem %d n�meros maiores que %d", (float)soma/cont, contNumMaior, num);
}
