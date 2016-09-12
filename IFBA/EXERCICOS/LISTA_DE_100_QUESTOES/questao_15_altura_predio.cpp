#include <stdio.h>

main(){
	
	float minha_altura, minha_sombra, sombra_predio, alt_predio;
	
	scanf("%f%f%f", &minha_altura, &minha_sombra, &sombra_predio);
	
	alt_predio = sombra_predio / (minha_sombra / minha_altura);
	
	printf("Altura do predio: %.2f", alt_predio);
	
	
}
