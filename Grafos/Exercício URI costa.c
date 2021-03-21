#include <stdio.h>

// Por Eduardo Bastos e Victor Kist

int main() { 
        int nrLinha, nrColuna; // Declaraçao de variáveis que definem o tamanho da matriz
        scanf("%d %d", &nrLinha, &nrColuna); // Entrada de dados do número de linhas e coluans

        char territorio[nrLinha][nrColuna]; // Declaração da matriz com o tamanho inserido anteriormente
        int i = 0, j = 0, count = 0; // Declaração das variáveis de controle e do contador para resposta final

        for (i = 0; i < nrLinha; i++) {  // Laço de repetição para pedir a entrada dos dados
                scanf("%s", &territorio[i]); // Entrada dos valores . e # na linha correspondente ao i
        }

        /* Imprimir a matriz (verificação)
        for (i = 0; i < nrLinha; i++) {  
		for (j = 0; j < nrColuna; j++) {
			printf("%c", territorio[i][j]);
		}
		printf("\n");
	}*/

        for (i = 0; i < nrLinha; i++) {  // Laço de repetição para percorrer as linhas da matriz
                for (j = 0; j < nrColuna; j++) { // Laço de repetição para percorrer as colunas da matriz
                        if (territorio[i][j] == '#') { // Verifica se o caracter é terra ou não, se não for, já não executa o resto
                                if(i == 0 || i == nrLinha - 1 || j == 0 || j == nrColuna - 1) // Caso o território esteja na borda (que foi definida como mar),
                                        count++;  // automaticamente é costa
                                else if (territorio[i + 1][j] == '.' || territorio[i - 1][j] == '.' || territorio[i][j - 1] == '.' || territorio[i][j + 1] == '.')  // Caso o caracter esteja rodeado por mar "."
                                        count++;  // conta-se mais uma costa
                        } 
                }
        }
                printf("%d\n", count);  // Saída proposta pelo exercício (\n é exigido tbm)

        return 0;  // return exigido pelo URI tbm
}  // fim função :)