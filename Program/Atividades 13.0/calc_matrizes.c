#include <stdio.h>

#define MAX_L 100//constante com o número máximo de Linhas
#define MAX_C 100//                              de colunas

void somar_matriz(int a[MAX_L][MAX_C], int b[MAX_L][MAX_C], int c[MAX_L][MAX_C], int linhas, int colunas){
	int i, j;
	
	for(i=0; i<linhas; i++)
	{
		for(j=0; j<colunas; j++)
		{
			c[i][j] = a[i][j] + b[i][j];
		}
	}
}

void matriz_oposta(int a[MAX_L][MAX_C], int c[MAX_L][MAX_C], int linhas, int colunas)
{
	int i, j;
	
	for(i=0; i<linhas; i++)
	{
		for(j=0; j<colunas; j++)
		{
			//ex: se a[0][0] = 5 entao c[0][0] = -5
			//se a[0][1] = -2 entao c[0][1] = 2
			c[i][j] = a[i][j] * (-1);
		}
	}	
}

void matriz_transposta(int a[MAX_L][MAX_C], int c[MAX_L][MAX_C], int linhas, int colunas)
{
	int i, j;
	
	for(i=0; i <linhas; i++)
		for(j=0; j<colunas; j++)
			c[j][i] = a[i][j];
			
}

void imprimir_matriz(int m[MAX_L][MAX_C], int linhas, int colunas)
{
	int i, j;
	
	for(i=0; i<linhas; i++){
		for(j=0; j<colunas; j++){
			printf("%d\t", m[i][j]);
		}
		printf("\n");
	}
}

void informar_matriz(int m[MAX_L][MAX_C], int l, int c)
{
  int i, j;
  for(i=0; i<l; i++){
    for(j=0; j<c; j++){
      printf("Informe valores da matriz[%d][%d]: ", i, j);
      scanf("%d", &m[i][j]);
    }
    printf("\n"); 
  }
}

void main(){
	int opcao=1;
	int a[MAX_L][MAX_C], b[MAX_L][MAX_C], c[MAX_L][MAX_C];
	int la, ca, lb, cb, lc, cc;
	
	while(opcao !=0 )
	{	
		printf("\n	MENU\n");
		printf("0 - Sair\n");
		printf("1 - Informar matriz A\n");
		printf("2 - Informar matriz B\n");
		printf("3 - Imprimir matriz A\n");
		printf("4 - Imprimir matriz B\n");
		printf("5 - Imprimir matriz C\n");
		printf("6 - Somar matrizes\n");
		printf("7 - Multiplicar matrizes\n");
		printf("8 - Matriz oposta\n");
		printf("9 - Matriz transposta\n");
		scanf("%d", &opcao);
		
		switch (opcao){
			case 1:
			    printf("\nInforme a quantidade de linhas e colunas da matriz A: ");
			    scanf("%d %d", &la, &ca);				
				informar_matriz(a, la, ca);
				break;
				
			case 2:			
			    printf("\nInforme a quantidade de linhas e colunas da matriz B: ");
			    scanf("%d %d", &lb, &cb);				
				informar_matriz(b, lb, cb);
				break;
				
			case 3:
				imprimir_matriz(a, la, ca);
				break;
				
			case 4:
				imprimir_matriz(b, lb, cb);
				break;
				
			case 5:
				imprimir_matriz(c, lc, cc);
				break;
				
			case 6:
				if(la!=lb || ca!=cb)
					printf("As matrizes A e B devem ter o mesmo num de linhas e colunas!\n");
				else
				{
					somar_matriz(a, b, c, la, ca);
					lc = la;//a matriz C tera o mesmo numero de linhas e colunas de A e de B
					cc = ca;
					printf("Matrizes somadas com sucesso (em C)\n");
				}				
				break;
				
			case 7:
				//mult_matriz;
				break;
				
			case 8:
				matriz_oposta(a, c, la, ca);
				lc = la;//a matriz C tera o mesmo numero de linhas e colunas de A
				cc = ca;			
				printf("Matriz oposta de A gerada com sucesso (em C)\n");	
				break;
				
			case 9:
				matriz_transposta(a, c, la, ca);
				lc = ca;//linhas de C = colunas de A
				cc = la;//colunas de C = linhas de A
				printf("Matriz transposta de A gerada com sucesso (em C)\n");
				break;
				
			case 0:
				printf("Programa encerrado!\n");
				exit(1);
				
			default:
				printf("Opcao invalida!");
				break;
		}
	}
}
