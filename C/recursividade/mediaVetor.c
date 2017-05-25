#include <stdio.h>

int mediaVetor(int* vetor, int tam){
	if(tam < 0)
		return 0;
	int s;
	s = (vetor,tam-1);
	s += vetor[tam-1] / tam; // errado
	return s;
}

void main(){
	int vetor[5] = {2,4,8,10,8};
	printf("%d", mediaVetor(vetor,5));
}
