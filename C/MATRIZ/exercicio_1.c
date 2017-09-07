/*
	Questão: Leia valores e preencha uma matriz 3x3 com valores inteiros entre 0 e 10, inclusive (notas de alunos) e indique:
	
	a) Quantas vezes a nota 9 aparece na matriz
	b) Quantas vezes aparece cada nota

*/

#include <stdio.h>
#define maxlin 3
#define maxcol 3
#define lin 11

main(){
	int	matriz[maxlin][maxcol], aparece[lin], x9;
	
	for(int x = 0; x < maxlin; x++){
		for(int y = 0; y < maxcol; y++){
			scanf("%d", &matriz[x][y]);
			if(matriz[x][y] == 9){
				x9++;
			}
		}
	}
	printf("\nO 9 aparece %d\n", x9);
	
	for(int x = 0; x < lin; x++)
		aparece[x] = 0;
		
	for(int x = 0; x < maxlin; x++){
		for(int y = 0; y < maxcol; y++){
			aparece[matriz[x][y]] = aparece[matriz[x][y]] + 1;
		}
	}
	
	for(int x = 0; x < lin; x++){
		printf("\nNota %d: %d\n", x, aparece[x]);
	}
	
}
