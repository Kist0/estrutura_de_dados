/***********************************************/ 
/* Grafos - BFS - Breadth-First Search         */
/* objetivo: registro de códigos               */
/* adaptado de                                 */
/*  https://www.programiz.com/dsa/graph-bfs    */
/* criado em: 11/11/2020                       */
/* data da última alteração: 10/12/2020        */
/***********************************************/

#include <stdio.h>
#include <stdlib.h>
#define MAX 40  // Máximo de vértices na fila


/***********************************************/ 
/* Definição dos Registros                     */
/***********************************************/
typedef struct QUEUE {   // Fila de busca
  int itens[MAX];        // Lista de vértices
  int inicio;
  int fim;
}QUEUE;

typedef struct NO {      // Registro
  int vertex;
  struct NO* next;
}NO;

typedef struct GRAPH {   // Grafo
  int numVertices;       // Nº total de vértices
  struct NO** adjLists;  // Lista de adjacências 
  int* visit;            // Nós visitados na busca
}GRAPH;


/***********************************************/ 
/* Definição das Funções                   */
/***********************************************/
void bfs( GRAPH* graph, int startVertex ); // Busca DFS
void bfs( GRAPH* graph, int startVertex ); // Busca BFS
NO* createNO( int v );                     // Cria novo nó
GRAPH* createGraph( int vertices );        // Cria o grafo
void addEdge( GRAPH* graph, int origem, int destino ); // Insere elementos na lista de adjacências de cada nó
QUEUE* createQueue();                      // Cria a fila 
void enqueue( QUEUE* q, int );             // Adiciona elemento na fila
int dequeue( QUEUE* q );                   // Retira elemento da fila                
int isEmpty( QUEUE* q );                   // Verifica se a fila está vazia
void printQueue( QUEUE* q );               // Mostra a fila 


/***********************************************/ 
/* Programa Principal                          */
/***********************************************/
int main( void ) {
  GRAPH* graph = createGraph( 8 );
  addEdge( graph, 0, 2 );
  addEdge( graph, 0, 1 );
  addEdge( graph, 1, 2 );
  addEdge( graph, 1, 4 );
  addEdge( graph, 1, 3 );
  addEdge( graph, 2, 4 );
  addEdge( graph, 3, 4 );
  addEdge( graph, 4, 5 );
  addEdge( graph, 5, 6 );
  addEdge( graph, 5, 7 );

  //bfs( graph, 0 );  // Busca em largura ou amplitude a partir do source 0
  dfs(graph, 0); 	// Busca recursiva a partir do 0
   
  return 0;
}


/*************************************************
 * DFS                                           *
 * objetivo: percorrer recursivamente            *
 * entrada : grafo e source                      *
 * saída   : nó visitado em tela               *
 *************************************************/ 
void dfs(GRAPH* grafo, int source) {
  QUEUE* q = createQueue();

  grafo->visit[source] = 1;
  enqueue( q, source );

  while ( !isEmpty(q) ) { // Percorre todos os vértices até fila vazia
    printQueue( q );
    int currentVertex = dequeue( q );  // Retira da fila
    printf( "visit %d\n", currentVertex );

    NO* temp = grafo->adjLists[currentVertex];

    while ( temp ) {      // Percorre a lista de adjacentes de um nó
      int adjVertex = temp->vertex;

      if ( grafo->visit[adjVertex] == 0 )
        dfs(grafo, adjVertex);				//Utiliza-se da recursividade para refazer a fun��o e continuar a percorrer o grafo
      temp = temp->next;
    }
  }
}


/*************************************************
 * BFS                                           *
 * objetivo: percorrer em amplitude              *
 * entrada : grafo e source                      *
 * saída   : nó visitado em tela                 *
 *************************************************/ 
void bfs(GRAPH* grafo, int source) {
  QUEUE* q = createQueue();

  grafo->visit[source] = 1;
  enqueue( q, source );

  while ( !isEmpty(q) ) { // Percorre todos os vértices até fila vazia
    printQueue( q );
    int currentVertex = dequeue( q );  // Retira da fila
    printf( "\nvisit %d\n", currentVertex );

    NO* temp = grafo->adjLists[currentVertex];

    while ( temp ) {      // Percorre a lista de adjacentes de um nó
      int adjVertex = temp->vertex;

      if ( grafo->visit[adjVertex] == 0 ) {
        grafo->visit[adjVertex] = 1;
        enqueue(q, adjVertex); // Insere na fila  
      }
      temp = temp->next;
    }
  }
}


