/***********************************************/
/* Árvores Binárias                            */
/* objetivo: registro de códigos               */
/* programador: Daniela Bagatini               */
/* criado em: 11/11/2020                       */
/* data da última alteração: 11/11/2020        */
/***********************************************/

#include <stdio.h>  // printf e scanf
#include <conio.h>  // getch
#include <stdlib.h> // exit
//#include <string.h>
#include <locale.h> // setlocale

/***********************************************/
/* Definição dos Registros                     */
/***********************************************/
typedef struct
{ // registro
        int codigo;
        int altura; // utilizado para balanceamento
        int fatbal; // utilizado para balanceamento
} INFORMACAO;

typedef struct arv
{
        INFORMACAO info;  // dados do registro
        struct arv *subd; // ponteiro para o nodo da direita
        struct arv *sube; // ponteiro para o nodo da esquerda
} ARVORE;

/***********************************************/
/* Definição das Funções                       */
/***********************************************/
void entrada_dados(ARVORE *aux);               // leitura dos dados de entrada
void imprime_ARVORE(ARVORE *aux);              // visualização da árvore em tela, todos os registros
void cria_ARVORE(ARVORE **r);                  // inicializa árvore com NULL
void insere_recursivo(ARVORE **r, int cod);    // inclui um novo registro na árvore
ARVORE *busca_recursivo(ARVORE *p, int cod);   // procura na árvore um código
ARVORE *remove_recursivo(ARVORE **p, int cod); // exclui um regitro por código
ARVORE *MaiorDireita(ARVORE **p);
ARVORE *busca_sucessor(ARVORE *p, int cod);

void calcula_altura(ARVORE **r);         // calcula e atualiza a altura e fator de balancemaento de um nodo
int altura_arvore(ARVORE *p);            // atualiza a altura do nodo
void verifica_balanceamento(ARVORE **r); // verifica balanceamento de cada nodo da árvore
void rotacao_direita(ARVORE **p);        // rotação para balanceamento
void rotacao_esquerda(ARVORE **p);       // rotação para balanceamento

/***********************************************/
/* Programa Principal                          */
/***********************************************/
int main(void)
{
        char op;       // opção do menu
        ARVORE *r, *p; // declaração da ARVORE, variável do tipo ARVORE = ARVORE de ponteiros
        int cod;

        setlocale(LC_ALL, "Portuguese");
        cria_ARVORE( &r );
        while (1)
        {
                printf("\n /---------------------------------------------------/");
                printf("\n Programa de registros - Menu                         ");
                printf("\n [1] Cria ARVORE                                      ");
                printf("\n [2] Imprime                                          ");
                printf("\n [3] Insere recursivo                                 ");
                printf("\n [4] Busca recursivo                                  ");
                printf("\n [5] Remove recursivo                                 ");
                printf("\n [6] Busca sucessor                                   ");
                printf("\n [0] Para sair do programa                            ");
                printf("\n /---------------------------------------------------/");
                printf("\n Opcao: ");
                op = getche(); // tecla de opção do menu

                switch (op)
                {
                case '1': // rotina cria ARVORE
                        cria_ARVORE(&r);
                        break;

                case '2': // rotina imprime nodos da ARVORE
                        if (r != NULL)
                                imprime_ARVORE(r);
                        else
                                printf("\n Árvore vazia!");
                        break;

                case '3': // rotina recursiva do inclui nodo da ARVORE
                        printf("\n Digite o novo codigo: ");
                        scanf("%d", &cod);
                        insere_recursivo(&r, cod);
                        calcula_altura(&r); // calcula e armazena a altura de cada nó
                        // verifica_balanceamento(&r); // verifica balanceamento da árvore
                        break;

                case '4': // rotina recursiva que busca um registro da ARVORE
                        if (r != NULL)
                        {

                                printf("\n Buscar o codigo: ");
                                scanf("%d", &cod);
                                p = busca_recursivo(r, cod); // busca código na árvore e retorno ponteiro do registro quando encontrado, caso não encontre retorna NULL
                                if (p != NULL)
                                        printf("\n Codigo: %d", p->info.codigo);
                                else
                                        printf("\n Registro não encontrado!");
                        }
                        else
                                printf("\n Árvore vazia!");
                        break;

                case '5': // rotina recursiva que busca um registro da ARVORE
                        if (r != NULL)
                        {
                                printf("\n Remove codigo: ");
                                scanf("%d", &cod);
                                p = remove_recursivo(&r, cod); // remove registro que contém o código e retorna a raíz
                                calcula_altura(&r);            // calcula e armazena a altura de cada nó
                        }
                        else
                                printf("\n Árvore vazia!");
                        break;

                case '6': // rotina recursiva que ...
                        // inclua nova função aqui!;
                        if (r != NULL)
                        {
                                printf("\n Buscar o sucessor do código: ");
                                scanf("%d", &cod);
                                p = busca_sucessor(r, cod);

                                if (p != NULL)
                                        printf("\n Sucesso da árvode do codigo %d: %d", cod, p->info.codigo);
                                else
                                        printf("\n Sucessor não encontrado");
                        }
                        else
                                printf("\n Árvore vazia!");
                        break;

                case '0': // término do programa
                        exit(1);
                        break;

                default:
                        printf("\n Digite uma opcao!");
                        break;
                } // switch( op )

                fflush(stdin); // limpa buffer do teclado, funciona junto com entrada de dados
                getchar();     // parada da tela

                printf("\n");
        } // fim do while( 1 )

        return 0;
} // fim do programa principal

