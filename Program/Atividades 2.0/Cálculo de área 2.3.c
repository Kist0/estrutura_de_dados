#include <stdio.h>

void main () {
	float area;
    int base, altura;

    printf("Insira o valor da altura do triangulo: ");
    scanf("%d", &base);
    printf("Insira o valor da base do triangulo: ");
    scanf("%d", &altura);

    area = base * altura / 2;

    printf("A area do triangulo equivale a %.2f .", area);}
