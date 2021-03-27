#include <stdio.h>

void main (){
	float sal;
	
	printf("Qual o salário do funcionario? ");
	scanf("%f", &sal);
	sal = sal * 0.98;
	
	printf("O novo salário do funcionario, com impostos inluidos é R$ %.2f", sal);
}
