//Sistema bancário com as principais operações disponíveis para fazer em um caixa eletrônico
//Criado por Eduardo Bastos e Victor Kist 

#include <stdio.h>
#include <locale.h>
#include <string.h>

#define QTD_CONTA 100

//Criação dos tipos
typedef struct Conta {
	char titular[50];
	char cpf[11];
	float saldo;
	int posicao;
} Conta;

typedef struct ListaContas {
	Conta contas[QTD_CONTA];
    int tamanho;
} ListaContas;


//Protótipos
int imprimeMenuOperacao();																				//Mostra o menu e retorna a 'opcao'
int imprimeMenuConta();																					//Mostra o menu e retorna a 'opcao2'
int procuraConta(ListaContas lista);																	//Por meio do CPF (solicitado na função) encontra a conta na lista

//Protótipos das operações
ListaContas criaConta(ListaContas lista);																//Criação de uma conta (CPF, titular)
ListaContas excluiConta(ListaContas lista);																//Exclusão de uma conta
void extratoBancario(Conta conta);																		//Verificação do extrato bancário
Conta depositoBancario(Conta conta);																	//Depositar um valor na conta
Conta saqueBancario(Conta conta);																		//Sacar um valor da conta
ListaContas transferenciaBancaria(ListaContas lista, int posicao);										//Transferência de um valor para outra conta
void listaDadosBancarios(ListaContas lista);															//Listar todos os dados dos usuários

//Painel
void imprimeCabecalho();																				//Impressão do
void imprimeDados(ListaContas lista);																	//painel da função
void imprimeRodape();																					//listaDadosBancarios

int main() {
	// setlocale(LC_ALL, "portuguese");
	ListaContas lista;																					//Criação da variável lista (base de todo o programa)
    lista.tamanho = 0;																					//Definindo o tamanho inicial como zero

	int opcao, opcao2 = 0;																				//Criação das variáveis para opções dos menus
	int posicaoConta;																					//Criação da variável para acessar rapidamente a conta

	do {																								//Do while para repetir os menus
		opcao = imprimeMenuOperacao();																	//Chamar a função e armazenar em 'opcao'
		switch (opcao) {
			case 1:																						//Opção de criar a conta
				if (lista.tamanho <= QTD_CONTA)															//Se não estiver cheio
					lista = criaConta(lista);															//Chama a função
				else
					printf("Lista lotada\n");															//Caso estiver lotada, mostra a mensagem
				break;

			case 2:																						//Opção de excluir a conta
				if (lista.tamanho != 0)																	//Verificar se tem contas na lista
					lista = excluiConta(lista);															//Se tiver, chama a função
				else
					printf("\nNão existe nenhuma conta criada no momento");								//Caso não tiver, mostra a mensagem
				break;

			case 3:																						//Opção de acessar uma das contas
				if (lista.tamanho != 0) {																//Verificar se tem contas na lista
					posicaoConta = procuraConta(lista);													//Verifica se existe o CPF cadastrado
					if (posicaoConta != -1)																//Se existir o CPF informado
						opcao2 = imprimeMenuConta();													//chama a fução imprimeMenuConta e atualiza a var 'opcao2'
					else
						printf("\nNão existe nenhuma conta para o cpf informado");						//Se nãso existir o CPF informado, mostra a mensagem
				} else
					printf("\nNão existe nenhuma conta criada no momento");								//Caso não tiver contas, mostra a mensagem
				break;

			case 4:																						//Opção de listar os dados bancários de todos os cadastros
				if (lista.tamanho != 0)																	//Se existir cadastros
					listaDadosBancarios(lista);															//Chama a função
				else
					printf("\nNão existe nenhuma conta criada no momento");								//Se não existir cadastros, mostra a mensagem
				break;

			default:																					//Caso for 0
				printf("\nSaindo do programa");															//Fecha o programa
				break;
		}

		if (opcao2 != 0) {
			do  {
				switch (opcao2) {
					case 1:																				//Mostra o extrato bancário do usuário
						extratoBancario(lista.contas[posicaoConta]);									//Chamada da função
						break;
					case 2:																				//Faz um depósito na conta do usuário
						lista.contas[posicaoConta] = depositoBancario(lista.contas[posicaoConta]);		//Chamada da função
						break;
					case 3:																				//Faz um saque na conta do usuário
						lista.contas[posicaoConta] = saqueBancario(lista.contas[posicaoConta]);			//Chamada da função
						break;
					case 4:																				//Faz um depósito da conta do usuário para outro CPF informado
						lista = transferenciaBancaria(lista, posicaoConta);								//Chamada da função
						break;
					default:
						break;
				}
				
				opcao2 = imprimeMenuConta();															//Mostra novamente o menu
			} while (opcao2 != 0);																		//Enquando a opção do usuário não for zero, o menu da conta aparece
			opcao2 = 0;
		}

	} while(opcao != 0);																				//Enquando a opção do usuário não for zero, o menu da operação aparece
	
    return 0;
}

