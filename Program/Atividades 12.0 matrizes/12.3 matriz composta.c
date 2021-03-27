#include <stdio.h>

void main()
{
	int nrLinha, nrColuna;
	int i, j;

	printf("Insira o número de linhas e o número de colunas: ");
	scanf("%d %d", &nrLinha, &nrColuna);
	int matriz[nrLinha][nrColuna], transposta[nrColuna][nrLinha];

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

	for (i = 0; i < nrLinha; i++)
	{
		for (j = 0; j < nrColuna; j++)
		{
			transposta[j][i] = matriz[i][j];
		}
	}

	for (i = 0; i < nrColuna; i++)
	{
		for (j = 0; j < nrLinha; j++)
		{
			printf("%d ", transposta[i][j]);
		}

		printf("\n");
	}
}
