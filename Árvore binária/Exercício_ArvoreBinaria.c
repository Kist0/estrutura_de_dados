/***********************************************/
/* �rvores Bin�rias                            */
/* objetivo: registro de c�digos               */
/* programador: Daniela Bagatini               */
/* criado em: 11/11/2020                       */
/* data da �ltima altera��o: 11/11/2020        */
/***********************************************/

#include <stdio.h>  // printf e scanf
#include <conio.h>  // getch
#include <stdlib.h> // exit
//#include <string.h>
#include <locale.h> // setlocale

/***********************************************/
/* Defini��o dos Registros                     */
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
/* Defini��o das Fun��es                       */
/***********************************************/
void entrada_dados(ARVORE *aux);               // leitura dos dados de entrada
void imprime_ARVORE(ARVORE *aux);              // visualiza��o da �rvore em tela, todos os registros
void cria_ARVORE(ARVORE **r);                  // inicializa �rvore com NULL
void insere_recursivo(ARVORE **r, int cod);    // inclui um novo registro na �rvore
ARVORE *busca_recursivo(ARVORE *p, int cod);   // procura na �rvore um c�digo
ARVORE *remove_recursivo(ARVORE **p, int cod); // exclui um regitro por c�digo
ARVORE *MaiorDireita(ARVORE **p);
ARVORE *busca_sucessor(ARVORE *p, int cod);

void calcula_altura(ARVORE **r);         // calcula e atualiza a altura e fator de balancemaento de um nodo
int altura_arvore(ARVORE *p);            // atualiza a altura do nodo
void verifica_balanceamento(ARVORE **r); // verifica balanceamento de cada nodo da �rvore
void rotacao_direita(ARVORE **p);        // rota��o para balanceamento
void rotacao_esquerda(ARVORE **p);       // rota��o para balanceamento

