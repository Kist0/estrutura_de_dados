/***********************************************/ 
/* Árvores B                                   */
/* objetivo: registro de códigos               */
/* programador: Daniela Bagatini               */
/* criado em: 11/11/2020                       */
/* data da última alteração: 11/11/2020        */
/* fonte de referência:                        */    
/* Piva Jr., D.; et al. (2014) Estrutura de    */
/* Dados e Técnicas de Programação.RJ:Elsevier.*/
/***********************************************/ 

#include <stdio.h>
#include <stdlib.h>    // exit, malloc
#include <locale.h>    // setlocale
#include <conio.h>     // getch

#define GRAU 2                    // Grau mínimo da árvore (apontadores)


/***********************************************/ 
/* Definição dos Registros                     */
/***********************************************/ 
typedef int TIPO_DADO;
typedef int TIPO_NO;

typedef struct TIPO_NO{
	int nro_chaves;               // armazena o nº de chaves que estão armazenadas no nó em determinado momento
	int folha;                    // indica se o nó é uma folha da árvore
	int chaves[2*GRAU-1];   // Nº posições que armazena as chaves, sendo 2*GRAU-1
	TIPO_NO *apontadores[2*GRAU]; // Nº posições que armazena os apontadores para as subárvores, sendo 2*GRAU
}NO;

 
/***********************************************/ 
/* Definição das Funções                       */
/***********************************************/
void criaArvoreB( NO **raiz );
void imprimeArvoreB( NO * raiz );                               // visualização da árvore em tela, todos os registros
void buscaArvoreB( NO *raiz, int chave, NO **i, int *j ); // procura na árvore uma chave
void repartir( NO **pai, int i );                               // repartição do nó cheio
void insereArvoreB( NO **raiz, int chave );               // inserção de uma chave em uma árvore
void inserirChaveB( NO **p, int chave );                  // inclui uma nova chave na árvore


/***********************************************/ 
/* Programa Principal                          */
/***********************************************/
int main( void ){
	NO *raiz, *i= NULL;
	char op;
	int nChave= 0, chaveBusca, j= 0;
	
	setlocale(LC_ALL, "Portuguese");
    while( 1 ){
         printf( "\n /---------------------------------------------------/" ); 
         printf( "\n Programa de registros - Menu                         " );
         printf( "\n [1] Cria ARVORE-B                                    " );
         printf( "\n [2] Insere                                           " );
         printf( "\n [3] Busca                                            " );
		 printf( "\n [4] Imprime                                          " );         
		 printf( "\n [0] Para sair do programa                            " );         
         printf( "\n /---------------------------------------------------/" );      
         printf( "\n Opcao: " );
         op = getche(); // tecla de opção do menu
         printf( "\n" );

         switch( op ) {
           case '1':   // rotina cria ARVORE-B       
                   criaArvoreB( &raiz );
                   break;
                                
           case '2':   // rotina inclui chave na ARVORE-B (folha)
                   //printf( "Informe a chave: " );
                   //scanf( "%d", &nChave ); // chave a ser inserida na ARVORE-B
				   nChave= nChave + 10;
				   insereArvoreB( &raiz, nChave );
                   break;
                      
           case '3':   // rotina busca chave na ARVORE-B
                   printf( "Informe a chave de busca: " );
                   scanf( "%d", &chaveBusca ); // chave a ser procurada na ARVORE-B
				   buscaArvoreB( raiz, chaveBusca, &i, &j );				   
				   printf( "A chave foi encontrada no endereço [%#p], na posição %d", *i, j );
                   break;                 
                                            
           case '4':   // imprime ARVORE-B e mostra todos os registros                                             
                   imprimeArvoreB( raiz );
                   
                   break;
				                      
           case '0':  // término do programa                                                 
                   exit( 1 ); 
                   break;                
                   
           default : 
                   printf( "\n Digite uma opcao!" );
                   break;
        } // switch( op )
        
        fflush( stdin ); // limpa buffer do teclado, funciona junto com entrada de dados
        getchar();       // parada da tela
        
        printf( "\n" );
     } // fim do while( 1 )
     
 return 0;	
	
}


