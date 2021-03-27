#include <stdio.h>
#include <string.h>
#include <locale.h>

void tabela(char simbolos[7][18][3]) {
	int i, j;
	
	for (i=0; i<7; i++) {
		for (j=0; j<18; j++)
			printf("%-4s", simbolos[i][j]);
		printf("\n");
	}
}

void main() {
	setlocale(LC_ALL, "Portuguese");
	char simbolos[7][18][3] = {{"H", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "He"},
							{"Li", "Be", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "B", "C", "N", "O", "F", "Ne"},
							{"Na", "Mg", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", "Al", "Si", "P", "S", "Cl", "Ar"},
							{"K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr"},
							{"Rb", "Sr", "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb", "Te", "I", "Xe"},
							{"Cs", "Ba", " ", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn"},
						    {"Fr", "Ra", " ", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og"}};
						    
	int numeros[7][18] = {{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
                        		{3, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 6, 7, 8, 9, 10},
    		                    {11, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 14, 15, 16, 17, 18},
            		            {19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36},
                    		    {37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54},
        		                {55, 56, 0, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86},
                		        {87, 88, 0, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118}};
                		        
	char simbolos2[118][2] = {"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb", "Te", "I", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og"};
	char elemento[3];
	int linha, coluna, i, j;
	
	
	tabela(simbolos);
	
	do{
		printf("Digite o elemento ('espaço' para sair): ");
		gets(elemento);
		printf("%s", elemento);
		
		if (elemento[0] != ' ') {
			for (i=0; i<7; i++) {
				for (j=0; j<18; j++) {
					if (strcmp(elemento, simbolos[i][j]) == 0) {
						printf("\nNúmero Atômico: %d", numeros[i][j]);
						printf("\nPeríodo: %d", i + 1);
                		printf("\nGrupo: %d", j + 1);
					}
				}
			}
		}
	}while(elemento[0] != ' ');
}
