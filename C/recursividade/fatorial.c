#include <stdio.h>

int fatorial(int n){
	if(n < 2)
		return 1;
	else
		return fatorial(n-1) * n;
}

void main(){
	printf("%d", fatorial(5));
}