/*************************************************
 * criaNO                                        *
 * objetivo: incializa vértice e apontador NULL  *
 * entrada : valor do vértice                    *
 * saída   : novo nó                             *
 *************************************************/ 
NO* createNO( int v ) {
  NO* newNO = ( NO * ) malloc( sizeof( NO ) );
  newNO->vertex = v;
  newNO->next = NULL;
  return newNO;
}


/*************************************************
 * criaGrafo                                     *
 * objetivo: inicializa lista adj., lista        *
 *           lista de visitados a partir do nº   *
 *           vértices                            *
 * entrada : nº de vértices                      *
 * saída   : grafo                               *
 *************************************************/ 
GRAPH* createGraph( int vertices ) {
  GRAPH* graph = ( GRAPH * ) malloc( sizeof( GRAPH ) );  // Aloca memoria para o grafo
  graph->numVertices = vertices;                         // Nº de vértices do grafo
  graph->adjLists = ( NO ** ) malloc( vertices * sizeof( NO* ) ); // Aloca memória para a lista de vértices
  graph->visit = ( int * ) malloc( vertices * sizeof( int ) );    // Aloca memória para lista de visitados

  int i;
  for ( i = 0; i < vertices; i++ ) {  
    graph->adjLists[i] = NULL;       // Inicializa lista de vértices
    graph->visit[i] = 0;             // Inicializa lista de visitados 
  }
  return graph;
}


/*************************************************
 * criaListas                                    *
 * objetivo: inicializa lista adjacências para   *
 *           grafo não orientado                 *
 * entrada : grafo, origem, destino              *
 * saída   : grafo com listas de adjacências     *
 *************************************************/
void addEdge( GRAPH* graph, int origem, int destino ) {
  
  NO* novoNO = createNO( destino );  // Adiciona da origem para o destino
  novoNO->next = graph->adjLists[origem];
  graph->adjLists[origem] = novoNO;

  novoNO = createNO( origem );       // Adiciona do destino para a origem
  novoNO->next = graph->adjLists[destino];
  graph->adjLists[destino] = novoNO;
}


/*************************************************
 * criaFila                                      *
 * objetivo: inicializa ponteiro para fila       *
 *           posiciona indicador de início e fim * 
 * entrada : nenhum                              *
 * saída   : ponteiro para fila                  *
 *************************************************/
QUEUE* createQueue() {
  QUEUE* q = ( QUEUE * ) malloc( sizeof ( QUEUE ) );
  q->inicio = -1;
  q->fim = -1;
  return q;
}


/*************************************************
 * verificaFilaVazia                             *
 * objetivo: verifica se fila vazia              *
 * entrada : ponteiro para a fila                *
 * saída   : situação vazia ou não               *
 *************************************************/
int isEmpty( QUEUE* q ) {
  if ( q->fim == -1 )
    return 1;
  else
    return 0;
}


/*************************************************
 * insereFila                                    *
 * objetivo: insere vértice no fim               *
 * entrada : ponteiro para a fila e vértice      *
 * saída   : fila com novo vértice               *
 *************************************************/
void enqueue( QUEUE* q, int value ) {
  if ( q->fim == MAX - 1 )
    printf( "\nQueue is Full!!" );
  else {
    if ( q->inicio == - 1 )
      q->inicio = 0;
    q->fim++;
    q->itens[q->fim] = value;
  }
}


/*************************************************
 * removeFila                                    *
 * objetivo: remove vértice do início            *
 * entrada : ponteiro para a fila                *
 * saída   : fila com vértice do início removido *
 *************************************************/
int dequeue( QUEUE* q ) {
  int item;
  if ( isEmpty( q ) ) {
    printf( "Queue is empty" );
    item = -1;
  } else {
    item = q->itens[q->inicio];
    q->inicio++;
    if (q->inicio > q->fim) {
      printf( "Resetting queue " );
      q->inicio = q->fim = -1;
    }
  }
  return item;
}


/*************************************************
 * imprimeFila                                   *
 * objetivo: mostra elementos da fila            *
 * entrada : ponteiro para a fila                *
 * saída   : fila com novo vértice               *
 *************************************************/
void printQueue( QUEUE* q ) {
  int i = q->inicio;

  if ( isEmpty( q ) ) {
    printf( "Queue is empty" );
  } else {
    printf( "\nQueue contains " );
    for ( i = q->inicio; i < q->fim + 1; i++ ) {
      printf( "%d ", q->itens[i] );
    }
  }
}
