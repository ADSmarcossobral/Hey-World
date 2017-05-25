#include <stdio.h>

void deZeroaNDecresc(int n){
	if(n == 0)
		return;
	deZeroaNDecresc(n-1);
	printf("%d ", n);
}

void main(){
	deZeroaNDecresc(6);
}
