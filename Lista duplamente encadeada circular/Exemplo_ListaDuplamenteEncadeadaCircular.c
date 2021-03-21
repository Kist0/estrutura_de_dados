/***********************************************/ 
/* Lista Duplamente Encadeada                  */
/* objetivo: cadastro pessoas                  */
/* programador: Daniela Bagatini               */
/* criado em: 06/04/2018                       */
/* data da �ltima altera��o: 06/10/2019        */
/***********************************************/ 

#include <stdio.h>                            // entrada e sa�da padr�o: printf, scanf
#include <stdlib.h>		                      // exit, malloc, system
#include <string.h>	  	                      // strcmp
#include <locale.h>                           // setlocale
//#include <ctype.h>                          // toupper
#include <conio.h>                            // getch
//#include <time.h>                           // rand  


// bibliotecas inclu�das, manter bibliotecas na mesma pasta do arquivo fonte
#include "MODELODUPLA.h"                      // modelo de dados
#include "GERA_DADOSCIRCULAR.h"               // gera dados para povoar lista de forma autom�tica 


/***********************************************/ 
/* Defini��o das Fun��es                       */
/***********************************************/
void  entrada_dados  ( NODO* aux );           // l� dados de entrada
void  imprime_lista  ( NODO* l );             // visualiza lista em tela
void  cria_lista     ( NODO** l );            // inicializa lista com NULL
void  destroi_lista  ( NODO* *l );            // apaga lista e libera mem�ria
void  inclui_fim     ( NODO** l );            // inclui novo registro no final da lista
void  inclui_inicio  ( NODO** l );            // inclui novo registro no in�cio da lista
NODO* procura_nodo   ( NODO* l, int cod );   // procura na lista por c�digo
void  exclui_nodo    ( NODO** l );            // exclui regitro por c�digo
void  ordena_lista   ( NODO** l );            // ordena lista por c�digo
// crie sua pr�pria fun��o aqui!

       
/***********************************************/ 
/* Programa Principal                          */
/***********************************************/ 
int main( void ){
    int op;                                   // op��o do menu                               
    NODO* l;                                  // declara��o da lista, vari�vel do tipo lista = lista de ponteiros
    setlocale(LC_ALL, "Portuguese");          // alterar idioma para portugu�s      

    while( 1 ){
         printf( "\n /---------------------------------------------------/" ); 
         printf( "\n Programa de registro - Menu                          " );
         printf( "\n [1] Cria lista                                       " );
         printf( "\n [2] Inclui registro no final da lista                " );
         printf( "\n [3] Inclui registro no in�cio da lista               " );
         printf( "\n [4] Exclui registro                                  " );
         printf( "\n [5] Ordena lista                                     " );                           
         printf( "\n [6] Gera dados                                       " );
         printf( "\n [7] Destroi lista                                    " );		  
         printf( "\n [8] Imprime lista                                    " );
         printf( "\n [0] Para sair do programa                            " );
         printf( "\n /---------------------------------------------------/" );      
         printf( "\n Op��o: " );
         fflush( stdin );   // limpa buffer do teclado, funciona antes da entrada de dados
         scanf( "%i", &op );// tecla de op��o do menu

         switch( op ) {
            case 1: // rotina cria lista       
                    cria_lista( &l );
                    break;
                                                    
            case 2: // rotina inclui registro no final da lista
                    inclui_fim( &l );    
                    break;
          
            case 3: // rotina inclui registro no in�cio da lista
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
					                                
            case 0: // t�rmino do programa                                                 
                    exit( 1 ); 
                    break;
                
            default : 
                    printf( "\n Digite uma op��o!" );
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
	  
    printf( "\n\n Digite o c�digo: " ); 
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
    
	int i= 0;                     // indica n�mero de registro na lista
		 	 
    if( aux == NULL )             // verifica se lista vazia
        printf( "\n Lista vazia!" );
	else{
	     printf("\n Relat�rio Geral ----------------------------------------- ");
         NODO *inicio= aux;       // ponteiro auxiliar para percorrer a lista
         do{                        
		 	    printf( "\n Registro[%d]", i );
                printf( "\t C�digo: %d", aux->info.codigo );
                printf( "\t Nome..: %s", aux->info.nome );
                aux = aux->prox;  // aponta para o pr�ximo registro da lista
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
	 
    *l = NULL ; // lista criada, in�cio nao aponta
}



/*************************************************
 * destroi_lista                                 *
 * objetivo: rotina para apagar lista            *
 * entrada : lista                               *
 * saida   : lista vazia                         *
 *************************************************/ 
void destroi_lista  ( NODO* *l ){
	  
	int i= 0;                     // indica n�mero de registro na lista
		 	 
    if( *l == NULL )              // verifica se lista vazia
        printf( "\n Lista vazia!" );
	else{
		 NODO *aux = *l;          // ponteiro auxiliar para percorrer a lista
		 NODO *inicio = aux;
         do{                        
		 	    printf( "\n Destroi Registro[%d]", i );
                printf( "\t C�digo: %d", aux->info.codigo );
				printf( "\t Nome..: %s", aux->info.nome );
                *l = aux->prox;   // aponta para o pr�ximo registro da lista
			    free( aux );      // libera mem�ria
			    aux = *l;         // reposiciona ponteiro auxiliar no in�cio  
                i++;
         }while( inicio != *l ); // fim while ( aux->prox != aux )         
		 free( inicio );
		 printf("\n Lista destru�da!");
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

    NODO* no = ( NODO * ) malloc ( sizeof( NODO ));   // aloca novo espa�o em mem�ria
    if( no != NULL ){                                 // verifica se conseguiu alocar mem�ria para o novo registro (no)
              entrada_dados( no );                    // l� dados
              if ( *l == NULL ){                      // verifica se lista vazia, caso sim o novo registro ser� o primeiro
                   *l = no;                           // insere o novo registro (no) como primeiro na lista
                   no->prox = no;                     // lista circular, nodo aponta para ele mesmo
                   no->ant  = no;
              }else{                                  // caso n�o seja o primeiro da lista...
                   no->ant = (*l)->ant;               // ant do novo registro (no) aponta para �ltimo da lista
			       no->prox = *l;                     // prox do novo registro (no) aponta para o primeiro registro da lista (*l)                  
                   (*l)->ant->prox = no;              // prox do �ltimo registro da lista aponta para o novo registro (no)
				   (*l)->ant = no;                    // ant do primeiro registro da lista aponta para o novo registro (no)
              } // fim if ( *l == NULL ) 
              // linhas de c�digo repetidas podem ser descritas aqui! 
              printf( "\n Registro inclu�do no fim!" );
    }else // if( no != NULL )   
        printf( "\n Lista cheia!" );
}



/*************************************************** 
 * inclui_inicio                                   *
 * objetivo: rotina para inserir no in�cio da lista*
 * entrada : lista                                 *
 * saida   : lista com novo registro               *
 ***************************************************/ 
void inclui_inicio( NODO** l ){

    NODO* no = ( NODO * ) malloc ( sizeof( NODO ));   // aloca novo espa�o em mem�ria
    if( no != NULL ){                                 // verifica se conseguiu alocar mem�ria para o novo registro (no)
              entrada_dados( no );                    // l� dados
              if( *l == NULL ){                      // verifica se lista vazia, caso sim o novo registro ser� o primeiro
                   no->prox = no;                     // lista circular, nodo aponta para ele mesmo
                   no->ant  = no;
              }else{                                  // caso n�o seja o primeiro da lista...
                   no->ant = (*l)->ant;               // ant do novo registro (no) aponta para �ltimo da lista 
				   no->prox = *l;                     // prox do novo registro (no) aponta para o primeiro registro da lista (*l) 
                   (*l)->ant->prox = no;              // prox do �ltimo registro da lista aponta para o novo registro (no)
				   (*l)->ant = no;                    // ant do primeiro registro da lista aponta para o novo registro (no)
              } // fim if ( *l == NULL ) 
			  *l = no;                                // nsere o novo registro (no) como primeiro na lista
			  // compare os algoritmos de inclus�o no in�cio e no fim, qual � a l�gica que os diferencia?
              printf( "\n Registro inclu�do no in�cio!" );
    } // if( no != NULL )   
    else
        printf( "\n Lista cheia!" );
}



/************************************************ 
 * procura_nodo                                 *
 * objetivo: achar nodo na lista                *
 * entrada : lista e c�digo a ser encontrado    *
 * sa�da   : posi��o ou NULL (n�o encontrou)    *
 ************************************************/ 
NODO* procura_nodo( NODO* p, int cod ){
 
    NODO *inicio= p;   
    while( ( p->info.codigo != cod ) && ( p->prox != inicio ))// anda pela lista at� o final da lista (sendo circular, at� retornar ao primeiro) ou at� encontrar c�digo desejado
             p = p->prox;                                     // passa para o pr�ximo   
             
    return p; // nodo de refer�ncia
}



/*************************************************** 
 * exclui_nodo                                     *
 * objetivo: rotina para excluir nodo da lista     *
 * entrada : lista                                 *
 * sa�da   : lista com registro exclu�do           *
 ***************************************************/ 
void exclui_nodo( NODO** l ){
	 
    int cod;                                     // c�digo a ser exclu�do 
    NODO* no;                                    // ponteiro auxiliar para o c�digo de refer�ncia

    if( *l == NULL )                             // verifica se a lista est� vazia
        printf( "\n Lista vazia!" );
    else{
         printf("\n C�digo de refer�ncia: ");
         fflush( stdin );                        // limpa buffer do teclado e faz a entrada de dados
         scanf( "%d", &cod );                    // l� c�digo a ser exclu�do
  
         no = procura_nodo( *l, cod );           // procura c�digo de refer�ncia a ser exclu�do, retorna posi��o
         if( cod == no->info.codigo ){           // verifica se encontrou o c�digo procurado na lista
             if( *l == no ){                     // se for o primeiro...  
			     (*l)->ant->prox = (*l)->prox;   // �ltimo registro aponta para o posterior do primeiro (lembrar que � lista circular)
                 (*l)->prox->ant = (*l)->ant;    // segundo registro aponta para o �ltimo (lembrar que � lista circular)
                 if( (*l)->prox != *l )          // se n�o for o �nico da lista...
					 *l = (*l)->prox;            // *l aponta para o segundo registro da lista 
	             else  
                     *l = NULL;                  // *l ser� NULL, pois o �nico registro ser� exclu�do        
             }else{                              // se n�o for o primeiro...  
                   no->ant->prox = no->prox;     // o registro anterior a no, aponta para um registro posterior a no (para onde no est� apontando) 
                   no->prox->ant = no->ant;      // o registro posterior a no, aponta para um registro anterior a no (para onde no est� apontando) 
             }    
             free( no );                         // libera o espa�o de mem�ria que estava sendo ocupado pelo registro que foi exclu�do
             printf( "\n Registro excluido!" );
        } // fim if( cod == no->info.codigo )
        else
            printf( "\n Registro n�o encontrado!");
  } // fim if( *l == NULL )
}



/*************************************************** 
 * ordena_lista                                    *
 * objetivo: rotina para ordenar a lista           *
 * entrada : lista duplamente encadeada circular   *
 * saida   : lista ordenada por c�digo             *
 ***************************************************/ 
void ordena_lista( NODO** l ){
	   
    if( *l == NULL )                                // verifica se a lista est� vazia 
        printf( "\n Lista vazia!" );
    else {
        if( (*l)->prox == NULL )                    // verifica se a lista tem apenas um registro 
             printf( "\n Lista com apenas 1 elemento!" );
        else{
             INFORMACAO aux;                        // auxiliar para a troca de dados
             NODO *ant = *l;                        // posiciona ponteiro auxiliar ant (anterior) no in�cio da lista
             NODO *p   = ant->prox;                 // posiciona ponteiro auxiliar p (posterior) ap�s ant, para que possa ser feita a compara��o
    
             while( ant->prox != *l ){              // enquanto n�o for o �ltimo registro da lista circular
                    while( p != *l ){               // enquanto n�o for o primeiro registro da lista circular
                           if( strcmp(p->info.nome, ant->info.nome) < 0 ){ // se c�digo de p for menor do que o c�digo de ant, realiza a troca de conte�do
                               aux      = p->info;  // faz a troca (algoritmo de ordena��o M�todo Bolha)
                               p->info  = ant->info;
                               ant->info= aux;
                           } // fim if( p->info.codigo < ant.info.codigo )
                           p= p->prox;
                    } // fim while ( p != *l )  
                    ant= ant->prox;                 // atualiza ponteiros, ant para para o pr�ximo registro
                    p= ant->prox;                   // p passa para o pr�ximo de ant (permanece a frente do ponteiro ant)
             } // fim while ( ant->prox != *l )                      
         } // fim else
    }
}
