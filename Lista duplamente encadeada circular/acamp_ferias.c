#include <stdio.h>
#include <stdlib.h>

typedef struct{             
       int  codigo;
       char nome[30];
}INFORMACAO;

typedef struct nodo {
       INFORMACAO info;     
       struct nodo* prox;   
       struct nodo* ant;    
}CRIANCA;

void inclui_fim        ( CRIANCA **l, CRIANCA **no );               	// inclui novo registro no final da lista
CRIANCA* entrada_dados (void);                       	  	            // l� dados de entrada
void vencedor          ( CRIANCA** l, int qtd );                        // realiza a l�gica para determinar o vencedor
void imprime_lista     ( CRIANCA *aux );           				   	    // visualiza lista em tela
void exclui_nodo       ( CRIANCA **l ,CRIANCA *aux);   			  	    // exclui regitro pela referencia


int main(void){
	
	CRIANCA *lista_vencedores = NULL;                   // inicializa��o da lista para guardar os vencedores
	
	int qtd, i;
	
	do {
		scanf("%d", &qtd);                              // guarda o numero de crian�as
		if (qtd == 0){                                  // se o usuario digitar 0 ele vai imprimir os vencedores
			imprime_lista(lista_vencedores);
		}
		else {                                          // se n�o
			CRIANCA *l = NULL;                          // cria uma lista para serem colocadas as crian�as
			for (i=0; i<qtd; i++){                      // ocorre x vezes de acordo com a quantidade informada
				CRIANCA *crianca;                       // cria��o do nodo
				crianca = entrada_dados();              // entrada de dados no nodo crianca
				inclui_fim( &l, &crianca );             // inclus�o da crian�a na lista
			}
			vencedor(&l, qtd);                          // chamada da fun��o vencedor para determinar a crian�a vencedora
			inclui_fim( &lista_vencedores, &l );        // inclus�o da crian�a vencedora na lista_vencedores
		}
		}while (qtd != 0);                              // vai ser executado enquanto o usuario n�o informar o 0 para imprimir lista

	return 0;
}

void inclui_fim( CRIANCA **l, CRIANCA **no ) {           // fun��o para inclus�o no fim da lista

	if((*l) != NULL){                                    // enquanto a lista for diferente de null, no caso se � for o primeiro elemento
		(*no)->ant = (*l)->ant;                          // o anterior do novo elemento recebe o anterior do primeiro da lista
		(*no)->prox = (*l);                              // o prox do novo elemento recebe o primeiro da lista
		(*l)->ant->prox = (*no);                         // o antigo ultimo da lista recebe o novo elemento
		(*l)->ant = (*no);	                             // o anterior do primeiro da lista recebe o novo elemento
	}
	else{                                                // se for o primeiro elemento a ser inserido
		(*no)->prox = (*no);                             // o prox do novo elemento recebe ele mesmo
		(*no)->ant = (*no);                              // o anteriror do novo elemento recebe ele mesmo
		(*l) = (*no);                                    // o come�o da lista fica apontada para ele
	}
}

CRIANCA* entrada_dados(void){ // fun��o para entrada de dados

	CRIANCA *aux = ( CRIANCA * ) malloc ( sizeof( CRIANCA )); // aloca espa�o na memoria
	
	scanf("%s %d", &aux->info.nome, &aux->info.codigo);       // guarda o nome e o valor informado pelo usuario
	fflush( stdin );                                          // limpar o buffer do teclado
  
    aux->prox = aux;       // circular, registro aponta para ele mesmo 
    aux->ant  = aux;       // circular, registro aponta para ele mesmo
    
    return (aux);          // retorna aux (crian�a)
}

void vencedor( CRIANCA **l, int qtd ) {       // fun��o para determinar entre o grupo de crian�as quem foi a vencedora

	int i, k;                                // variaveis para uso no for
	CRIANCA *aux = *l;                       // nodo auxiliar para percorrer a lista
	int cod = aux->info.codigo;              // variavel inteiro cod para guardar o numero de cada crian�a
	
	// l�gica para determinar a crian�a vencedora de cada grupo (par = horario, impar = antihorario)
	for (k=0; k<(qtd-1); k++) {

		if(((cod) % 2) == 0){          // se for par ...
			aux = aux->ant;            // come�a na crian�a ao lado
			for(i=0; i<(cod-1); i++)   // vai andar na lista determinadas vezes de acordo com (cod-1)
				aux = aux->ant;        // percorre a lista no sentido hor�rio
		}
		else{                          // se for �mpar ...
			aux = aux->prox;           //come�a na crian�a ao lado
			for(i=0; i<(cod-1); i++)   // vai andar na lista determinadas vezes de acordo com (cod-1)
				aux = aux->prox;       // percorre a lista no sentido anti hor�rio
		}
		cod = aux->info.codigo;        // recebe o numero da crian�a excluida e entra no loop novamente
		exclui_nodo(l, aux);           // exclus�o da crian�a
	}
}

void exclui_nodo( CRIANCA **l ,CRIANCA *aux) {   // fun��o para exclus�o do elemento
    
    if( *l == aux ){                             // se for o primeiro...  
		(*l)->ant->prox = (*l)->prox;            // ultimo registro aponta para o posterior do primeiro (lembrar que � lista circular)
        (*l)->prox->ant = (*l)->ant;             // segundo registro aponta para o �ltimo (lembrar que � lista circular)
        if( (*l)->prox != *l )                   // se n�o for o �nico da lista
			*l = (*l)->prox;                     // *l aponta para o segundo registro da lista 
	    else  
            *l = NULL;                           // *l ser� NULL, pois o �nico registro ser� exclu�do        
        }else{                                   // se n�o for o primeiro...  
            aux->ant->prox = aux->prox;          // o registro anterior a no, aponta para um registro posterior a no (para onde no est� apontando) 
            aux->prox->ant = aux->ant;           // o registro posterior a no, aponta para um registro anterior a no (para onde no est� apontando) 
        }    
        free( aux );                             // libera espa�o na memoria
}

void imprime_lista( CRIANCA *aux ){ 	// fun��o para imprimir lista
    
	CRIANCA *inicio= aux;       	   // ponteiro auxiliar para percorrer a lista
    
	do{
        printf( "Vencedor(a): %s\n", aux->info.nome );
        aux = aux->prox;  								// aponta para o pr�ximo registro da lista
    }while( aux != inicio ); 						    // fim while( aux != inicio )    
}

