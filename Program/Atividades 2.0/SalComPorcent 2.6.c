#include <stdio.h>

void main () {
    float sal, aum;
	
    printf("Informe o salario do funcionario: ");
    scanf("%f", &sal);
    printf("Informe o aumento do salario em porcentagem: ");
    scanf("%f", &aum);
	
    sal += sal * (aum / 100);
	
    printf("O novo salario corresponde a %.2f", sal);
}