/***********************************************/
/* Programa Principal                          */
/***********************************************/
int main(void)
{
        char op;       // op��o do menu
        ARVORE *r, *p; // declara��o da ARVORE, vari�vel do tipo ARVORE = ARVORE de ponteiros
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
                op = getche(); // tecla de op��o do menu

                switch (op)
                {
                case '1': // rotina cria ARVORE
                        cria_ARVORE(&r);
                        break;

                case '2': // rotina imprime nodos da ARVORE
                        if (r != NULL)
                                imprime_ARVORE(r);
                        else
                                printf("\n �rvore vazia!");
                        break;

                case '3': // rotina recursiva do inclui nodo da ARVORE
                        printf("\n Digite o novo codigo: ");
                        scanf("%d", &cod);
                        insere_recursivo(&r, cod);
                        calcula_altura(&r); // calcula e armazena a altura de cada n�
                        // verifica_balanceamento(&r); // verifica balanceamento da �rvore
                        break;

                case '4': // rotina recursiva que busca um registro da ARVORE
                        if (r != NULL)
                        {

                                printf("\n Buscar o codigo: ");
                                scanf("%d", &cod);
                                p = busca_recursivo(r, cod); // busca c�digo na �rvore e retorno ponteiro do registro quando encontrado, caso n�o encontre retorna NULL
                                if (p != NULL)
                                        printf("\n Codigo: %d", p->info.codigo);
                                else
                                        printf("\n Registro n�o encontrado!");
                        }
                        else
                                printf("\n �rvore vazia!");
                        break;

                case '5': // rotina recursiva que busca um registro da ARVORE
                        if (r != NULL)
                        {
                                printf("\n Remove codigo: ");
                                scanf("%d", &cod);
                                p = remove_recursivo(&r, cod); // remove registro que cont�m o c�digo e retorna a ra�z
                                calcula_altura(&r);            // calcula e armazena a altura de cada n�
                        }
                        else
                                printf("\n �rvore vazia!");
                        break;

                case '6': // rotina recursiva que ...
                        // inclua nova fun��o aqui!;
                        if (r != NULL)
                        {
                                printf("\n Buscar o sucessor do c�digo: ");
                                scanf("%d", &cod);
                                p = busca_sucessor(r, cod);

                                if (p != NULL)
                                        printf("\n Sucesso da �rvode do codigo %d: %d", cod, p->info.codigo);
                                else
                                        printf("\n Sucessor n�o encontrado");
                        }
                        else
                                printf("\n �rvore vazia!");
                        break;

                case '0': // t�rmino do programa
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
 * sa�da   : nodo com dados                      *
 ************************************************/
void entrada_dados(ARVORE *aux)
{
        /*  printf( "\n\n C�digo: %d", aux->info.codigo ); */
        aux->subd = NULL; // n�o aponta
        aux->sube = NULL; // n�o aponta
}

/*************************************************
 * imprime_ARVORE                                *
 * objetivo: rotina para imprimir dados          *
 * entrada : ARVORE                              *
 * sa�da   : dados em tela                       *
 *************************************************/
void imprime_ARVORE(ARVORE *aux)
{

        if (aux != NULL)
        { // verifica se a raiz � diferente de vazio
                printf("\n C�digo.....: %d", aux->info.codigo);
                printf("\n Altura.....: %d", aux->info.altura);
                printf("\n Fatbal.....: %d", aux->info.fatbal);
                getchar();
                printf("\n >> sube");
                imprime_ARVORE(aux->sube); // recursivo, segue pelo caminho da esquerda
                printf("\n >> subd");
                imprime_ARVORE(aux->subd); // recursivo, segue pelo caminho da direita
        }
        else
                printf("\n �rvore vazia!");
}

/*************************************************
 * cria_ARVORE                                   *
 * objetivo: rotina para inicializar a ARVORE    *
 * entrada : nenhuma                             *
 * sa�da   : NULL (inicializa ARVORE)            *
 ************************************************/
void cria_ARVORE(ARVORE **r)
{
        *r = NULL; // arvore criada, raiz nao aponta
}

/************************************************* 
 * insere_recursivo                              *
 * objetivo: rotina para inserir no fim da ARVORE*
 * entrada : ARVORE e cod                        *
 * sa�da   : ARVORE com mais um registro         *
 *************************************************/
void insere_recursivo(ARVORE **p, int cod)
{

        if (*p == NULL)
        {                                                      // se n�o achou o c�digo, insere
                ARVORE *no = (ARVORE *)malloc(sizeof(ARVORE)); // aloca novo espaco em mem�ria
                no->info.codigo = cod;
                no->subd = NULL; // inicializa sub�rvore da direita
                no->sube = NULL; // inicializa sub�rvore da esquerda
                *p = no;         // anterior aponta para novo registro
                printf("\n Registro inserido!");
        }
        else
        {
                if ((*p)->info.codigo > cod)                // verifica se c�digo a ser inserido � menor que o valor do registro para qual o p aponta
                        insere_recursivo(&(*p)->sube, cod); // anda com o ponteiro p para a esquerda, pois o c�digo procurado � menor
                else if ((*p)->info.codigo < cod)           // verifica se c�digo a ser inserido � maior que o valor do registro para qual o p aponta
                        insere_recursivo(&(*p)->subd, cod); // anda com o ponteiro p para a direita, pois o c�digo procurado � maior
                else
                        printf("\n Registro j� existe!");
        }
} // desempilha

/* INSERE N�O RECURSIVO
void insere( ARVORE** r ){
    ARVORE* p;      // ponteiro auxiliar
    ARVORE* a;      // ponteiro auxiliar para anterior de p (nodo pai)
    int cod, achou; // cod = dado de entrada; achou = informa se c�digo j� existe na estrutura

    printf("\n Digite o novo c�digo: ");
    scanf("%d", &cod);
    
    p = *r;                            // posiciona ponteiro auxiliar
    achou = busca( cod, &a, &p );      // verifica se c�digo a ser inserido j� existe na �rvore, "a" � o nodo pai
    if( !achou ){                      // se n�o achou o c�digo, insere
         ARVORE* no = ( ARVORE * ) malloc ( sizeof( ARVORE )); // aloca novo espaco em mem�ria

         if( no != NULL ){             // se conseguiu alocar mem�ria, insere
                 no->info.codigo = cod;// preenche o novo registro com o c�digo j� informado
                 entrada_dados( no );  // entrada do usu�rio
                 if( *r == NULL )      // verifica se a �rvore esta vazia
                     *r = no;          // o registro sera o primeiro, atualiza a raiz
                 else 
                      if ( no->info.codigo > a->info.codigo )
                           a->subd = no; // insere a direita do registro folha
                      else
                           a->sube = no; // insere a esquerda do registro folha
         } // fim if( no != NULL )
    } // fim if( !achou )
    else
        printf( "\n Registro j� existe!" );
*/

/***************************************************
 * busca_recursivo                                 *
 * objetivo: rotina para buscar registro por c�digo*
 * entrada : ARVORE e cod                          *
 * sa�da   : ARVORE com mais um registro           *
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
 * objetivo: rotina para remover registro por c�digo*
 * entrada : ARVORE e cod                           *
 * sa�da   : ARVORE com registro removido           *
 ****************************************************/
ARVORE *remove_recursivo(ARVORE **p, int cod)
{
        ARVORE *aux = *p;
        ARVORE *aux2 = *p;
        // Vai andar at� encontar o valor
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
 * objetivo: rotina para calcular a altura da �rvore*
 * entrada : ARVORE                                 *
 * sa�da   : ARVORE com campo altura atualizado     *
 ****************************************************/
void calcula_altura(ARVORE **r)
{
        ARVORE *aux = *r; // ponteiro auxiliar para percorrer a �rvore

        if (aux != NULL)
        {                                                                                           // verifica se a raiz � diferente de NULL
                aux->info.altura = altura_arvore(aux);                                              // verifica a altura do n�
                aux->info.fatbal = (altura_arvore(aux->subd) + 1) - (altura_arvore(aux->sube) + 1); // calcula fator de balanceamento (fatbal) do n�
                //printf("\n Cod:%i  A:%i  Fatbal:%i  \n", aux->info.codigo, aux->info.altura, fatbal);
                calcula_altura(&aux->subd); // recursivo, segue pelo caminho da direita do n�
                calcula_altura(&aux->sube); // recursivo, segue pelo caminho da esquerda do n�
        }
}

/****************************************************
 * verifica_balanceamento                           *
 * objetivo: rotina para calcular o balancemaneto   *
 * entrada : ARVORE                                 *
 * sa�da   : ARVORE balanceada                      *
 ****************************************************/
void verifica_balanceamento(ARVORE **r)
{
        ARVORE *aux = *r; // cria ponteiro auxiliar para percorrer a �rvore

        if (aux != NULL)
        { // verifica se ponteiro � diferente de NULL
                if (aux->info.fatbal >= 2 && (aux->subd->info.fatbal != 2 && aux->subd->info.fatbal != -2))
                { // verifica fator de balanceamento no n� pai e filho, se n� pai for maior do que 1, a rota��o ser� � esquerda
                        if (aux->subd->info.fatbal < 0)
                        {                                    // se sinal do fatbal do n� filho for negativo, realiza rota��o dupla
                                rotacao_direita(&aux->subd); // rota��o esquerda - dupla
                                rotacao_esquerda(&aux);
                        }
                        else // se sinal do fatbal do n� filho for positivo, realiza rota��o simples
                                rotacao_esquerda(&aux);
                }
                else if (aux->info.fatbal <= -2 && (aux->sube->info.fatbal != 2 && aux->sube->info.fatbal != -2))
                { // verifica fator de balanceamento no n� pai e filho, se n� pai for menor do que 1, a rota��o ser� � direita
                        if (aux->sube->info.fatbal > 0)
                        {                                     // se sinal do fatbal do n� filho for positvo, realiza rota��o dupla
                                rotacao_esquerda(&aux->sube); // rota��o direita - dupla
                                rotacao_direita(&aux);
                        }
                        else
                                rotacao_direita(&aux); // se sinal do fatbal do n� filho for positivo, realiza rota��o simples
                }
                else
                {
                        verifica_balanceamento(&aux->sube); // continua verificando balanceamento � esquerda
                        verifica_balanceamento(&aux->subd); // continua verificando balanceamento � direita
                }
                calcula_altura(&aux); // atualiza a altura dos n�s da �rvore ap�s rota��o
        }
        *r = aux; // atualiza a raiz ap�s rota��o
}

/****************************************************
 * altura_arvore                                    *
 * objetivo: rotina para atualizar a altura do nodo *
 * entrada : ARVORE                                 *
 * sa�da   : altura                                 *
 ****************************************************/
int altura_arvore(ARVORE *p)
{
        int altura_esq, altura_dir;
        if (p == NULL) // finaliza o percurso
                return -1;
        else
        {
                altura_dir = altura_arvore(p->subd); // percorre � direita
                altura_esq = altura_arvore(p->sube); // percorre � esquerda
                if (altura_dir > altura_esq)         // se altura da direita maior, soma mais um n�vel � direita
                        return altura_dir + 1;
                else // se altura da esquerda maior, soma mais um n�vel � esquerda
                        return altura_esq + 1;
        }
}

/****************************************************
 * rotacao_direita                                  *
 * objetivo: rotina para rotacionar �rvore          *
 * entrada : ARVORE                                 *
 * sa�da   : ARVORE rotacionada                     *
 ****************************************************/
void rotacao_direita(ARVORE **p)
{
        ARVORE *aux;
        if (*p != NULL)
        {                               // percurso at� NULL
                aux = (*p)->sube;       // aponta � esquerda
                (*p)->sube = aux->subd; // n� filho � direita
                aux->subd = *p;         // raiz passa a ser n� filho
                *p = aux;               // aux passa ser a nova raiz
        }
}

/****************************************************
 * rotacao_esquerda                                 *
 * objetivo: rotina para rotacionar �rvore          *
 * entrada : ARVORE                                 *
 * sa�da   : ARVORE rotacionada                     *
 ****************************************************/
void rotacao_esquerda(ARVORE **p)
{
        ARVORE *aux;
        if (*p != NULL)
        {                               // percurso at� NULL
                aux = (*p)->subd;       // ponteiro auxiliar � posicionado no n� filho da direita
                (*p)->subd = aux->sube; // ajusta apontamento, ponteiro direito pai aponta para ponteiro esquerdo do filho
                aux->sube = *p;         // ponteiro � esquerda no filho aponta para n� pai
                *p = aux;               // reposiciona p
        }
}

/****************************************************
 * busca_sucessor                                   *
 * objetivo: encontrar o sucessor do elemento       *
 * entrada : ARVORE e c�digo                        *
 * sa�da   : elemento sucessor                      *
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
