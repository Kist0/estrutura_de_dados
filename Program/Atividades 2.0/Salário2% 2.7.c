#include <stdio.h>

void main (){
	float sal;
	
	printf("Qual o sal�rio do funcionario? ");
	scanf("%f", &sal);
	sal = sal * 0.98;
	
	printf("O novo sal�rio do funcionario, com impostos inluidos � R$ %.2f", sal);
}
