#include <stdio.h>

int main(){
	
	float a, b, c, perimetro;
	
	printf("Informe o tamanho do lado a: \n");
	scanf("%f", &a);
	
	printf("Informe o tamanho do lado b: \n");
	scanf("%f", &b);
	
	printf("Informe o tamanho do lado c: \n");
	scanf("%f", &c);
	
	perimetro = a + b + c;
	
	printf("\n\nPerimetro: %.2f", perimetro);
	
	return 0;
	
}
