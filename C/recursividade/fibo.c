#include <stdio.h>

int fibo(int termo){
	if(termo == 1)
		return 0;
	else if(termo == 2)
		return 1;
	else
		return fibo(termo-1) + fibo(termo-2);			
}

void main(){
	printf("%d", fibo(8));
}
