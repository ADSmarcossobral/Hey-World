#include <stdio.h>

int main(){
	
	float lado, area, perimetro;
	
	printf("Informe o tamanho do lado: ")/
	scanf("%f", &lado);
	
	area = lado * lado;
	
	perimetro = lado * 4;
	
	printf("\n\nArea: %.2f m2 \nPerimetro: %.2f", area, perimetro);
	
	return 0;
	
}
