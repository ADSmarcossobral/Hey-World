#include <stdio.h>

main(){
	
	int tipoPul;
	float area, acre, custo;
	
	printf("Informe o tipo de pulverizacao: ");
	scanf("%d", &tipoPul);
	fflush(stdin);
	printf("\nInforme o tamanho da area: ");
	scanf("%f", &area);
	fflush(stdin);
	
	acre = area / 4047;

	switch(tipoPul){
		
		case 1:
		
			custo = 50 * acre;
			break;
			
		case 2:
			
			custo = 100 * acre;
			break;
		
		case 3:
			
			custo = 150 * acre;
			break;
		
		case 4:
			
			custo = 250 * acre;
			break;
		
	}

	if(acre > 1000){

		custo = custo * 0.95;

	}
	
	if(custo > 750){
		
		custo = custo * 0.9;
		
	}
	
	printf("\nValor a ser pago: R$%.2f", custo);
	
}
