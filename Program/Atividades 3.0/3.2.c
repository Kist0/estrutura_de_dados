#include <stdio.h>
 
void main() {
	int a, b, x;
	
	printf("Digite 2 numeros: ");
	scanf("%d %d", &a, &b);
	if(a%2 == 0 && b%2 == 0){
		x = (a + b);
		printf("A soma dos numeros eh: %d", x);
		}
	else{
		x = a * b;
		printf("O produto dos numeros eh: %d", x);
		}
}
