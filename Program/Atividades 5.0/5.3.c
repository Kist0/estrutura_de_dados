#include <stdio.h>

void main() {
	int i, vetor [10] =  {-1, 8, 9, -8, -777, 6, 4, 0, 3, 777};
	
	for (i=0; i<=10; i++) {
		if (vetor[i] < 0)
			printf("valor negativo %d encontra-se na posição %d \n", vetor[i], i);
	}
}
