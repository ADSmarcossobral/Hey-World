#include <stdio.h>

main(){
	
	int inicio = 0, encontrado = 2, x = 0, meio, fim, v[20] = {40, 100, 10, 5, 35, 65, 82, 27, 91, 23, 25, 21, 47, 89, 17, 7, 19, 29, 30, 56}, 
	aux = 0, tam = 20, busca = 40;
	
	//Ordenando os elementos no vetor
	for(int x = tam - 1; x > 0; x--){
		
		for(int y = 0; y < x; y++){
			
			if(v[y] > v[y+1]){
				
				aux = v[y+1];
				v[y+1] = v[y];
				v[y] = aux;
				
			}
			
		}
		
		
	}
	printf("Vetor ordenado --> ");
	for(int x = 0; x < tam; x++){
		printf("%d ", v[x]);
	}

	//Buscando um elemento no vetor - Busca binária
	
	fim = tam - 1;
	meio = fim / 2;

	printf("\nBuscando elemento %d...", busca);
	while(encontrado != 1){
		
		if(v[meio] == busca){
			printf("\nElemento encontrado na posicao %d do vetor.", meio);
			encontrado = 1;
			break;
		} else if(busca < v[meio]){
			fim = meio;
			meio /= 2;
		} else if(busca > v[meio]){
			inicio = meio;
			meio = (fim / 2) + ((meio + 1) / 2);
		}

		x++;

		if(x >= fim || busca < v[inicio]){
			printf("\nElemento nao encontrado!");
			break;
		}
		
	}
	
}
