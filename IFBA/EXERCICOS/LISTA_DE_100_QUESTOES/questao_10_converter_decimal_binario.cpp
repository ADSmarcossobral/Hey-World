#include <stdio.h>

int main(){
	
	int n, x[5], y;
	
	printf("Informe um numero menor que 32:");
	scanf("%d", &n);
	
	for(y = 0; y < 5; y++){
		
		x[y] = n%2;
		n = n / 2;
		
	}
	
	printf("Numero em binario: 000%d%d%d%d%d",x[4],x[3],x[2],x[1],x[0]);
	
}
