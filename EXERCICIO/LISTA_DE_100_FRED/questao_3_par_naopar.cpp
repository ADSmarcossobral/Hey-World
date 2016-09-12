#include <stdio.h>

main(){
	
	int n;
	
	printf("Informe um numero: ");
	scanf("%d", &n);
	
	if((n % 2) == 0){
		
		printf("\n\nEsse numero eh par!");
		
	} else {
		
		printf("\n\nEsse numero nao eh par!");
		
	}
	
}
