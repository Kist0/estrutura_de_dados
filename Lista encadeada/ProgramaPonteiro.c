/***********************************************/ 
/* Lista Encadeada                             */
/* objetivo: cadastro de pessoas               */
/* programador: Daniela Bagatini               */
/* criado em: 01/04/2016                       */
/* data da ultima alteracao: 29/09/2020        */
/***********************************************/ 


#include <stdio.h>              // entrada e sa?da padr?o: printf, scanf
#include <stdlib.h>		// exit, malloc, system
#include <string.h>	        // strcmp
#include <locale.h>             // setlocale
//#include <ctype.h>            // toupper
//#include <conio.h>            // getch
//#include <time.h>             // rand   


// bibliotecas inclu?das, manter bibliotecas na mesma pasta do arquivo fonte
#include "MODELOENC.h"     // modelo de dados
#include "GERA_DADOSENC.h" // gera dados para povoar lista de forma autom?tica 

#define True 1             // constante True vale 1 


/***********************************************/ 
/* Defini??o das Fun??es                       */
/***********************************************/ 
void  entrada_dados  ( NODO *aux );           // l? dados de entrada
void  imprime_lista  ( NODO *aux );           // visualiza lista em tela
void  cria_lista     ( NODO **l );            // inicializa lista com NULL
void  destroi_lista  ( NODO **l );            // apaga lista e libera mem?ria
void  inclui_fim     ( NODO **l );            // inclui novo registro no final da lista
void  inclui_inicio  ( NODO **l );            // inclui novo registro no in?cio da lista
NODO *procura_nodo   ( NODO *l, int cod );    // procura na lista por uma c?digo
void  exclui_nodo    ( NODO **l );            // exclui regitro por c?digo 
void  ordena_lista   ( NODO **l );            // ordena lista por c?digo
void  inclui_ordenado( NODO **l );            // inclui registro na lista ordenado por c?digo
void  inverte        ( NODO **l );            // inverte refer?ncia dos registros
void  consulta_nome  ( NODO *l );             // consulta por nome
void  inserir_antes  ( NODO **l );            // insere registro antes de uma c?digo de refer?ncia
void  inserir_depois ( NODO **l );            // insere registro depois de uma c?digo de refer?ncia
void  conta_nodo     ( NODO **l );            // conta n?mero de registros existentes na lista
// crie sua pr?pria fun??o aqui!


