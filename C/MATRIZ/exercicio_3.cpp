/*
	Quest�o: Fa�a um programa C que leia duas matrizes A e B de tamanho 4 x 4, conte e mostre quais dos
			 valores que est�o na matriz A tamb�m aparecem na matriz B, independente de sua posi��o na matriz B.
*/

#include <stdio.h>
#define maxlin 4
#define maxcol 4

main(){
	int matrizA[maxlin][maxcol], matrizB[maxlin][maxcol], verificado[maxlin*maxcol], contV = 0;
	// Recebendo os valores da matriz A
	for(int x = 0; x < maxlin; x++){
		for(int y = 0; y < maxcol; y++){
			scanf("%d", &matrizA[x][y]);
		}
	}
	// Recebendo os valores da matriz B
	for(int x = 0; x < maxlin; x++){
		for(int y = 0; y < maxcol; y++){
			scanf("%d", &matrizB[x][y]);
		}
	}
	// Zerando o vetor que possuir� os valores dos n�meros verificados
	for(int x = 0; x < maxlin * maxcol; x++)
		verificado[0] = 0;
	
	for(int x = 0; x < maxlin; x++){ // Linha da matriz A
		for(int y = 0; y < maxcol;){ // Coluna da matriz A
			for(int z = 0; z < maxlin; z++){ // Linha da matriz B
				for(int w = 0; w < maxcol; w++){ // Coluna da matriz B
					if(matrizA[x][y] == matrizB[z][w]){ // Comparando as primeiras posi��es da matriz A com as posi��es de B
						int existe = 0; // 0 para falso, 1 para verdadeiro
						for(int v = 0; v < maxlin*maxcol; v++){ // Verificando se o n�mero j� foi verificado
							if(matrizA[x][y] == verificado[v]){ // Verificando se o valor que est� sendo comparado, j� foi verificado
								existe = 1; // Se j� foi verificado, ent�o � verdadeiro
								break;
							}
						}
						if(existe == 0){ // Se n�o foi verificado...
							printf("O numero %d aparece nas duas matrizes.", matrizA[x][y]); // Mostra-se o valor 
							verificado[contV] == matrizA[x][y]; // Adicionando o valor a lista de n�meros verificados
							contV++;
							y++;
						}
					}
				}
			}
		}
	}
}

