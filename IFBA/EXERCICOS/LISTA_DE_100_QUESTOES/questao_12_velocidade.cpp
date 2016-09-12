#include <stdio.h>

main(){
	
	float vms;
	
	printf("Informe a velocidade em metros por segundo: ");
	scanf("%f", &vms);
	
	printf("\nVelocidade em k/h: %.2f", vms * 3.6);
	
}