/************************************************* 
 * entrada_dados                                 *
 * objetivo: rotina para ler dados               *
 * entrada : nodo (ponteiro para o novo espaco)  *
 * saída   : nodo com dados                      *
 ************************************************/
void entrada_dados(ARVORE *aux)
{
        /*  printf( "\n\n Código: %d", aux->info.codigo ); */
        aux->subd = NULL; // não aponta
        aux->sube = NULL; // não aponta
}

/*************************************************
 * imprime_ARVORE                                *
 * objetivo: rotina para imprimir dados          *
 * entrada : ARVORE                              *
 * saída   : dados em tela                       *
 *************************************************/
void imprime_ARVORE(ARVORE *aux)
{

        if (aux != NULL)
        { // verifica se a raiz é diferente de vazio
                printf("\n Código.....: %d", aux->info.codigo);
                printf("\n Altura.....: %d", aux->info.altura);
                printf("\n Fatbal.....: %d", aux->info.fatbal);
                getchar();
                printf("\n >> sube");
                imprime_ARVORE(aux->sube); // recursivo, segue pelo caminho da esquerda
                printf("\n >> subd");
                imprime_ARVORE(aux->subd); // recursivo, segue pelo caminho da direita
        }
        else
                printf("\n Árvore vazia!");
}

/*************************************************
 * cria_ARVORE                                   *
 * objetivo: rotina para inicializar a ARVORE    *
 * entrada : nenhuma                             *
 * saída   : NULL (inicializa ARVORE)            *
 ************************************************/
void cria_ARVORE(ARVORE **r)
{
        *r = NULL; // arvore criada, raiz nao aponta
}

/************************************************* 
 * insere_recursivo                              *
 * objetivo: rotina para inserir no fim da ARVORE*
 * entrada : ARVORE e cod                        *
 * saída   : ARVORE com mais um registro         *
 *************************************************/
void insere_recursivo(ARVORE **p, int cod)
{

        if (*p == NULL)
        {                                                      // se não achou o código, insere
                ARVORE *no = (ARVORE *)malloc(sizeof(ARVORE)); // aloca novo espaco em memória
                no->info.codigo = cod;
                no->subd = NULL; // inicializa subárvore da direita
                no->sube = NULL; // inicializa subárvore da esquerda
                *p = no;         // anterior aponta para novo registro
                printf("\n Registro inserido!");
        }
        else
        {
                if ((*p)->info.codigo > cod)                // verifica se código a ser inserido é menor que o valor do registro para qual o p aponta
                        insere_recursivo(&(*p)->sube, cod); // anda com o ponteiro p para a esquerda, pois o código procurado é menor
                else if ((*p)->info.codigo < cod)           // verifica se código a ser inserido é maior que o valor do registro para qual o p aponta
                        insere_recursivo(&(*p)->subd, cod); // anda com o ponteiro p para a direita, pois o código procurado é maior
                else
                        printf("\n Registro já existe!");
        }
} // desempilha

