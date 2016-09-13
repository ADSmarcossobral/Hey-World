#include <stdio.h>

main(){
	
	int v[10], vidas[10] = {0,0,0,0,0,0,0,0,0,0}, maximo = 0, aux1 = 0, aux2 = 0;
	
	for(int x = 0; x < 10; x++){
		scanf("%d", &v[x]);
	}
	
	for(int x = 0; x < 10; x++){
		aux1 = 0;
		aux2 = x;
		for(int z = 10 - x; z > 0; z--){
			for(int y = 0; y < z; y++){
				vidas[aux1] += v[aux2];
				aux2++;
			}
			aux1++;
			aux2 = x;
		}
		
		for(int z = 0; z < 10 - x; z++){
			if(vidas[z] > maximo){
				maximo = vidas[z];
			}
			vidas[z] = 0;
		}
	
	}
	
	printf("\nVidas Maxima = %d", maximo);
	
}