/*************************************************
 * criaArvoreB                                   *
 * objetivo: inicializar árvore B                *
 * entrada : raiz da árvore B                    *
 * saída   : árvore B criada                     *
 *************************************************/ 
 void criaArvoreB( NO **raiz ){
 	NO *no= ( NO * ) malloc( sizeof(NO) );       // aloca memória para o novo nó
 	no->folha= 1;                                // indica que o nó é folha
	no->nro_chaves= 0;                           // indica o nº de chaves
	*raiz= no;                                   // o novo nó passar a ser a raiz da árvore B
 }
 
 
/*************************************************
 * imprimeArvoreB                                *
 * objetivo: imprimir chaves ordenadas crescente *
 * entrada : raiz da árvore B                    *
 * saída   : dados em tela                       *
 *************************************************/ 
void imprimeArvoreB( NO *raiz ){
	int j, Ni;                                    // j= para percorrer as chaves; Ni= nº de chaves de um nó
	
	if( raiz != NULL ){
		Ni= raiz->nro_chaves;                     // obtém o nº de chaves do nó 
        printf( " " );
		for( j= 0; j < Ni; j++ ){                 // percorre as chaves no nó
			imprimeArvoreB(raiz->apontadores[j]); // percorre a j-ésima subárvore de nó 
			printf( "%d ", raiz->chaves[j] );     // apresenta a j-ésima chave no nó 
		}
		printf( "  " );
		imprimeArvoreB( raiz->apontadores[j] );   // percorre a última subárvore do nó 
	}
}


/*************************************************
 * buscaArvoreB                                  *
 * objetivo: buscar chave                        *
 * entrada : raiz da árvore, chave de referência,*
 *    apontador para nó e posição da chave no nó *
 * saída   : apontador e posição do buscado      *
 *************************************************/
void buscaArvoreB( NO *raiz, int chave, NO **i, int *j ){
	int numCha;
	
	if( raiz == NULL ){
		*i = NULL;
		*j = -1;
	}
	else{
		*i = raiz;
		numCha = (*i)->nro_chaves;
		for(*j=0; *j<numCha; (*j)++){
			printf("Chave: %d\n", (*i)->chaves[*j]);
			if((*i)->chaves[*j] == chave)
			    return;
			else
				if(chave < (*i)->chaves[*j])
					break;
		}
		buscaArvoreB((*i)->apontadores[*j], chave, &(*i), &(*j));
	}
}


/************************************************ 
 * repartir                                     *
 * objetivo: repartir nó cheio                  *
 * entrada : nó pai e chave                     *
 * saída   : divisão do nó em dois              *
 ************************************************/
 void repartir( NO **pai, int i ){
 	NO *ant, *novo;                             // apontadores para os nós que receberão G-1 chaves (cada um) do nó repartido, sendo ant e novo o resultado da repartição de ant (que é o k-ésimo filho de pai)
 	int k;
 	
 	// ant é o nó que será repartido 
	// pai é o nó pai de ant
 	// em ant permanecerão as G-1 menores chaves
	   // as G-1 maiores serão colocadaas no novo nó criado (novo)
 	// no ant permanecerão as G subárvores mais à esquerda
	   // as G subárvores à direita serão deslocadas para o novo
 	ant= (*pai)->apontadores[i];               // ant aponta o nó filho de pai que será repartido
 	novo= ( NO * ) malloc( sizeof( NO ) );     // aloca espaço para o novo nó 
 	novo->folha= ant->folha;                   // coloca os dois nós (resultados da divisão com o mesmo status de folha 0 ou 1)
 	for( k= 0; k <= GRAU-2; k++ )              // copia as maiores chaves de ant em novo
 		 novo->chaves[k]= ant->chaves[k+GRAU]; 
 	if( ant->folha == 0 )	
	 	for( k= 0; k <= GRAU-2; k++ )          // copia a subárvore mais à direita de ant para novo
	 		 novo->apontadores[k]= ant->apontadores[k+GRAU];
	novo->nro_chaves= ant->nro_chaves = GRAU-1;// acerta o nº de chavesde ant e novo
	for( k= (*pai)->nro_chaves-1; k >= i; k-- )// abre espaço para subir a chave mediana para o nó pai
		 (*pai)->chaves[k+1]= (*pai)->chaves[k];
	(*pai)->chaves[i]= ant->chaves[GRAU-1];    // sobe a chave mediana
	((*pai)->nro_chaves)++;                    // incrementa o nº de chaves do pai
	for( k= ((*pai)->nro_chaves); k >= i+1; k-- )// abre espaço para a subárvore formada pelo novo nó
		 (*pai)->apontadores[k+1]= (*pai)->apontadores[k]; //(*pai)->apontadores[k+1]= (*pai)->apontadores[k];
	(*pai)->apontadores[k+1]= novo;            // insere a nova chave 
 }


