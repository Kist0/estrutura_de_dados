#include <stdio.h>

void main (){
	float sal;
	
	printf("Qual o sal�rio do funcionario? ");
	scanf("%f", &sal);
	sal = sal * 1.2;
	
	printf("o novo sal�rio do funcionario � R$ %.2f", sal);
}