/***********************************************/ 
/* Programa Principal                          */
/***********************************************/ 
int main( void ) {
        int op;                                   // op??o do menu                               
        NODO *l;                                  // declara??o da lista - ponteiro
        setlocale(LC_ALL, "Portuguese");	      // alterar idioma para portugu?s

        while( True ){
                printf( "\n /----------------------------------------------------/" );  // menu
                printf( "\n Programa registro - Menu                              " );
                printf( "\n [1 ]  Cria lista                                      " );
                printf( "\n [2 ]  Inclui registro no final da lista               " );
                printf( "\n [3 ]  Inclui registro no in?cio da lista              " );
                printf( "\n [4 ]  Exclui registro                                 " );
                printf( "\n [5 ]  Ordena lista                                    " );
                printf( "\n [6 ]  Inlcui ordenado                                 " );
                printf( "\n [7 ]  Inverte lista                                   " );         
                printf( "\n [8 ]  Consulta nome                                   " );         
                printf( "\n [9 ]  Inserir antes                                   " );           
                printf( "\n [10]  Inserir depois                                  " );     
                printf( "\n [11]  Conta registros                                 " );           
                printf( "\n [12]  Crie sua pr?pria fun??o aqui!                   " ); 
                printf( "\n [13]  Gera dados                                      " );  
                printf( "\n [14]  Destroi lista                                   " );
                printf( "\n [15]  Imprime lista                                   " );
				printf( "\n [0 ]  Para sair do programa                           " );
                printf( "\n /----------------------------------------------------/" );      
                printf( "\n Op??o: " );
                fflush( stdin );
                scanf("%d", &op); // tecla de op??o do menu
         
                switch( op ) {
                        case 1: // rotina cria lista       
                                cria_lista( &l );
                                break;
                                        
                        case 2:  // rotina inclui registro no final da lista
                                inclui_fim( &l );   
                                break;
                
                        case 3:  // rotina inclui registro no in?cio da lista
                                inclui_inicio( &l );
                                break;
                        
                        case 4:  // rotina exclui registro da lista
                                exclui_nodo( &l );
                                break;
                        
                        case 5:  // rotina ordena lista
                                ordena_lista( &l );
                                break;

                        case 6:  // rotina inclui ordenado
                                inclui_ordenado( &l );
                                break;
                                                                                        
                        case 7: // rotina inverte lista                 
                                inverte( &l ); 
                                break;                                
                
                        case 8: // rotina consultar por um nome                 
                                consulta_nome( l ); 
                                break;             

                        case 9: // rotina inserir antes de um c?digo                 
                                inserir_antes( &l ); 
                                break; 

                        case 10: // rotina inserir depois de um c?digo                 
                                inserir_depois( &l ); 
                                break; 
                                                                                
                        case 11: // rotina contar o n?mero de registros na lista                 
                                conta_nodo( &l ); 
                                break; 

                        case 12:                  
                                // crie sua pr?pria fun??o aqui! 
                                break;
                        
                        case 13: // rotina gera dados de forma autom?tica para povoar a lista
                                gera_dados( &l );
                                break;                    

                        case 14: // rotina destroi lista                 
                                destroi_lista( &l );     
                                break;    

                        case 15: // rotina imprime lista                 
                                imprime_lista( l );     
                                break;
                                                                                                        
                        case 0: // t?rmino do programa                                          
                                exit( True ); 
                                break;
                        
                        default : 
                                printf( "\n Digite uma op??o!" ); // n?o foi digitado uma op??o v?lida
                                break;
                } // fim switch( op )

                printf("\n");
                getchar();       // parada da tela
                system( "cls" ); // limpar tela
        } // fim do while( 1 )
        return 0;     
} // fim do programa principal



/************************************************ 
 * entrada_dados                                *
 * objetivo: rotina para ler dados              *
 * entrada : nodo (ponteiro para o novo espaco) *
 * saida   : nodo com dados                     *
 ************************************************/
void entrada_dados( NODO *aux ) {
      
        printf( "\n\n Digite a c?digo: " ); 
        fflush( stdin );                         // limpa buffer do teclado, funciona junto com entrada de dados
        scanf("%d", &aux->info.codigo);

        printf( "\n Digite o nome: " );
        fflush( stdin );     
        gets( aux->info.nome );
  
        aux->prox = NULL;                        // n?o aponta
}



/*************************************************
 * imprime_lista                                 *
 * objetivo: rotina para imprimir dados          *
 * entrada : lista                               *
 * saida   : nenhuma                             *
 *************************************************/     
void imprime_lista( NODO *aux ) {
     
        int i= 1;                       // indica n?mero de registro na lista
        
        if( aux == NULL )               // verifica se lista vazia
                printf( "\n Lista vazia!" );
	else {
                printf( "\n O endere?o (&l) onde a vari?vel lista est? na mem?ria ?: [%#p]", &aux ); 
		printf( "\n A vari?vel lista (l) aponta para o endere?o............: [%#p]", aux ); 
	        printf( "\n\n\n\n Relat?rio Geral ----------------------------------------- " );
                while( aux != NULL ){       // ponteiro auxiliar para percorrer a lista
                        printf( "\n\n Registro[%d] \t End: [%#p] \t Prox: [%#p]", i, aux, aux->prox );               
                        printf( "\n\t\t C?digo: %d", aux->info.codigo );
                        printf( "\t\t Nome.: %s", aux->info.nome );
                        aux = aux->prox;     // aponta para o pr?ximo registro da lista
                        i++;
	        }       // fim while( aux != NULL )
	}               // fim if( aux == NULL )
	getchar();      // parada da tela
}



