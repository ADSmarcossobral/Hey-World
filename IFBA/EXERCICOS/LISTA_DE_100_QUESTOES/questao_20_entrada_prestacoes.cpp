#include <stdio.h>

main(){
	
	float valor, entrada;
	int prestacao;
	
	scanf("%f", &valor);
	prestacao = valor / 3;
	entrada = valor - (prestacao * 2);
	
	printf("Entrada de %.2f + 2 prestacoes de %d", entrada, prestacao);
	
} 
