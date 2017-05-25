#include <stdio.h>

void natural_to_bin(int n){
	if(n == 0)
		return;
	natural_to_bin(n/2);
	printf("%d", n%2);
}

void main(){
	natural_to_bin(10);
}
