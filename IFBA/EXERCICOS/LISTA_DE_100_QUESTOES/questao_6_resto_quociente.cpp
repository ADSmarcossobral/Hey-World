#include <stdio.h>

main(){
	
	int n1, n2;
	
	printf("Informe o primeiro numero:");
	scanf("%d", &n1);
	fflush(stdin);
	printf("\nInforme o segundo numero:");
	scanf("%d", &n2);
	
	printf("\nQuociente: %d \nResto: %d", n1 / n2, n1 % n2);
	
}
