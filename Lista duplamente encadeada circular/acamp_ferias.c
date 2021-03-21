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
CRIANCA* entrada_dados (void);                       	  	            // lê dados de entrada
void vencedor          ( CRIANCA** l, int qtd );                        // realiza a lógica para determinar o vencedor
void imprime_lista     ( CRIANCA *aux );           				   	    // visualiza lista em tela
void exclui_nodo       ( CRIANCA **l ,CRIANCA *aux);   			  	    // exclui regitro pela referencia


int main(void){
	
	CRIANCA *lista_vencedores = NULL;                   // inicialização da lista para guardar os vencedores
	
	int qtd, i;
	
	do {
		scanf("%d", &qtd);                              // guarda o numero de crianças
		if (qtd == 0){                                  // se o usuario digitar 0 ele vai imprimir os vencedores
			imprime_lista(lista_vencedores);
		}
		else {                                          // se não
			CRIANCA *l = NULL;                          // cria uma lista para serem colocadas as crianças
			for (i=0; i<qtd; i++){                      // ocorre x vezes de acordo com a quantidade informada
				CRIANCA *crianca;                       // criação do nodo
				crianca = entrada_dados();              // entrada de dados no nodo crianca
				inclui_fim( &l, &crianca );             // inclusão da criança na lista
			}
			vencedor(&l, qtd);                          // chamada da função vencedor para determinar a criança vencedora
			inclui_fim( &lista_vencedores, &l );        // inclusão da criança vencedora na lista_vencedores
		}
		}while (qtd != 0);                              // vai ser executado enquanto o usuario não informar o 0 para imprimir lista

	return 0;
}

void inclui_fim( CRIANCA **l, CRIANCA **no ) {           // função para inclusão no fim da lista

	if((*l) != NULL){                                    // enquanto a lista for diferente de null, no caso se ñ for o primeiro elemento
		(*no)->ant = (*l)->ant;                          // o anterior do novo elemento recebe o anterior do primeiro da lista
		(*no)->prox = (*l);                              // o prox do novo elemento recebe o primeiro da lista
		(*l)->ant->prox = (*no);                         // o antigo ultimo da lista recebe o novo elemento
		(*l)->ant = (*no);	                             // o anterior do primeiro da lista recebe o novo elemento
	}
	else{                                                // se for o primeiro elemento a ser inserido
		(*no)->prox = (*no);                             // o prox do novo elemento recebe ele mesmo
		(*no)->ant = (*no);                              // o anteriror do novo elemento recebe ele mesmo
		(*l) = (*no);                                    // o começo da lista fica apontada para ele
	}
}

CRIANCA* entrada_dados(void){ // função para entrada de dados

	CRIANCA *aux = ( CRIANCA * ) malloc ( sizeof( CRIANCA )); // aloca espaço na memoria
	
	scanf("%s %d", &aux->info.nome, &aux->info.codigo);       // guarda o nome e o valor informado pelo usuario
	fflush( stdin );                                          // limpar o buffer do teclado
  
    aux->prox = aux;       // circular, registro aponta para ele mesmo 
    aux->ant  = aux;       // circular, registro aponta para ele mesmo
    
    return (aux);          // retorna aux (criança)
}

void vencedor( CRIANCA **l, int qtd ) {       // função para determinar entre o grupo de crianças quem foi a vencedora

	int i, k;                                // variaveis para uso no for
	CRIANCA *aux = *l;                       // nodo auxiliar para percorrer a lista
	int cod = aux->info.codigo;              // variavel inteiro cod para guardar o numero de cada criança
	
	// lógica para determinar a criança vencedora de cada grupo (par = horario, impar = antihorario)
	for (k=0; k<(qtd-1); k++) {

		if(((cod) % 2) == 0){          // se for par ...
			aux = aux->ant;            // começa na criança ao lado
			for(i=0; i<(cod-1); i++)   // vai andar na lista determinadas vezes de acordo com (cod-1)
				aux = aux->ant;        // percorre a lista no sentido horário
		}
		else{                          // se for ímpar ...
			aux = aux->prox;           //começa na criança ao lado
			for(i=0; i<(cod-1); i++)   // vai andar na lista determinadas vezes de acordo com (cod-1)
				aux = aux->prox;       // percorre a lista no sentido anti horário
		}
		cod = aux->info.codigo;        // recebe o numero da criança excluida e entra no loop novamente
		exclui_nodo(l, aux);           // exclusão da criança
	}
}

void exclui_nodo( CRIANCA **l ,CRIANCA *aux) {   // função para exclusão do elemento
    
    if( *l == aux ){                             // se for o primeiro...  
		(*l)->ant->prox = (*l)->prox;            // ultimo registro aponta para o posterior do primeiro (lembrar que é lista circular)
        (*l)->prox->ant = (*l)->ant;             // segundo registro aponta para o último (lembrar que é lista circular)
        if( (*l)->prox != *l )                   // se não for o único da lista
			*l = (*l)->prox;                     // *l aponta para o segundo registro da lista 
	    else  
            *l = NULL;                           // *l será NULL, pois o único registro será excluído        
        }else{                                   // se não for o primeiro...  
            aux->ant->prox = aux->prox;          // o registro anterior a no, aponta para um registro posterior a no (para onde no está apontando) 
            aux->prox->ant = aux->ant;           // o registro posterior a no, aponta para um registro anterior a no (para onde no está apontando) 
        }    
        free( aux );                             // libera espaço na memoria
}

void imprime_lista( CRIANCA *aux ){ 	// função para imprimir lista
    
	CRIANCA *inicio= aux;       	   // ponteiro auxiliar para percorrer a lista
    
	do{
        printf( "Vencedor(a): %s\n", aux->info.nome );
        aux = aux->prox;  								// aponta para o próximo registro da lista
    }while( aux != inicio ); 						    // fim while( aux != inicio )    
}

