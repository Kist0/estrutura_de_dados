/***********************************************/ 
/* �rvores B                                   */
/* objetivo: registro de c�digos               */
/* programador: Daniela Bagatini               */
/* criado em: 11/11/2020                       */
/* data da �ltima altera��o: 11/11/2020        */
/* fonte de refer�ncia:                        */    
/* Piva Jr., D.; et al. (2014) Estrutura de    */
/* Dados e T�cnicas de Programa��o.RJ:Elsevier.*/
/***********************************************/ 

#include <stdio.h>
#include <stdlib.h>    // exit, malloc
#include <locale.h>    // setlocale
#include <conio.h>     // getch

#define GRAU 2                    // Grau m�nimo da �rvore (apontadores)


/***********************************************/ 
/* Defini��o dos Registros                     */
/***********************************************/ 
typedef int TIPO_DADO;
typedef int TIPO_NO;

typedef struct TIPO_NO{
	int nro_chaves;               // armazena o n� de chaves que est�o armazenadas no n� em determinado momento
	int folha;                    // indica se o n� � uma folha da �rvore
	int chaves[2*GRAU-1];   // N� posi��es que armazena as chaves, sendo 2*GRAU-1
	TIPO_NO *apontadores[2*GRAU]; // N� posi��es que armazena os apontadores para as sub�rvores, sendo 2*GRAU
}NO;

 
/***********************************************/ 
/* Defini��o das Fun��es                       */
/***********************************************/
void criaArvoreB( NO **raiz );
void imprimeArvoreB( NO * raiz );                               // visualiza��o da �rvore em tela, todos os registros
void buscaArvoreB( NO *raiz, int chave, NO **i, int *j ); // procura na �rvore uma chave
void repartir( NO **pai, int i );                               // reparti��o do n� cheio
void insereArvoreB( NO **raiz, int chave );               // inser��o de uma chave em uma �rvore
void inserirChaveB( NO **p, int chave );                  // inclui uma nova chave na �rvore


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
         op = getche(); // tecla de op��o do menu
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
				   printf( "A chave foi encontrada no endere�o [%#p], na posi��o %d", *i, j );
                   break;                 
                                            
           case '4':   // imprime ARVORE-B e mostra todos os registros                                             
                   imprimeArvoreB( raiz );
                   
                   break;
				                      
           case '0':  // t�rmino do programa                                                 
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
 * objetivo: inicializar �rvore B                *
 * entrada : raiz da �rvore B                    *
 * sa�da   : �rvore B criada                     *
 *************************************************/ 
 void criaArvoreB( NO **raiz ){
 	NO *no= ( NO * ) malloc( sizeof(NO) );       // aloca mem�ria para o novo n�
 	no->folha= 1;                                // indica que o n� � folha
	no->nro_chaves= 0;                           // indica o n� de chaves
	*raiz= no;                                   // o novo n� passar a ser a raiz da �rvore B
 }
 
 
/*************************************************
 * imprimeArvoreB                                *
 * objetivo: imprimir chaves ordenadas crescente *
 * entrada : raiz da �rvore B                    *
 * sa�da   : dados em tela                       *
 *************************************************/ 
void imprimeArvoreB( NO *raiz ){
	int j, Ni;                                    // j= para percorrer as chaves; Ni= n� de chaves de um n�
	
	if( raiz != NULL ){
		Ni= raiz->nro_chaves;                     // obt�m o n� de chaves do n� 
        printf( " " );
		for( j= 0; j < Ni; j++ ){                 // percorre as chaves no n�
			imprimeArvoreB(raiz->apontadores[j]); // percorre a j-�sima sub�rvore de n� 
			printf( "%d ", raiz->chaves[j] );     // apresenta a j-�sima chave no n� 
		}
		printf( "  " );
		imprimeArvoreB( raiz->apontadores[j] );   // percorre a �ltima sub�rvore do n� 
	}
}


