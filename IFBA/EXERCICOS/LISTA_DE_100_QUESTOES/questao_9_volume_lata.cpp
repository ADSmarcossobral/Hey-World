#include <stdio.h>

main(){
	
	float raio, h, volume;
	float const pi = 3.14159;
	
	printf("Informe o raio da lata:");
	scanf("%f", &raio);
	
	printf("\nInforme a altura da lata:");
	scanf("%f", &h);
	
 	printf("\n\nVolume: %.2f", pi * (raio * raio) * h);
 	
}
