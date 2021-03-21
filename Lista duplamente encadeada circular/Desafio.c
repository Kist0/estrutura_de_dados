#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h> 

typedef struct{             // registro pessoa
       int  codigo;
       char nome[30];
}INFORMACAO;
       
typedef struct nodo {
       INFORMACAO info;     // dados do registro
       struct nodo* prox;   // ponteiro para o próximo registro
       struct nodo* ant;    // ponteiro para o registro anterior
}NODO; 

void entrada_dados( NODO* aux );           // lê dados de entrada
void inclui_fim( NODO** l );               // inclui novo registro no final da lista
void vencedor( NODO** l );                 
void imprime_lista( NODO *aux );           // visualiza lista em tela
void cria_lista( NODO **l );               // inicializa lista com NULL
void exclui_nodo( NODO **l, NODO *aux );      // exclui regitro pela referencia


int main(void){
	
	int qtd, i;

	NODO* l;
    setlocale(LC_ALL, "Portuguese");
	cria_lista(&l);
	
			do {
				scanf("%d", &qtd);
				if (qtd == 999) 		//teste
					imprime_lista(l);	//teste
				else if (qtd == 0)
					printf("terminou :)");
				else {
					for (i=0; i<qtd; i++)
						inclui_fim( &l );
					}
				vencedor(&l);
			}while (qtd != 0);
		

    
    return 0;
}
//vencedor(&l);


void entrada_dados( NODO *aux ){      // função para entrada de dados

	fflush( stdin );                                         // limpar o buffer do teclado
	scanf("%s %d", &aux->info.nome, &aux->info.codigo);      // guarda o nome e o valor informado pelo usuario
  
    aux->prox= aux;       // circular, registro aponta para ele mesmo 
    aux->ant = aux;       // circular, registro aponta para ele mesmo 
}


void inclui_fim( NODO **l ){     // função para inclusão no fim da lista
	
	NODO* no = ( NODO * ) malloc ( sizeof( NODO ));    // alocação na memória
	entrada_dados( no );                               // entrada de dados no ponteiro no
	if(*l != NULL){                                    // enquanto a lista for diferente de null, no caso se ñ for o primeiro elemento
		no->ant = (*l)->ant;                           // o anterior do novo elemento recebe o anterior do primeiro da lista
		no->prox = *l;                                 // o prox do novo elemento recebe o primeiro da lista
		(*l)->ant->prox = no;                          // o antigo ultimo da lista recebe o novo elemento
		(*l)->ant = no;	                               // o anterior do primeiro da lista recebe o novo elemento
	}
	else{                                              // se for o primeiro elemento a ser inserido
		no->prox = no;                                 // o prox do novo elemento recebe ele mesmo
		no->ant = no;                                  // o anteriror do novo elemento recebe ele mesmo
		*l = no;                                       // o começo da lista fica apontada para ele
	}
}


void vencedor( NODO **l ) {  // função para determinar entre o grupo de crianças quem foi a vencedora
	
	int i;

	// par = horario
	// impar = antihorario

	NODO *aux = *l;
	int cod = aux->info.codigo;
	exclui_nodo(&l, aux);
/*	while(aux->prox != aux && aux->ant != aux) { // loop para percorrer a lista até que sobre apenas um elemento

		if(aux->info.codigo % 2 == 0){
			aux = aux->ant;
			for(i=1; i=cod; i++)
				aux = aux->ant;
		}
		else{
			aux = aux->prox;
			for(i=0; i=cod; i++)
				aux = aux->prox;
		}
		int cod = aux->info.codigo;
		if(aux->info.codigo % 2 == 0)
			aux = aux->ant;
		else
			aux = aux->prox;
		
	}*/

}


void exclui_nodo( NODO **l, NODO *aux ) {    // função para exclusão do elemento
    
    if( *l == aux ) {
		(*l)->ant->prox = (*l)->prox;
        (*l)->prox->ant = (*l)->ant;
        if( (*l)->prox != *l )
			*l = (*l)->prox;
	    else
            *l = NULL;
    }
	else{
        aux->ant->prox = aux->prox;
        aux->prox->ant = aux->ant;
    }
    free( aux );
}


void imprime_lista( NODO *aux ){  // função para imprimir lista
	int i= 0;                     // indica número de registro na lista
		 	 
    if( aux == NULL )             // verifica se lista vazia
        printf( "\n Lista vazia!" );
	else{
	     printf("\n Relatório Geral ----------------------------------------- ");
         NODO *inicio= aux;       // ponteiro auxiliar para percorrer a lista
         do{                        
		 	    printf( "\n Registro[%d]", i );
                printf( "\t Código: %d", aux->info.codigo );
                printf( "\t Nome..: %s", aux->info.nome );
                
                aux = aux->prox;  // aponta para o próximo registro da lista
                i++;
         }while( aux != inicio ); // fim while( aux->prox != inicio )    
    } // fim if( aux == NULL )
}


void cria_lista( NODO **l ){         // função para criar lista
	 
    *l = NULL ;                      // lista criada, início nao aponta
}
