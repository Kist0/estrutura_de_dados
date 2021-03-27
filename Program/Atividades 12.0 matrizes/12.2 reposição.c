#include <stdio.h>

void main() {
	int v[18] = {3, 25, 12, 48, 51, 21, 10, 36, 21, 2, 57, 45, 21, 54, 58, 21, 11, 35};
	int matriz[3][6], i, j, k=0;
	
	/*for (i=0; i<3; i++) {
		for (j=0; j<6; j++) {
			if (i == 0)
				matriz[i][j] = v[j];
			else if (i == 1)
				matriz[i][j] = v[j+6];
			else
				matriz[i][j] = v[j+12];
		}
	}*/
	
	for (i=0; i<3; i++) {
		for (j=0; j<6; j++) {
				matriz[i][j] = v[k];
				k++;
		}
	}
	
	for (i=0; i<3; i++) {
		for (j=0; j<6; j++)
			printf("%d ", matriz[i][j]);
		printf("\n");
	}
}
