#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int n, y, x, quadrado, raizquad = 0;
	
	printf("Informe um numero: ");
	scanf("%d", &n);
	
	while(y != n && (x * x) <= n){
		
		y = x * x;
		// Se x vezes x for igual a n, então x é a raiz quadrada de n.
		if(y == n){
			
			raizquad = x;
			
		} else {
			
			x++;
			
		}
		
		
	}
	
	quadrado = n * n;
	
	printf("\n_________________");
		
	if(raizquad == 0){
		
		printf("\n\nQuadrado: %d\nRaiz quadrada: Nao exata.", quadrado);
			
	} else {
		
		printf("\n\nQuadrado: %d\nRaiz quadrada: %d ", quadrado, raizquad);
		
	}
	
	printf("\n___________________\n\n");
	
	system("pause");
	return 0;
	
	
}

