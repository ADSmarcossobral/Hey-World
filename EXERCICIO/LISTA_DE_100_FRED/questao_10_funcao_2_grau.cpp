#include <stdio.h>
#include <conio.h>

main(){
	
	float a, b, c, y = 0, x = 0, raizdelta = 0, delta, x1, x2;
	
	printf("Valor de a: ");
	scanf("%f", &a);
	fflush(stdin);
	printf("Valor de b: ");
	scanf("%f", &b);
	fflush(stdin);
	printf("Valor de c: ");
	scanf("%f", &c);
	fflush(stdin);
	
	delta = (b * b) - (4 * a * c);
	
	printf("\n\nDelta = b^2 x (4 x a x c)\nDelta = %.0f^2 x (4 x %.0f x %.0f)\nDelta = %.0f\n", b, a, c, delta);
	
		while(y != delta && (x * x) <= delta){
		
			y = x * x;
			// Se x vezes x for igual a n, então x é a raiz quadrada de n.
			if(y == delta){
			
				raizdelta = x;	
			
			} else {
			
				x++;
			
			}
				
		
		}
		
	if(raizdelta >= 0 && delta >= 0){
		printf("\n\nRaiz quadrada de delta: %.0f\n", raizdelta);
	} else{
		printf("\n\nRaiz quadrada de delta: Nao exata!\n");
	}
	
	if(delta > 0){
		
		x1 = ((-b) + raizdelta) / (2 * a);
		x2 = ((-b) - raizdelta) / (2 * a);
		
		printf("\nPossui duas raizes reais:\n");
		printf("\nx' = (-b) + Raiz Quadrada de Delta / (2 x a)");
		printf("\nx' = %.0f/%.0f = %.2f\n", ((-b) + raizdelta), (2 * a), x1);
		
		printf("\nx'' = (-b) - Raiz Quadrada de Delta / (2 x a)");
		printf("\nx'' = %.0f/%.0f = %.2f", ((-b) - raizdelta), (2 * a), x2);
		
	}
	
	if(delta == 0){
		
		x1 = ((-b) + raizdelta) / (2 * a);
		
		printf("\nPossui apenas uma raiz real:\n");
		printf("\nx' = %.0f/%.0f = %.2f", ((-b) + raizdelta), (2 * a), x1);
		
	}
	
	if(delta < 0){
		
		printf("\nNao possui raizes reais.");
		
	}
	
	printf("\n\nPressione qualquer tecla para continuar...");
	getch();
	
}