/************************************************ 
 * insereArvoreB                                *
 * objetivo: inserir novo nó na árvore B        *
 * entrada : raiz e chave                       *
 * saída   : árvore com novo nó                 *
 ************************************************/
void insereArvoreB( NO **raiz, int chave ){
	NO *novo, *aux= *raiz;                      // aponta para a raiz da árvore

	if( aux->nro_chaves == 2*GRAU-1 ){          // nó raiz está cheio, é necessário aumentar a altura da árvore
 		novo= ( NO * ) malloc( sizeof( NO ) );  // aloca espaço para o novo nó que receberá chave mediana da antiga raiz
 		novo->folha= 0;                         // indica que não é folha
		novo->nro_chaves= 0;                    // indica o nº de chaves
		novo->apontadores[0]= aux;              // coloca a antiga raiz como filha de novo
		*raiz= novo;                            // novo passa a ser a raiz			
		repartir( &novo, 0 );                   // repartir a antiga raiz (aux)  
		if( novo->chaves[0] < chave ) 
			inserirChaveB( &novo->apontadores[1], chave ); // inserir a chave a partir do nó que foi repartido
		else
			inserirChaveB( &aux, chave );       // inserir a chave a partir do nó que foi repartido
	}
	else
		inserirChaveB( &(*raiz), chave );       // inserir chave a partir da raiz
	printf( "\n Chave inserida!" );	
}


/************************************************ 
 * inserirChaveB                                *
 * objetivo: inserir novo nó na árvore B        *
 * entrada : raiz e chave                       *
 * saída   : árvore com novo nó                 *
 ************************************************/
void inserirChaveB( NO **p, int chave ){
	NO *aux;                                    // apontador usado como k-ésimo filho de p
	int k;
	
	k= (*p)->nro_chaves-1;                      // indica a última posição ocupada em chaves[k] no nó p
	if( (*p)->folha == 1 ){                     // verifica se p é folha para receber a chave
		while( k >= 0 && chave < (*p)->chaves[k] ){// abre espaço em p para inserir a chave
			(*p)->chaves[k+1]= (*p)->chaves[k];
			k--;
		}
		(*p)->chaves[k+1]= chave;               // insere a chave em p
		((*p)->nro_chaves)++;                   // incrementa o nº de chaves em p	 
	}
	else{                                       // se p não é folha, procura filho de p para inserção
		while( k >= 0 && chave < (*p)->chaves[k] )// procura subárvore de p para inserção da chave
			k--;                                
		k++;
		aux= (*p)->apontadores[k];              // aux aponta subárvore para inserção da chave
		if( aux->nro_chaves == 2*GRAU-1 ){      // verifica se aux (filho de p) está cheio
			repartir( &(*p), k );               // repartir aux
			if( chave > (*p)->chaves[k] )       // identifica em qual dos nós gerados da repetição de aux deverá inserir a chave
				k++;
			aux= (*p)->apontadores[k];
		}
		inserirChaveB( &aux, chave );           // inserir chave na subárvore de aux
	}
}
