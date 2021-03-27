#include <stdio.h>

void main (){
	float sal;
	
	printf("Qual o salário do funcionario? ");
	scanf("%f", &sal);
	sal = sal * 1.2;
	
	printf("o novo salário do funcionario é R$ %.2f", sal);
}
