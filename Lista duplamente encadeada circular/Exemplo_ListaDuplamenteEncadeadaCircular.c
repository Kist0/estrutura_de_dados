/***********************************************/ 
/* Lista Duplamente Encadeada                  */
/* objetivo: cadastro pessoas                  */
/* programador: Daniela Bagatini               */
/* criado em: 06/04/2018                       */
/* data da última alteração: 06/10/2019        */
/***********************************************/ 

#include <stdio.h>                            // entrada e saída padrão: printf, scanf
#include <stdlib.h>		                      // exit, malloc, system
#include <string.h>	  	                      // strcmp
#include <locale.h>                           // setlocale
//#include <ctype.h>                          // toupper
#include <conio.h>                            // getch
//#include <time.h>                           // rand  


// bibliotecas incluídas, manter bibliotecas na mesma pasta do arquivo fonte
#include "MODELODUPLA.h"                      // modelo de dados
#include "GERA_DADOSCIRCULAR.h"               // gera dados para povoar lista de forma automática 


/***********************************************/ 
/* Definição das Funções                       */
/***********************************************/
void  entrada_dados  ( NODO* aux );           // lê dados de entrada
void  imprime_lista  ( NODO* l );             // visualiza lista em tela
void  cria_lista     ( NODO** l );            // inicializa lista com NULL
void  destroi_lista  ( NODO* *l );            // apaga lista e libera memória
void  inclui_fim     ( NODO** l );            // inclui novo registro no final da lista
void  inclui_inicio  ( NODO** l );            // inclui novo registro no início da lista
NODO* procura_nodo   ( NODO* l, int cod );   // procura na lista por código
void  exclui_nodo    ( NODO** l );            // exclui regitro por código
void  ordena_lista   ( NODO** l );            // ordena lista por código
// crie sua própria função aqui!

       
/***********************************************/ 
/* Programa Principal                          */
/***********************************************/ 
int main( void ){
    int op;                                   // opção do menu                               
    NODO* l;                                  // declaração da lista, variável do tipo lista = lista de ponteiros
    setlocale(LC_ALL, "Portuguese");          // alterar idioma para português      

    while( 1 ){
         printf( "\n /---------------------------------------------------/" ); 
         printf( "\n Programa de registro - Menu                          " );
         printf( "\n [1] Cria lista                                       " );
         printf( "\n [2] Inclui registro no final da lista                " );
         printf( "\n [3] Inclui registro no início da lista               " );
         printf( "\n [4] Exclui registro                                  " );
         printf( "\n [5] Ordena lista                                     " );                           
         printf( "\n [6] Gera dados                                       " );
         printf( "\n [7] Destroi lista                                    " );		  
         printf( "\n [8] Imprime lista                                    " );
         printf( "\n [0] Para sair do programa                            " );
         printf( "\n /---------------------------------------------------/" );      
         printf( "\n Opção: " );
         fflush( stdin );   // limpa buffer do teclado, funciona antes da entrada de dados
         scanf( "%i", &op );// tecla de opção do menu

         switch( op ) {
            case 1: // rotina cria lista       
                    cria_lista( &l );
                    break;
                                                    
            case 2: // rotina inclui registro no final da lista
                    inclui_fim( &l );    
                    break;
          
            case 3: // rotina inclui registro no início da lista
                    inclui_inicio( &l );
                    break;                     
                
            case 4: // rotina exclui registro da lista
                    exclui_nodo( &l );
                    break;
                  
            case 5: // rotina ordena lista
                    ordena_lista( &l ); 
                    break;
                                                                                                                   
            case 6: // rotina imprime lista                 
                    gera_dados( &l ); 
                    break;

            case 7:  // rotina destroi lista                 
                    destroi_lista( &l );
                    break;                    

            case 8: // rotina imprime lista                 
                    imprime_lista( l ); 
                    break;
					                                
            case 0: // término do programa                                                 
                    exit( 1 ); 
                    break;
                
            default : 
                    printf( "\n Digite uma opção!" );
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
 * entrada : ponteiro para o novo espaco        *
 * saida   : dados armazenados                  *
 ************************************************/
void entrada_dados( NODO* aux ){
	  
    printf( "\n\n Digite o código: " ); 
    fflush( stdin );      // limpa buffer do teclado, funciona junto com entrada de dados
    scanf("%d", &aux->info.codigo);

    printf( "\n Digite o nome: " );
    fflush( stdin );      // limpa buffer do teclado, funciona junto com entrada de dados
    gets( aux->info.nome );
  
    aux->prox= aux;       // circular, registro aponta para ele mesmo 
    aux->ant = aux;       // circular, registro aponta para ele mesmo 
}



/*************************************************
 * imprime_lista                                 *
 * objetivo: rotina para imprimir dados          *
 * entrada : lista                               *
 * saida   : nenhuma                             *
 *************************************************/ 
void imprime_lista( NODO* aux ){
    
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
 	getchar();                    // parada da tela
}

 

/************************************************
 * cria_lista                                   *
 * objetivo: rotina para inicializar a lista    *
 * entrada : nenhuma                            *
 * saida   : NULL (inicializa lista)            *
 ************************************************/ 
void cria_lista( NODO** l ){
	 
    *l = NULL ; // lista criada, início nao aponta
}



/*************************************************
 * destroi_lista                                 *
 * objetivo: rotina para apagar lista            *
 * entrada : lista                               *
 * saida   : lista vazia                         *
 *************************************************/ 
void destroi_lista  ( NODO* *l ){
	  
	int i= 0;                     // indica número de registro na lista
		 	 
    if( *l == NULL )              // verifica se lista vazia
        printf( "\n Lista vazia!" );
	else{
		 NODO *aux = *l;          // ponteiro auxiliar para percorrer a lista
		 NODO *inicio = aux;
         do{                        
		 	    printf( "\n Destroi Registro[%d]", i );
                printf( "\t Código: %d", aux->info.codigo );
				printf( "\t Nome..: %s", aux->info.nome );
                *l = aux->prox;   // aponta para o próximo registro da lista
			    free( aux );      // libera memória
			    aux = *l;         // reposiciona ponteiro auxiliar no início  
                i++;
         }while( inicio != *l ); // fim while ( aux->prox != aux )         
		 free( inicio );
		 printf("\n Lista destruída!");
		 *l = NULL;          
    } // fim if( aux == NULL )
 	getchar();                    // parada da tela
}




/************************************************ 
 * inclui_fim                                   *
 * objetivo: rotina para inserir no fim da lista*
 * entrada : lista                              *
 * saida   : lista com novo registro            *
 ***********************************************/
void inclui_fim( NODO** l ){

    NODO* no = ( NODO * ) malloc ( sizeof( NODO ));   // aloca novo espaço em memória
    if( no != NULL ){                                 // verifica se conseguiu alocar memória para o novo registro (no)
              entrada_dados( no );                    // lê dados
              if ( *l == NULL ){                      // verifica se lista vazia, caso sim o novo registro será o primeiro
                   *l = no;                           // insere o novo registro (no) como primeiro na lista
                   no->prox = no;                     // lista circular, nodo aponta para ele mesmo
                   no->ant  = no;
              }else{                                  // caso não seja o primeiro da lista...
                   no->ant = (*l)->ant;               // ant do novo registro (no) aponta para último da lista
			       no->prox = *l;                     // prox do novo registro (no) aponta para o primeiro registro da lista (*l)                  
                   (*l)->ant->prox = no;              // prox do último registro da lista aponta para o novo registro (no)
				   (*l)->ant = no;                    // ant do primeiro registro da lista aponta para o novo registro (no)
              } // fim if ( *l == NULL ) 
              // linhas de código repetidas podem ser descritas aqui! 
              printf( "\n Registro incluído no fim!" );
    }else // if( no != NULL )   
        printf( "\n Lista cheia!" );
}



/*************************************************** 
 * inclui_inicio                                   *
 * objetivo: rotina para inserir no início da lista*
 * entrada : lista                                 *
 * saida   : lista com novo registro               *
 ***************************************************/ 
void inclui_inicio( NODO** l ){

    NODO* no = ( NODO * ) malloc ( sizeof( NODO ));   // aloca novo espaço em memória
    if( no != NULL ){                                 // verifica se conseguiu alocar memória para o novo registro (no)
              entrada_dados( no );                    // lê dados
              if( *l == NULL ){                      // verifica se lista vazia, caso sim o novo registro será o primeiro
                   no->prox = no;                     // lista circular, nodo aponta para ele mesmo
                   no->ant  = no;
              }else{                                  // caso não seja o primeiro da lista...
                   no->ant = (*l)->ant;               // ant do novo registro (no) aponta para último da lista 
				   no->prox = *l;                     // prox do novo registro (no) aponta para o primeiro registro da lista (*l) 
                   (*l)->ant->prox = no;              // prox do último registro da lista aponta para o novo registro (no)
				   (*l)->ant = no;                    // ant do primeiro registro da lista aponta para o novo registro (no)
              } // fim if ( *l == NULL ) 
			  *l = no;                                // nsere o novo registro (no) como primeiro na lista
			  // compare os algoritmos de inclusão no início e no fim, qual é a lógica que os diferencia?
              printf( "\n Registro incluído no início!" );
    } // if( no != NULL )   
    else
        printf( "\n Lista cheia!" );
}



/************************************************ 
 * procura_nodo                                 *
 * objetivo: achar nodo na lista                *
 * entrada : lista e código a ser encontrado    *
 * saída   : posição ou NULL (não encontrou)    *
 ************************************************/ 
NODO* procura_nodo( NODO* p, int cod ){
 
    NODO *inicio= p;   
    while( ( p->info.codigo != cod ) && ( p->prox != inicio ))// anda pela lista até o final da lista (sendo circular, até retornar ao primeiro) ou até encontrar código desejado
             p = p->prox;                                     // passa para o próximo   
             
    return p; // nodo de referência
}



/*************************************************** 
 * exclui_nodo                                     *
 * objetivo: rotina para excluir nodo da lista     *
 * entrada : lista                                 *
 * saída   : lista com registro excluído           *
 ***************************************************/ 
void exclui_nodo( NODO** l ){
	 
    int cod;                                     // código a ser excluído 
    NODO* no;                                    // ponteiro auxiliar para o código de referência

    if( *l == NULL )                             // verifica se a lista está vazia
        printf( "\n Lista vazia!" );
    else{
         printf("\n Código de referência: ");
         fflush( stdin );                        // limpa buffer do teclado e faz a entrada de dados
         scanf( "%d", &cod );                    // lê código a ser excluído
  
         no = procura_nodo( *l, cod );           // procura código de referência a ser excluído, retorna posição
         if( cod == no->info.codigo ){           // verifica se encontrou o código procurado na lista
             if( *l == no ){                     // se for o primeiro...  
			     (*l)->ant->prox = (*l)->prox;   // último registro aponta para o posterior do primeiro (lembrar que é lista circular)
                 (*l)->prox->ant = (*l)->ant;    // segundo registro aponta para o último (lembrar que é lista circular)
                 if( (*l)->prox != *l )          // se não for o único da lista...
					 *l = (*l)->prox;            // *l aponta para o segundo registro da lista 
	             else  
                     *l = NULL;                  // *l será NULL, pois o único registro será excluído        
             }else{                              // se não for o primeiro...  
                   no->ant->prox = no->prox;     // o registro anterior a no, aponta para um registro posterior a no (para onde no está apontando) 
                   no->prox->ant = no->ant;      // o registro posterior a no, aponta para um registro anterior a no (para onde no está apontando) 
             }    
             free( no );                         // libera o espaço de memória que estava sendo ocupado pelo registro que foi excluído
             printf( "\n Registro excluido!" );
        } // fim if( cod == no->info.codigo )
        else
            printf( "\n Registro não encontrado!");
  } // fim if( *l == NULL )
}



/*************************************************** 
 * ordena_lista                                    *
 * objetivo: rotina para ordenar a lista           *
 * entrada : lista duplamente encadeada circular   *
 * saida   : lista ordenada por código             *
 ***************************************************/ 
void ordena_lista( NODO** l ){
	   
    if( *l == NULL )                                // verifica se a lista está vazia 
        printf( "\n Lista vazia!" );
    else {
        if( (*l)->prox == NULL )                    // verifica se a lista tem apenas um registro 
             printf( "\n Lista com apenas 1 elemento!" );
        else{
             INFORMACAO aux;                        // auxiliar para a troca de dados
             NODO *ant = *l;                        // posiciona ponteiro auxiliar ant (anterior) no início da lista
             NODO *p   = ant->prox;                 // posiciona ponteiro auxiliar p (posterior) após ant, para que possa ser feita a comparação
    
             while( ant->prox != *l ){              // enquanto não for o último registro da lista circular
                    while( p != *l ){               // enquanto não for o primeiro registro da lista circular
                           if( strcmp(p->info.nome, ant->info.nome) < 0 ){ // se código de p for menor do que o código de ant, realiza a troca de conteúdo
                               aux      = p->info;  // faz a troca (algoritmo de ordenação Método Bolha)
                               p->info  = ant->info;
                               ant->info= aux;
                           } // fim if( p->info.codigo < ant.info.codigo )
                           p= p->prox;
                    } // fim while ( p != *l )  
                    ant= ant->prox;                 // atualiza ponteiros, ant para para o próximo registro
                    p= ant->prox;                   // p passa para o próximo de ant (permanece a frente do ponteiro ant)
             } // fim while ( ant->prox != *l )                      
         } // fim else
    }
}
