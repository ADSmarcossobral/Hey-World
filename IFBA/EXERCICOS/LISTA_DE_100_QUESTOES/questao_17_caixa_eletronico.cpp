#include <stdio.h>

main(){
	
	int valor, nDisp[7] = {100, 50, 20, 10, 5, 2, 1}, y[7] = {0, 0, 0, 0, 0, 0, 0};
	
	scanf("%d", &valor);
	
	for(int x = 0; x < 7; x++){
		
		while(valor >= nDisp[x]){
			
			valor = valor - nDisp[x];
			y[x]++;
			
		}
		
                if(y[x] > 0){
			
			printf("\n%d de %d", y[x], nDisp[x]);
			
		}
	}
	
}
