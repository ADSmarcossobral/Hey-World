#include <stdio.h>

void deZeroaNDecresc(int n){
	if(n == 0)
		return;
	printf("%d ", n);
	return deZeroaNDecresc(n-1);
}

void main(){
	deZeroaNDecresc(6);
}