#include <stdio.h>
#include <string.h>

void main()
{
	char linha[] = {"111111111111111111111111111111111111111111111111111111111111111111110000000111110101100001000000011110111110110110011101111011111011110100010101000100000011010001011110100010101101010110011010001011110100010100010111000111010001011110111110110111010000111011111011110000000101010101010101000000011111111111111111100111011111111111110001100000110110000000110001111110110101011010010000001010110011111100110111111100011011110101111111010001001110001000010001010111110111100000110001100001011101111110100001011101111110100100110111110000110111100010101000100110111111101101100101011000110111100011110000100111011100111111000000011111010111111110000000100111110011110101000101001111111000100111011111000111111111011110001011010111110100010101011101101000000011111111111111100111010101001110110111110000000101111000010001010101111110111110101011011111001110100111110100010110111010100000000100011110100010110001100011111101110111110100010101110111001101010111011110111110100100010011000010100111110000000100111011111010101111111111111111111111111111111111111111111111111111111111111111111111111"};
	char matriz[33][33];
	int i, j, counter = 0;

	for (i = 0; i < 33; i++)
	{
		for (j = 0; j < 33; j++)
		{
			matriz[i][j] = linha[counter];
			counter++;
		}
	}

	for (i = 0; i < 33; i++)
	{
		for (j = 0; j < 33; j++)
		{
			if (matriz[i][j] == '1')
				printf("%c", 219);
			else
				printf(" ");
		}
		printf("\n");
	}
}