/************************************************
 * cria_lista                                   *
 * objetivo: rotina para inicializar a lista    *
 * entrada : lista                              *
 * sa?da   : NULL (inicializa lista)            *
 ************************************************/ 
void cria_lista( NODO **l ) {

        *l = NULL;                                        // lista criada, in?cio n?o aponta
        printf( "\n Lista criada! " );
}



/************************************************ 
 * inclui_fim                                   *
 * objetivo: rotina para inserir no fim da lista*
 * entrada : lista                              *
 * saida   : lista com novo registro            *
 ************************************************/ 
void inclui_fim( NODO **l ) {
        NODO *no =  ( NODO * ) malloc ( sizeof( NODO ) ); // aloca novo espaco em mem?ria
        
        if( no != NULL ){                                 // verifica se conseguiu alocar mem?ria para o novo registro
                entrada_dados( no );

                if( *l == NULL )
                        *l = no;
                else{
                        NODO *p = *l;
                        while(p->prox != NULL)
                                p = p->prox;
                        p->prox = no;
                }
                printf("Registro inserido :)");
        }
        else
                printf("Lista cheia :(");
}



/*************************************************** 
 * inclui_inicio                                   *
 * objetivo: rotina para inserir no inicio da lista*
 * entrada : referencia de lista                   *
 * sa?da   : referencia lista com novo registro    *
 ***************************************************/ 
void inclui_inicio( NODO **l ) {
        NODO *no =  ( NODO * ) malloc ( sizeof( NODO ) ); // aloca novo espaco em mem?ria
        if( no != NULL ){                                 // verifica se conseguiu alocar mem?ria para o novo registro
                entrada_dados( no );                     // l? dados
                no->prox = *l;                           // novo aponta para o primeiro existente ou para Null
                *l = no;                                 // in?cio aponta para o novo registro
                printf( "\n Registro incluido!" );
        } // fim if( no != NULL )
        else
                printf( "\n Lista cheia!" );
}



/************************************************ 
 * procura_nodo                                 *
 * objetivo: achar um registro por c?digo       *
 * entrada : lista e c?digo a ser procurado     *
 * sa?da   : posi??o ou NULL (n?o encontrou)    *
 ************************************************/ 
NODO* procura_nodo( NODO *p, int cod ) {
        while( p != NULL ){                             // anda pela lista at? o final ou at? encontrar c?digo desejado
                if( p->info.codigo == cod ) {
                        return (p);                             
                }      
                p = p->prox;                // passa para o pr?ximo       
        }
        return (NULL); // nodo de refer?ncia
}


/*************************************************** 
 * exclui_nodo                                     *
 * objetivo: rotina para excluir nodo da lista     *
 * entrada : lista                                 *
 * sa?da   : lista                                 *
 ***************************************************/ 
void exclui_nodo( NODO **l ) {
        if (l != NULL){
                NODO *anterior = *l;
                NODO *atual = *l;
                while (atual->prox != NULL) {
                        anterior = atual;
                        atual = atual->prox;
                        if(atual->prox == NULL) {
                                anterior->prox = NULL;
                                atual = anterior;
                        }
                }
        }
        else
                printf( "\n Lista vazia!" );
}


/*************************************************** 
 * ordena_lista                                    *
 * objetivo: rotina para ordenar a lista           *
 * entrada : lista                                 *
 * sa?da   : lista ordenada por codigo             *
 ***************************************************/
void ordena_lista( NODO **l ) {
        NODO *atual = *l;

        if (atual != NULL) {
                NODO *proximo;
                INFORMACAO aux;

                while (atual->prox != NULL) {

                	proximo = atual->prox;

					while(proximo != NULL){

						if(atual->info.codigo > proximo->info.codigo){
							aux = atual->info;
							atual->info = proximo->info;
							proximo->info = aux;
						}

						proximo = proximo->prox;
					}

					atual = atual->prox;
				}
        }
}

/*
                        proximo = lista->prox;
                        menor = lista;

                        while(proximo != NULL) {
                                if(proximo->info.codigo > menor->info.codigo)
                                        menor = proximo;

                                proximo = proximo->prox;
                        }

                        if(proximo != lista) {
                                aux = lista->info;
                                lista->info = menor->info;
                                menor->info = aux;
                        }

                        lista = lista->prox;
                }*/