/****************************************************
 * imprimeMenuOperacao								*
 * objetivo: Imprimir o menu da operação			*
 * entrada :										*
 * retorno : dados em tela + opção do usuário		*
 ****************************************************/

int imprimeMenuOperacao() {
	int opcao;

	printf(	"\n\nBem vindo ao Banco do Kist :)\n"
			"[1] Criar conta\n"
			"[2] Exclui conta\n"
			"[3] Acessar conta\n"
			"[4] Listar todas as contas\n"
			"[0] Sair\n"
			"\nOpção: ");
			scanf("%d", &opcao);																		//É escaneado uma opção
			return opcao;																				//Retorna a opção para o switch da main
}

/****************************************************
 * criaConta										*
 * objetivo: Criar uma conta						*
 * entrada : Lista									*
 * retorno : Lista com uma conta adicionada			*
 ****************************************************/

ListaContas criaConta(ListaContas lista) {
	
	char titular[50];																					//Variável para armazenar o nome
	int i, verificacao = 1;																				//Variáveis contadora e verificadora

	printf("\nDigite seu CPF: ");																		//Solicitação do CPF para armazenar na conta
	fflush(stdin);
	scanf("%s", &lista.contas[lista.tamanho].cpf);

	if (strlen(lista.contas[lista.tamanho].cpf) != 11) {												//If para verificar se o CPF informado possi 11 dígitos
		while (strlen(lista.contas[lista.tamanho].cpf) != 11) {											//While para pedir novamente o cpf até estar com 11 dígitos
			printf("\nCPF não possui 11 digítos, digite novamente: ");
			scanf("%s", &lista.contas[lista.tamanho].cpf);
		}
	}
		
	for (i = 0; i < lista.tamanho; i++) {																//For e if para verificar se não existe um CPF igual já cadastrado
		if(strcmp(lista.contas[i].cpf, lista.contas[lista.tamanho].cpf) == 0)
			verificacao = 0;
	}

	if (verificacao == 1) {																				//Caso não exista um CPF igual é solicitado o nome
		printf("\nDigite seu nome: ");
		fflush(stdin);
		scanf("%[^\n]", &lista.contas[lista.tamanho].titular);											//Armazenar o nome na conta | %[^\n] == armazenar nome com espaço
		lista.contas[lista.tamanho].saldo = 0;															//Definição do saldo para zero
		lista.contas[lista.tamanho].posicao = lista.tamanho;											//Definição da posição da conta na lista
		lista.tamanho++;																				//Tamanho da lista aumenta de tamanho

	} else 
		printf("\nJá existe uma conta com esse cpf");													//Caso exista um CPF já igual é mostrada a mensagem
	
    return lista;
}

/****************************************************
 * excluiConta										*
 * objetivo: Exclui uma conta						*
 * entrada : Lista									*
 * retorno : Lista com uma conta excluida			*
 ****************************************************/

