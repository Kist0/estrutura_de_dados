#include <stdio.h>

void main() {
	int i, n;

	printf("Digite um número: ");
	scanf("%d, ", &n);
	
	for (i=1; i<=n; i++) {
		if (i == n)
			printf("%d", i);
		else
			printf("%d, ", i);
	}
	printf("\n");
	
	for (i=n; i >=0; i--) {
		if (i == 0)
			printf("%d", i);
		else
		printf("%d, ", i);
	}
	printf("\n");
	
	for (i=0; i<=n; i+=2) {
		if (i == n || i == n-1)
			printf("%d", i);
		else
			printf("%d, ", i);
	}
	printf("\n");
}
