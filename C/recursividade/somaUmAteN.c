#include <stdio.h>

int somaUmAteN(int n){
	if(n == 0)
		return 0;
	else
		return somaUmAteN(n-1) + n;
}

void main(){
	printf("%d", somaUmAteN(5));
}