/* INSERE NÃO RECURSIVO
void insere( ARVORE** r ){
    ARVORE* p;      // ponteiro auxiliar
    ARVORE* a;      // ponteiro auxiliar para anterior de p (nodo pai)
    int cod, achou; // cod = dado de entrada; achou = informa se código já existe na estrutura

    printf("\n Digite o novo código: ");
    scanf("%d", &cod);
    
    p = *r;                            // posiciona ponteiro auxiliar
    achou = busca( cod, &a, &p );      // verifica se código a ser inserido já existe na árvore, "a" é o nodo pai
    if( !achou ){                      // se não achou o código, insere
         ARVORE* no = ( ARVORE * ) malloc ( sizeof( ARVORE )); // aloca novo espaco em memória

         if( no != NULL ){             // se conseguiu alocar memória, insere
                 no->info.codigo = cod;// preenche o novo registro com o código já informado
                 entrada_dados( no );  // entrada do usuário
                 if( *r == NULL )      // verifica se a árvore esta vazia
                     *r = no;          // o registro sera o primeiro, atualiza a raiz
                 else 
                      if ( no->info.codigo > a->info.codigo )
                           a->subd = no; // insere a direita do registro folha
                      else
                           a->sube = no; // insere a esquerda do registro folha
         } // fim if( no != NULL )
    } // fim if( !achou )
    else
        printf( "\n Registro já existe!" );
*/

/***************************************************
 * busca_recursivo                                 *
 * objetivo: rotina para buscar registro por código*
 * entrada : ARVORE e cod                          *
 * saída   : ARVORE com mais um registro           *
 ***************************************************/
ARVORE *busca_recursivo(ARVORE *p, int cod)
{

        if (p == NULL)
                return NULL;
        else if (cod == p->info.codigo)
                return p;
        else if (cod > p->info.codigo)
                busca_recursivo(p->subd, cod); //direita
        else if (cod < p->info.codigo)
                busca_recursivo(p->sube, cod); //esquerda
} // desempilha

/****************************************************
 * remove_recursivo                                 *
 * objetivo: rotina para remover registro por código*
 * entrada : ARVORE e cod                           *
 * saída   : ARVORE com registro removido           *
 ****************************************************/
ARVORE *remove_recursivo(ARVORE **p, int cod)
{
        ARVORE *aux = *p;
        ARVORE *aux2 = *p;
        // Vai andar até encontar o valor
        if (p == NULL)
                return NULL;
        if (cod < (*p)->info.codigo)
                remove_recursivo(&(*p)->sube, cod);
        else if (cod > (*p)->info.codigo)
                remove_recursivo(&(*p)->subd, cod);
        else if (((*p)->sube == NULL) && ((*p)->subd == NULL))
        {
                free(aux);
                (*p) = NULL;
        }
        else if ((*p)->sube == NULL)
        {
                (*p) = (*p)->subd;
                aux->subd = NULL;
                free(aux);
                aux = NULL;
        }
        else if ((*p)->subd == NULL)
        {
                (*p) = (*p)->sube;
                aux->sube = NULL;
                free(aux);
                aux = NULL;
        }
        else
        {
                aux = aux->sube;
                while (aux->subd != NULL)
                {
                        aux2 = aux;
                        aux = aux->subd;
                }

                if (aux2->info.codigo != (*p)->info.codigo)
                {
                        if (aux->sube != NULL)
                                aux2->subd = aux->sube;
                        else 
                                aux2->subd = NULL;
                        aux->sube = (*p)->sube;
                }
                else
                        aux->sube = NULL;

                aux->subd = (*p)->subd;
                (*p)->sube = (*p)->subd = NULL;
                free((*p));
                *p = aux;
                aux = NULL;
        }
} // desempilha

/****************************************************
 * calcula_altura                                   *
 * objetivo: rotina para calcular a altura da árvore*
 * entrada : ARVORE                                 *
 * saída   : ARVORE com campo altura atualizado     *
 ****************************************************/
void calcula_altura(ARVORE **r)
{
        ARVORE *aux = *r; // ponteiro auxiliar para percorrer a árvore

        if (aux != NULL)
        {                                                                                           // verifica se a raiz é diferente de NULL
                aux->info.altura = altura_arvore(aux);                                              // verifica a altura do nó
                aux->info.fatbal = (altura_arvore(aux->subd) + 1) - (altura_arvore(aux->sube) + 1); // calcula fator de balanceamento (fatbal) do nó
                //printf("\n Cod:%i  A:%i  Fatbal:%i  \n", aux->info.codigo, aux->info.altura, fatbal);
                calcula_altura(&aux->subd); // recursivo, segue pelo caminho da direita do nó
                calcula_altura(&aux->sube); // recursivo, segue pelo caminho da esquerda do nó
        }
}

/****************************************************
 * verifica_balanceamento                           *
 * objetivo: rotina para calcular o balancemaneto   *
 * entrada : ARVORE                                 *
 * saída   : ARVORE balanceada                      *
 ****************************************************/
