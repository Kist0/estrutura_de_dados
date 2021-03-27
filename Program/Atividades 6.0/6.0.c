#include <stdio.h>
#include <locale.h>
#include <math.h>

float calculaMedia(float vet[], int tamanho) {
	int i, contador;
	float somatorio, media;
	
	somatorio=0; //inicializar as vari�veis
	contador=0;
	for(i=0; i<tamanho; i++) {
		somatorio += vet[i]; //mesmo que somatario = somatrio + vet[i];
		contador++; //mesmo que contador = contador + 1;
	}
	media = somatorio / contador;
	return media; //retorna para a main
}

int contaPrecosAltos(float vet[], int tamanho, float media) {
	int contador, i;
	
	contador=0; //resetei a vari�vel
	for(i=0; i<11; i++) {
		if(vet[i] > media)
			contador++;
	}
	return contador; //retorna para main
}

/*6.1*/
float verificaMaiorValor(float vet[]) {
	float maiorValor;
	int i;
	
	for(i=0; i<11; i++) {
		if (i == 0)
			maiorValor = vet[0];
		if (vet[i] > maiorValor)
			maiorValor = vet[i];
	}
	return maiorValor;
}

/*6.2*/
int verificaValFracionado(float vet[]) {
	int contador, i;
	
	for (i=0; i<11; i++) {
		if (fmod(vet[i], 1) > 0)
			contador++;
	}
	return contador;
}

/*6.3*/
int verificaPosicao(float vet[]) {
	float verificador;
	int posicao, i;
	
	printf("Digite um valor para verifica��o: ");
	fflush(stdin);
	scanf("%f", &verificador);
	for (i=0; i<11; i++){
		if (vet[i] == verificador) {
			posicao = i;
			return posicao;
		}
	}
	return -1;
}

void trocaValores(float vet[]) {
	int posicao;
	float valor;
	
	printf("Digite a posi��o para trocar um valor: ");
	fflush(stdin);
	scanf("%d", &posicao);
	printf("Digite o valor desejado: ");
	fflush(stdin);
	scanf("%f", &valor);
	vet[posicao] = valor;
}

/*6.4*/
void main() {
	float vet[11] = {23.99, 44.89, 78.10, 12.10, 89.78, 100.00, 250.00, 38.80, 74.87, 11.54, 57.35};
	float somatorio, media, maiorValor;
	int contador, qtdValFracionado, posicao, op, rodar = 1;
		
	setlocale(LC_ALL, "portuguese");
	
	while(rodar == 1){
        printf( "\n /------------------------------------------/" );
        printf( "\n Programa calculos - Menu					" );
        printf( "\n [1 ]  M�dia de valores						" );
        printf( "\n [2 ]  Quantidade de valores acima da m�dia	" );
        printf( "\n [3 ]  Maior valor do vetor					" );
        printf( "\n [4 ]  Quantidade de valores fracionados		" );
        printf( "\n [5 ]  Verificar posi��o						" );
        printf( "\n [6 ]  Troca de valores						" );
        printf( "\n [0 ]  Para sair do programa					" );
        printf( "\nValores atuais: %.2f, %.2f, %.2f, %.2f, %.2f", vet[0], vet[1], vet[2], vet[3], vet[4]);
        printf( "\n%.2f, %.2f, %.2f, %.2f, %.2f, %.2f", vet[5], vet[6], vet[7], vet[8], vet[9], vet[10], vet[11]);
        printf( "\n /------------------------------------------/" );      
        printf( "\n Op��o: " );
        fflush( stdin );
        scanf("%d", &op);
        
		switch( op ) {
            case 1:      
                media = calculaMedia(vet, 11);
				printf("A media �: %.2f\n", media);
                break;
                                        
            case 2:
                contador = contaPrecosAltos(vet, 11, media);
				printf("Tenho %d precos acima da media\n", contador); 
                break;
                
            case 3:
                maiorValor = verificaMaiorValor(vet);
				printf("O maior valor � %.2f\n", maiorValor);
                break;
                        
            case 4:
                qtdValFracionado = verificaValFracionado(vet);
				printf("Temos %d elementos com valor fracionado\n", qtdValFracionado);
                break;
                        
            case 5:
                posicao = verificaPosicao(vet);
                if (posicao == -1)
                	printf("Valor n�o encontrado");
                else
					printf("Este valor encontra-se na posi��o %d\n", posicao);
                break;

            case 6:
                trocaValores(vet);
                break;
								                                                                 
            case 0:                                  
                rodar = 0; 
                break;
                        
            default : 
            	printf( "\n Op��o n�o encontrada!" );
            	printf( "\n Digite uma op��o!" );
                break;
        }

        printf("\n");
        getchar();       // parada da tela
        /*system( "cls" ); // limpar tela*/
    }
}
