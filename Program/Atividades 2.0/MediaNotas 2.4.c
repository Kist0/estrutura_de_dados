#include <stdio.h>

void main () {
    float m, n1, n2, n3;

    printf("Informe as tres notas com pesos 2, 3 e 5, respectivamente\n");
    scanf("%f %f %f", &n1, &n2, &n3);

    m = ((n1 * 2) + (n2 * 3) + (n3 * 5)) / 10;

    printf("A media equivale a %.2f", m);
}
