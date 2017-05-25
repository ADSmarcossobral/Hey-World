#include <stdio.h>

int kN(int k, int n){
	if(n == 2)
		return k * k;
	return kN(k,n-1) * k;
}

void main(){
	int k, n;
	scanf("%d %d", &k, &n);
	printf("%d", kN(k,n));
}
