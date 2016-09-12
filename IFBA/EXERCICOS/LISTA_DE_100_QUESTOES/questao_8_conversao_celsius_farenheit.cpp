#include <stdio.h>

int main(){
	
	float c, f;
	
	printf("Informe a temperatura em graus Celsius: ");
	scanf("%f", &c);
	
	f = (9 * c + 160) / 5;
	
	printf("\n\nTemperatura em Celsius: %.2f\nTemperatura em Farenheit: %.2f", c, f);
	
	return 0;
	
}
