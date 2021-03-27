#include <stdio.h>
 
void main() {
	float a, b, c, v;
	
	printf("Digite 3 numeros: ");
	scanf("%f %f %f", &a, &b, &c);
	if(a>b && a>c){
		v = a;
		printf("O valor A que custa R$%.2f é o mais caro", v);
	}
	else if(b>a && b>c){
		v = b;
		printf("O valor B que custa R$%.2f é o mais caro", v);
	}
	else(c>a && c>b);{
		v = c;
		printf("O valor C que custa R$%.2f é o mais caro", v);
 }
}