ListaContas excluiConta(ListaContas lista) {
	int posicaoConta, i;																				//Criação da variável para acessar rapidamente a conta e contadora

	posicaoConta = procuraConta(lista);
	if (posicaoConta != -1) {																			//If para verificar se foi achado uma conta
		for (i = posicaoConta; i < lista.tamanho; i++) {												//For para realocar a posição das contas na lista
			lista.contas[i] = lista.contas[i+1];
			lista.contas[i].posicao--;
		}

   		lista.tamanho--;																				//Diminuição do tamanho da lista
		printf("\nConta excluída");
	}
	else
		printf("\nNão existe nenhuma conta para o cpf informado");										//Se não foi achado uma conta, mostra a mensagem

	return lista;
}

/********************************************************
 * procuraConta											*
 * objetivo: Procurar uma conta							*
 * entrada : Lista										*
 * retorno : Posição da conta na lista. -1 inexistente	*
 ********************************************************/

int procuraConta(ListaContas lista) {
	char cpf[11];
    int i, posicaoConta = -1;																			//Variáveis contadora e -1 por padrao na posicaoConta

    printf("\nInforme o cpf da conta que deseja: ");
    scanf("%s", &cpf);																					//CPF informado pelo usuário

    for(i = 0; i < lista.tamanho; i++) {																//Verifica em toda a lista se
        if(strcmp(lista.contas[i].cpf, cpf) == 0)														//CPF informado existe na lista
            posicaoConta = lista.contas[i].posicao;														//Se sim, posicaoConta recebe a posição dela
    }
    
    return posicaoConta;
}

/****************************************************
 * imprimeMenuConta									*
 * objetivo: Imprimir o menu da conta				*
 * entrada :										*
 * retorno : dados em tela + opção do usuário		*
 ****************************************************/

int imprimeMenuConta() {
	int opcao2;
	
	printf(	"\n\nEscolha a opção desejada:\n"
			"[1] Extrato\n"
			"[2] Depóstio\n"
			"[3] Saque\n"
			"[4] Transferência\n"
			"[0] Voltar ao menu\n"
			"\nOpção: ");
			scanf("%d", &opcao2);																		//É escaneado uma opção
			return opcao2;																				//Retorna a opção para o switch da main
}

/****************************************************
 * extratoBancario									*
 * objetivo: Mostrar o valor na conta				*
 * entrada : conta do usuário						*
 * retorno : print com o saldo						*
 ****************************************************/

void extratoBancario(Conta conta) {
	printf("\nO saldo da sua conta corresponde a: R$ %.2f", conta.saldo);
}

/****************************************************
 * depositoBancario									*
 * objetivo: Depositar um valor na conta			*
 * entrada : conta do usuário						*
 * retorno : conta com o valor adicionado			*
 ****************************************************/

Conta depositoBancario(Conta conta) {
    float valor;
    printf("\nInforme a quantidade em reais que deseja depoistar na conta: ");
    scanf("%f", &valor);																				//Escaneia o valor a ser adicionado
    if(valor > 0 )																						//Verifica se a quantidade é maior do que zero
		conta.saldo += valor;
	else																								//Armazena na conta
		printf("\nVocê não pode inserir um valor menor que 0");

    return conta;
}

/****************************************************
 * saqueBancario									*
 * objetivo: Sacar um valor da conta				*
 * entrada : conta do usuário						*
 * retorno : conta com o valor sacado				*
 ****************************************************/

Conta saqueBancario(Conta conta) {
    float valor;
    printf("\nInforme a quantidade em reais que deseja sacar da conta: ");
    scanf("%f", &valor);																				//Escaneia o valor a ser sacado
    if (conta.saldo - valor >= 0)																		//Se o saldo - valor for maior que zero
        conta.saldo -= valor;																			//Saldo perde o valor sacado
    else																								//Caso o saldo - valor for menor que zero
        printf("\nVocê não possui saldo o suficiente para realizar um saque neste valor");				//Mostra a mensagem

    return conta;
}

