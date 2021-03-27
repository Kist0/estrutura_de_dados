#include <stdio.h>

float pesoideal(float h, char s[1]){
	int k;
	float p;
	
	if (s == 'm')
		k = 4;
	else
		k = 2;
	p = h-100-((h-150)/k);
	return p;
}

void main(){
	char s;
	float p, h;
	
	printf("Informe a sua altura: ");
	scanf("%f", &h);
	printf("Informe o seu sexo (m/f): ");
	setbuf(stdin, NULL);
	scanf("%c", &s);
	p = pesoideal(h, s);
	printf("O peso ideal para sua altura eh %.2f", p);
}
