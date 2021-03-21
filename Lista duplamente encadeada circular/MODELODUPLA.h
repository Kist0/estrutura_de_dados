/***********************************************/ 
/* Definição do Registro e da Estrutura        */
/* Profa Daniela Bagatini                      */
/***********************************************/ 
typedef struct{             // registro pessoa
       int  codigo;
       char nome[30];
}INFORMACAO;
       
typedef struct nodo {
       INFORMACAO info;     // dados do registro
       struct nodo* prox;   // ponteiro para o próximo registro
       struct nodo* ant;    // ponteiro para o registro anterior
}NODO; 
