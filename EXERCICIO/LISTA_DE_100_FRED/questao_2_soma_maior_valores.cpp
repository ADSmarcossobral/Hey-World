#include <stdio.h>

main(){
	
	float n1, n2, n3;
	
	printf("Informe o primeiro valor: ");
	scanf("%f", &n1);
	
	printf("\nInforme o segundo valor: ");
	scanf("%f", &n2);
	
	printf("\nInforme o terceiro valor: ");
	scanf("%f", &n3);
	
	if(n1 > n3 && n2 > n3){
		
		printf("\n\n%.1f + % .1f = %.1f", n1, n2, n1 + n2);
		
	}
	
	if(n1 > n2 && n3 > n2){
		
		printf("\n\n%.1f + % .1f = %.1f", n1, n3, n1 + n3);
		
	}
	
	if(n2 > n1 && n3 > n1){
		
		printf("\n\n%.1f + % .1f = %.1f", n2, n3, n2 + n3);
		
	}
	
	
	
}
