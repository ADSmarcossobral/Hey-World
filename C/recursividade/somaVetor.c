#include <stdio.h>

int somaVetor(int* vetor, int n){
	if(n == 0)
		return 0;
	int s;
	s = somaVetor(vetor,n-1);
	s += vetor[n-1];
	return s;
}

void main(){
	int vetor[5] = {1,2,3,4,5};
	printf("%d", somaVetor(vetor,5));
}
