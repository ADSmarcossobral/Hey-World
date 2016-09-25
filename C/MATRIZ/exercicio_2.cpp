/*
	Questão: Leia duas matrizes de tamanho 3x3, compare o valor das duas matrizes nas respectivas posições, e mostre quais números são iguais
			 nas duas matrizes, na mesma posição.

*/

#include <stdio.h>
#define maxlin 3
#define maxcol 3

main(){
	
	int matrizA[maxlin][maxlin], matrizB[maxlin][maxlin];
	
	for(int x = 0; x < maxlin; x++){
		for(int y = 0; y < maxcol; y++){
			scanf("%d", &matrizA[x][y]);
		}
	}
	
	for(int x = 0; x < maxlin; x++){
		for(int y = 0; y < maxcol; y++){
			scanf("%d", &matrizB[x][y]);
		}
	}
	
	for(int x = 0; x < maxlin; x++){
		for(int y = 0; y < maxcol; y++){
			if(matrizA[x][y] == matrizB[x][y]){
				printf("\nO numero %d aparece na posicao [%d][%d] das duas matrizes.\n", matrizA[x][y], x, y);
			}
		}
	}
}
