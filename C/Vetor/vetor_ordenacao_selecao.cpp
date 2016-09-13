#include <stdio.h>

main(){
	//Ordenação por seleção
	int v[5] = {20, 40, 35, 5, 10}, aux, x, tam = 5, menor;
	
	for(int y = 0 ; y < tam - 1; y++){
		
		for(x = y+1; x < tam; x++){
			menor = y;
			if(v[menor] > v[x]){
				
				menor = x;
				aux = v[y];
				v[y] = v[menor];
				v[menor] = aux;
				
			}
					
		}	
		
	}
	
	for(int x = 0; x < 5; x++){
		
		printf("%d ", v[x]);
		
	}
	
}
