#include <stdio.h>

void inverteVetor(int* vetor, int inicio, int fim){
	if(inicio >= fim)
		return;
	int aux;
	aux = vetor[inicio];
	vetor[inicio] = vetor[fim];
	vetor[fim] = aux;
	inverteVetor(vetor,inicio+1,fim-1);
}

void main(){
	int vetor[6] = {1,2,3,4,5,6};
	inverteVetor(vetor,0,5);
	for(int x = 0; x < 6; x++)
		printf("%d ", *(vetor+x));
}