/****************************************************
 * transferenciaBancaria							*
 * objetivo: Transferir um valor da conta			*
 * entrada : lista e posição da conta				*
 * retorno : Valores alterados nas contas			*
 ****************************************************/

ListaContas transferenciaBancaria(ListaContas lista, int posicao) {
    int posicaoConta;
	float valor;

    posicaoConta = procuraConta(lista);																	//Localiza a posição

	if (posicaoConta != -1) {																			//Se encontrar a conta
		if (posicaoConta != posicao) {																	//Se a conta não for a mesma
    		printf("\nInforme a quantidade em reais que deseja transferir da conta: ");
    		scanf("%f", &valor);																		//É solicitado o valor a transferir
			if (lista.contas[posicao].saldo - valor >= 0) {												//Se o saldo - valor for maior que zero
       			lista.contas[posicao].saldo -= valor;													//O saldo na conta é excluido
				lista.contas[posicaoConta].saldo += valor;												//O saldo na conta do destinatário e adicionado
			} else																						//Se o saldo - valor for menor que zero, mostra a mensagem
        		printf("\nVocê não possui saldo o suficiente para realizar uma transferência neste valor");
		} else																							//Se a conta for a mesma, mostra a mensagem
			printf("\nVocê não pode transferir para sua própria conta");
	} else
		printf("\nNão existe nenhuma conta para o cpf informado");										//Se não encontrar a conta, mostra a mensagem

	return lista;
}

/****************************************************************************
 * listaDadosBancarios + imprimeCabecalho + imprimeDados + imprimeRodape	*
 * objetivo: Listar todos os dados dos usuários com o painel				*
 * entrada : lista															*
 * retorno : Impressão do painel											*
 ****************************************************************************/

void listaDadosBancarios(ListaContas lista) {
	imprimeCabecalho();
	imprimeDados(lista);
	imprimeRodape();
}

void imprimeCabecalho() {
	int i;
	printf("\n");
	printf("%c", 201);
	for (i = 0; i < 50; i++) {
		printf("%c", 205);
	}
	printf("%c", 203);
	for (i = 0; i < 13; i++) {
		printf("%c", 205);
	}
	printf("%c", 203);
	for (i = 0; i < 12; i++) {
		printf("%c", 205);
	}
	printf("%c\n", 187);

	printf("%c", 204);
	printf("%-50s", "Nome do Titular");
	printf("%c", 186);
	printf("%-13s", "CPF");
	printf("%c", 186);
	printf("%12s", "Saldo");
	printf("%c\n", 185);

	printf("%c", 204);
	for (i = 0; i < 50; i++) {
		printf("%c", 205);
	}
	printf("%c", 206);
	for (i = 0; i < 13; i++) {
		printf("%c", 205);
	}
	printf("%c", 206);
	for (i = 0; i < 12; i++) {
		printf("%c", 205);
	}
	printf("%c\n", 185);
}

void imprimeDados(ListaContas lista) {
	int i;

	for (i = 0; i < lista.tamanho; i ++) {																//For para percorrer todas as contas e mostrar os dados
		printf("%c", 186);
		printf("%-50s", lista.contas[i].titular);
		printf("%c", 186);
		printf("%-13s", lista.contas[i].cpf);
		printf("%c", 186);
		printf("%12.2f", lista.contas[i].saldo);
		printf("%c\n", 186);
	}
}

void imprimeRodape() {
	int i;
	printf("%c", 200);
	for (i = 0; i < 50; i++) {
		printf("%c", 205);
	}
	printf("%c", 202);
	for (i = 0; i < 13; i++) {
		printf("%c", 205);
	}
	printf("%c", 202);
	for (i = 0; i < 12; i++) {
		printf("%c", 205);
	}
	printf("%c\n\n\n", 188);
}