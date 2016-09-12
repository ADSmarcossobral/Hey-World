#include <stdio.h>
#include <conio.h>

main(){
	
	float litros;
	char tipoC;
	
	printf("Litros vendidos: ");
	scanf("%f", &litros);
	
	fflush(stdin);
	
	printf("\nTipo do combustivel: ");
	scanf("%c", &tipoC);
	
	printf("\n\n");
	
	switch(tipoC){
		
		case 'a':
			
			if(litros <= 25){
			
				printf("Valor a ser pago: R$%.2f", litros * (2.3 * (1 - 0.2)) );
			
			} else {
				
				printf("Valor a ser pago: R$%.2f", litros * (2.3 * (1 - 0.4)) );
				
			}
			
			
			break;
		
		case 'g':
			
			
			if(litros <= 25){
			
				printf("Valor a ser pago: R$%.2f", litros * (3.1 * (1 - 0.3)) );
			
			} else {
				
				printf("Valor a ser pago: R$%.2f", litros * (3.1 * (1 - 0.5)) );
				
			}
		
	}
	
	printf("\n\nPressione uma tecla para continuar...");
	getch();
	
}
