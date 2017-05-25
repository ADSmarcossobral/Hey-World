#include <stdio.h>

int ocorrenciaN(int n, int busca){
	if(n == 0)
		return 0;
	if(n % 10 == busca)
		return ocorrenciaN(n/10,busca) + 1;
	return ocorrenciaN(n/10,busca);
}

void main(){
	printf("%d\n", ocorrenciaN(125124225, 2));
}
