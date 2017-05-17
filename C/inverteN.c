#include <stdio.h>

void inverte(int n){
	if(n==0){
		return;
	} else{
		printf("%d", n % 10);
		n = n/10;
		inverte(n);
	}
}

void main(){
	inverte(123);
}
