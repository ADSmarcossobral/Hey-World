#include <stdio.h>

main(){
	
	int n;
	
	printf("Informe um numero: ");
	scanf("%d", &n);
	
	if(n % 10 == 0){
		
		printf("\nDivisivel por 10");
		
	}
	
	if(n % 5 == 0){
		
		printf("\nDivisivel por 5");
		
	}
	
	if(n % 2 == 0){
		
		printf("\nDivisivel por 2");
		
	}
	
	if(n % 10 != 0 && n % 5 != 0 && n % 2 != 0){
		
		printf("\nNao eh divisivel por 10, nem 5, nem 2");
		
	}
	
}
