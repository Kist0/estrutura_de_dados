#include <stdio.h>

void main() {
	int num, s=0;
	
	do {
		printf("Digite um número ");
		scanf("%d", &num);
		fflush(stdin);
		if (num >= 1 && num <= 100)
			s += num;
	}while (num > 0);
	printf("%d\n", s);
}
