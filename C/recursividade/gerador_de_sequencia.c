#include <stdio.h>

int F(int n){
	if(n == 1)
		return 1;
	if(n == 2)
		return 2;
	return (F(n-1) * 2) + (F(n-2) * 3);
}

void main(){
	printf("%d\n", F(3));
}
