#include <stdio.h>

int main(){
	
	float base, h, area, perimetro;
	
	printf("Informe o tamanho da base: ")/
	scanf("%f", &base);
	
	printf("\nInforme o tamanho da altura: ");
	scanf("%f", &h);
	
	area = base * h;
	
	perimetro = (base * 2) + (h * 2);
	
	printf("\n\nArea: %.2f m2\nPerimetro: %.2f", area, perimetro);
	
	return 0;
	
}