/*************************************************** 
 * inclui_ordenado                                 *
 * objetivo: rotina para inserir em ordem de codigo*
 * entrada : lista                                 *
 * sa?da   : lista com novo registro               *
 ***************************************************/ 
void inclui_ordenado( NODO **l ) {

}



/*************************************************** 
 * inverte referencia                              *
 * objetivo: rotina para inverter referencia do reg*
 * entrada : lista                                 *
 * saida   : lista com referencia invertida        *
 ***************************************************/ 
void inverte( NODO **l ) {
     

}



/*************************************************** 
 * consulta nome                                   *
 * objetivo: rotina para consultar                 *
 * entrada : lista                                 *
 * saida   : lista                                 *
 ***************************************************/
void consulta_nome( NODO *l ) {
        int codigo;

        printf("Digite o c?digo: ");
        scanf("%d", &codigo);

        NODO *consulta = procura_nodo( l, codigo );

        if(consulta != NULL) {
                printf( "End: [%#p] \t Prox: [%#p]", consulta, consulta->prox );               
                printf( "\n\t\t C?digo: %d", consulta->info.codigo );
                printf( "\t\t Nome.: %s", consulta->info.nome );
        }
        else
                printf("C?digo inv?lido :(");

        
        getchar();
}



/*************************************************** 
 * inserir antes                                   *
 * objetivo: rotina para inserir antes de uma matr *
 * entrada : lista                                 *
 * saida   : lista com novo registro               *
 ***************************************************/ 
void inserir_antes( NODO **l ) {

}



/*************************************************** 
 * inserir depois                                  *
 * objetivo: rotina para inserir antes de uma matr *
 * entrada : lista                                 *
 * saida   : lista com novo registro               *
 ***************************************************/ 
void inserir_depois( NODO **l ) {
        if (*l != NULL) {
                int codigo;

                printf("Digite o c?digo: ");
                scanf("%d", &codigo);

                NODO *referencia = procura_nodo( *l, codigo );

                if (referencia != NULL) {
                        NODO *no =  ( NODO * ) malloc ( sizeof( NODO ) ); // aloca novo espaco em mem?ria
                        if( no != NULL ) {
                                entrada_dados( no );

                                if(referencia->prox == NULL) 
                                        no->prox = NULL;
                                else
                                        no->prox = referencia->prox;

                                referencia->prox = no;
                        }
                        else
                                printf("Lista cheia :(");
                }
                else
                        printf("C?digo inv?lido :(");             
        }
        else
                printf("Lista vazia :(");
        getchar();
}


/*************************************************** 
 * conta_nodo                                      *
 * objetivo: rotina para contar numero de registros*
 * entrada : lista                                 *
 * saida   : nenhuma                               *
 **************************************************/ 
void conta_nodo( NODO **l ) {
     

}


/*************************************************
 * destroi_lista                                 *
 * objetivo: rotina para apagar lista            *
 * entrada : lista                               *
 * saida   : lista vazia                         *
 *************************************************/ 
void destroi_lista  ( NODO **l ) {
	  
        int i= 0;                      // indica n?mero de registro na lista
	 
        if( *l == NULL )               // verifica se lista vazia
                printf( "\n Lista vazia!" );
        else {
                NODO *aux = *l;
                while( aux != NULL ) {      // ponteiro auxiliar para percorrer a lista
                        printf( "\n Destroi Registro[%d]", i );
                        printf( "\t C?digo: %d", aux->info.codigo );
		        printf( "\t Nome.: %s", aux->info.nome );
		        *l = aux->prox;     // aponta para o pr?ximo registro da lista
                        free( aux );        // libera mem?ria
		        aux = *l;           // reposiciona ponteiro auxiliar no in?cio      
                        i++;
		} // fim while( aux != NULL )
	} // fim if( aux == NULL )
	getchar();                     // parada da tela
}