/*************************************************
 * buscaArvoreB                                  *
 * objetivo: buscar chave                        *
 * entrada : raiz da �rvore, chave de refer�ncia,*
 *    apontador para n� e posi��o da chave no n� *
 * sa�da   : apontador e posi��o do buscado      *
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
 * objetivo: repartir n� cheio                  *
 * entrada : n� pai e chave                     *
 * sa�da   : divis�o do n� em dois              *
 ************************************************/
 void repartir( NO **pai, int i ){
 	NO *ant, *novo;                             // apontadores para os n�s que receber�o G-1 chaves (cada um) do n� repartido, sendo ant e novo o resultado da reparti��o de ant (que � o k-�simo filho de pai)
 	int k;
 	
 	// ant � o n� que ser� repartido 
	// pai � o n� pai de ant
 	// em ant permanecer�o as G-1 menores chaves
	   // as G-1 maiores ser�o colocadaas no novo n� criado (novo)
 	// no ant permanecer�o as G sub�rvores mais � esquerda
	   // as G sub�rvores � direita ser�o deslocadas para o novo
 	ant= (*pai)->apontadores[i];               // ant aponta o n� filho de pai que ser� repartido
 	novo= ( NO * ) malloc( sizeof( NO ) );     // aloca espa�o para o novo n� 
 	novo->folha= ant->folha;                   // coloca os dois n�s (resultados da divis�o com o mesmo status de folha 0 ou 1)
 	for( k= 0; k <= GRAU-2; k++ )              // copia as maiores chaves de ant em novo
 		 novo->chaves[k]= ant->chaves[k+GRAU]; 
 	if( ant->folha == 0 )	
	 	for( k= 0; k <= GRAU-2; k++ )          // copia a sub�rvore mais � direita de ant para novo
	 		 novo->apontadores[k]= ant->apontadores[k+GRAU];
	novo->nro_chaves= ant->nro_chaves = GRAU-1;// acerta o n� de chavesde ant e novo
	for( k= (*pai)->nro_chaves-1; k >= i; k-- )// abre espa�o para subir a chave mediana para o n� pai
		 (*pai)->chaves[k+1]= (*pai)->chaves[k];
	(*pai)->chaves[i]= ant->chaves[GRAU-1];    // sobe a chave mediana
	((*pai)->nro_chaves)++;                    // incrementa o n� de chaves do pai
	for( k= ((*pai)->nro_chaves); k >= i+1; k-- )// abre espa�o para a sub�rvore formada pelo novo n�
		 (*pai)->apontadores[k+1]= (*pai)->apontadores[k]; //(*pai)->apontadores[k+1]= (*pai)->apontadores[k];
	(*pai)->apontadores[k+1]= novo;            // insere a nova chave 
 }


/************************************************ 
 * insereArvoreB                                *
 * objetivo: inserir novo n� na �rvore B        *
 * entrada : raiz e chave                       *
 * sa�da   : �rvore com novo n�                 *
 ************************************************/
void insereArvoreB( NO **raiz, int chave ){
	NO *novo, *aux= *raiz;                      // aponta para a raiz da �rvore

	if( aux->nro_chaves == 2*GRAU-1 ){          // n� raiz est� cheio, � necess�rio aumentar a altura da �rvore
 		novo= ( NO * ) malloc( sizeof( NO ) );  // aloca espa�o para o novo n� que receber� chave mediana da antiga raiz
 		novo->folha= 0;                         // indica que n�o � folha
		novo->nro_chaves= 0;                    // indica o n� de chaves
		novo->apontadores[0]= aux;              // coloca a antiga raiz como filha de novo
		*raiz= novo;                            // novo passa a ser a raiz			
		repartir( &novo, 0 );                   // repartir a antiga raiz (aux)  
		if( novo->chaves[0] < chave ) 
			inserirChaveB( &novo->apontadores[1], chave ); // inserir a chave a partir do n� que foi repartido
		else
			inserirChaveB( &aux, chave );       // inserir a chave a partir do n� que foi repartido
	}
	else
		inserirChaveB( &(*raiz), chave );       // inserir chave a partir da raiz
	printf( "\n Chave inserida!" );	
}


/************************************************ 
 * inserirChaveB                                *
 * objetivo: inserir novo n� na �rvore B        *
 * entrada : raiz e chave                       *
 * sa�da   : �rvore com novo n�                 *
 ************************************************/
void inserirChaveB( NO **p, int chave ){
	NO *aux;                                    // apontador usado como k-�simo filho de p
	int k;
	
	k= (*p)->nro_chaves-1;                      // indica a �ltima posi��o ocupada em chaves[k] no n� p
	if( (*p)->folha == 1 ){                     // verifica se p � folha para receber a chave
		while( k >= 0 && chave < (*p)->chaves[k] ){// abre espa�o em p para inserir a chave
			(*p)->chaves[k+1]= (*p)->chaves[k];
			k--;
		}
		(*p)->chaves[k+1]= chave;               // insere a chave em p
		((*p)->nro_chaves)++;                   // incrementa o n� de chaves em p	 
	}
	else{                                       // se p n�o � folha, procura filho de p para inser��o
		while( k >= 0 && chave < (*p)->chaves[k] )// procura sub�rvore de p para inser��o da chave
			k--;                                
		k++;
		aux= (*p)->apontadores[k];              // aux aponta sub�rvore para inser��o da chave
		if( aux->nro_chaves == 2*GRAU-1 ){      // verifica se aux (filho de p) est� cheio
			repartir( &(*p), k );               // repartir aux
			if( chave > (*p)->chaves[k] )       // identifica em qual dos n�s gerados da repeti��o de aux dever� inserir a chave
				k++;
			aux= (*p)->apontadores[k];
		}
		inserirChaveB( &aux, chave );           // inserir chave na sub�rvore de aux
	}
}