void verifica_balanceamento(ARVORE **r)
{
        ARVORE *aux = *r; // cria ponteiro auxiliar para percorrer a árvore

        if (aux != NULL)
        { // verifica se ponteiro é diferente de NULL
                if (aux->info.fatbal >= 2 && (aux->subd->info.fatbal != 2 && aux->subd->info.fatbal != -2))
                { // verifica fator de balanceamento no nó pai e filho, se nó pai for maior do que 1, a rotação será à esquerda
                        if (aux->subd->info.fatbal < 0)
                        {                                    // se sinal do fatbal do nó filho for negativo, realiza rotação dupla
                                rotacao_direita(&aux->subd); // rotação esquerda - dupla
                                rotacao_esquerda(&aux);
                        }
                        else // se sinal do fatbal do nó filho for positivo, realiza rotação simples
                                rotacao_esquerda(&aux);
                }
                else if (aux->info.fatbal <= -2 && (aux->sube->info.fatbal != 2 && aux->sube->info.fatbal != -2))
                { // verifica fator de balanceamento no nó pai e filho, se nó pai for menor do que 1, a rotação será à direita
                        if (aux->sube->info.fatbal > 0)
                        {                                     // se sinal do fatbal do nó filho for positvo, realiza rotação dupla
                                rotacao_esquerda(&aux->sube); // rotação direita - dupla
                                rotacao_direita(&aux);
                        }
                        else
                                rotacao_direita(&aux); // se sinal do fatbal do nó filho for positivo, realiza rotação simples
                }
                else
                {
                        verifica_balanceamento(&aux->sube); // continua verificando balanceamento à esquerda
                        verifica_balanceamento(&aux->subd); // continua verificando balanceamento à direita
                }
                calcula_altura(&aux); // atualiza a altura dos nós da árvore após rotação
        }
        *r = aux; // atualiza a raiz após rotação
}

/****************************************************
 * altura_arvore                                    *
 * objetivo: rotina para atualizar a altura do nodo *
 * entrada : ARVORE                                 *
 * saída   : altura                                 *
 ****************************************************/
int altura_arvore(ARVORE *p)
{
        int altura_esq, altura_dir;
        if (p == NULL) // finaliza o percurso
                return -1;
        else
        {
                altura_dir = altura_arvore(p->subd); // percorre à direita
                altura_esq = altura_arvore(p->sube); // percorre à esquerda
                if (altura_dir > altura_esq)         // se altura da direita maior, soma mais um nível à direita
                        return altura_dir + 1;
                else // se altura da esquerda maior, soma mais um nível à esquerda
                        return altura_esq + 1;
        }
}

/****************************************************
 * rotacao_direita                                  *
 * objetivo: rotina para rotacionar árvore          *
 * entrada : ARVORE                                 *
 * saída   : ARVORE rotacionada                     *
 ****************************************************/
void rotacao_direita(ARVORE **p)
{
        ARVORE *aux;
        if (*p != NULL)
        {                               // percurso até NULL
                aux = (*p)->sube;       // aponta à esquerda
                (*p)->sube = aux->subd; // nó filho à direita
                aux->subd = *p;         // raiz passa a ser nó filho
                *p = aux;               // aux passa ser a nova raiz
        }
}

/****************************************************
 * rotacao_esquerda                                 *
 * objetivo: rotina para rotacionar árvore          *
 * entrada : ARVORE                                 *
 * saída   : ARVORE rotacionada                     *
 ****************************************************/
void rotacao_esquerda(ARVORE **p)
{
        ARVORE *aux;
        if (*p != NULL)
        {                               // percurso até NULL
                aux = (*p)->subd;       // ponteiro auxiliar é posicionado no nó filho da direita
                (*p)->subd = aux->sube; // ajusta apontamento, ponteiro direito pai aponta para ponteiro esquerdo do filho
                aux->sube = *p;         // ponteiro à esquerda no filho aponta para nó pai
                *p = aux;               // reposiciona p
        }
}

/****************************************************
 * busca_sucessor                                   *
 * objetivo: encontrar o sucessor do elemento       *
 * entrada : ARVORE e código                        *
 * saída   : elemento sucessor                      *
 ****************************************************/

ARVORE *busca_sucessor(ARVORE *p, int cod)
{
        if (cod < p->info.codigo)
                busca_sucessor(p->sube, cod);
        else if (cod > p->info.codigo)
                busca_sucessor(p->subd, cod);
        else if ((p->sube == NULL) && (p->subd == NULL))
        {
                return NULL;
        }
        else if (p->sube == NULL)
        {
                return p->subd;
        }
        else if (p->subd == NULL)
        {
                return p->sube;
        }
        else
        {
                p = p->sube;
                while (p->subd != NULL)
                {
                        p = p->subd;
                }
                return p;
        }
}
