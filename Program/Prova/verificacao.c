#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

int validaEmail(char email[]);
int validaSenha(char senha[]);

void main(){
	char email[MAX], senha[MAX];
	int ok;
	
	do{
		printf("\nInforme seu e-mail para o cadastro: ");
		scanf("%s", &email);
		ok = validaEmail(email);
	}while(!ok);///enquanto não estiver correto, vou pedir novamente
	
	do{
		printf("\nInforme uma senha para o cadastro: ");
		scanf("%s", &senha);
		ok = validaSenha(senha);
	}while(!ok);///enquanto não estiver correto, vou pedir novamente
	
	printf("E-mail e senha sao validos para cadastro");
}

int validaEmail(char email[]) {
	int contarrb=0, i, t, contt, ok=0;
	
	t = strlen(email);
	
	for (i=0; i<t; i++)
        email[i] = tolower(email[i]);
	
	for (i=0; i<t; i++) {
        if (email[i] == '@')
			contarrb += 1;
	}
	
    for (i=0; i<t; i++) {
        if (email[i] == 'a'|| 'b'|| 'c'|| 'd'|| 'e'|| 'f'|| 'g'|| 'h'|| 'i'|| 'j'|| 'k'|| 'l'|| 'm'|| 'n'|| 'o'|| 'p'|| 'q'|| 'r'|| 's'|| 't'|| 'u'|| 'v'|| 'x'|| 'y'|| 'w'|| 'z'|| '1'|| '2'|| '3'|| '4'|| '5'|| '6'|| '7'|| '8'|| '9'|| '0'|| '_'|| '.'|| '@')
    		ok = 1;
    	else
    		return 0;
	}

	if (ok =! 0 && contarrb == 1)
		return 1;
	else
		return 0;
    }

int validaSenha(char senha[]) {
	int contmaiu=0, contnum, i;
	
	int t = strlen(senha);
	
	if (t >= 6) {
		
		for (i=0; i<t; i++) {
	        if (senha[i] == 'A' || 'B' || 'C' || 'D' || 'E' || 'F' || 'G' || 'H' || 'I' || 'J' || 'K' || 'L' || 'M' || 'N' || 'O' || 'P' || 'Q' || 'R' || 'S' || 'T' || 'U' || 'V' || 'W' || 'X' || 'Y' || 'Z')
				contmaiu += 1;
		}
		
		for (i=0; i<t; i++) {
	        if (senha[i] == '0' || '1' || '2' || '3' || '4' || '5' || '6' || '7' || '8' || '9')
				contnum += 1;
		}
		
		if (contmaiu >= 1 && contnum >= 1)
			return 1;
		else
			return 0;
	}
	
	else
		return 0;
}
