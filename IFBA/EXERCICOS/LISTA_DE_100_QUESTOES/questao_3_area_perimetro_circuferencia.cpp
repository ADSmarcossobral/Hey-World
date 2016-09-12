#include <stdio.h>

int main(){
	
	float raio, area, perimetro;
	const float pi = 3.14;
	
	printf("Informe o tamanho do raio: ")/
	scanf("%f", &raio);
		
	area = pi * (raio * raio);
	
	perimetro = 2 * pi * raio;
	
	printf("\n\nArea: %.2f m2\nPerimetro: %.2f", area, perimetro);
	
	return 0;
	
}
