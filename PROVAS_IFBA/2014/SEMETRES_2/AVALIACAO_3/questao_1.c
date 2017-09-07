#include <stdio.h>
#define maxL 4
#define maxC 4

main(){
	int matriz[maxL][maxC];
	for(int x = 0; x < maxL; x++){
		for(int y = 0; y < maxC; y++){
			scanf("%d", &matriz[x][y]);
			fflush(stdin);
		}
	}
	int verificado = 0, permutacao = 0, posicoes[maxL*maxC], mesma_linha;
	while(!verificado){
		for(int x = 0; x < maxL; x++){
			mesma_linha = 0;
			for(int y = 0; y < maxC; y++){
				if(matriz[x][y] != 0 && matriz[x][y] != 1){
					verificado = 1;
					break;
				}
				if(matriz[x][y] == 1){
					posicoes[x] = y;
					if(mesma_linha){
						verificado = 1;
						break;
					}
					mesma_linha = 1;
				}		
			}
			if(verificado){
				break;
			} 
		}
		if(verificado){
			break;
		} else{
			for(int x = 0; x < maxL - 1; x++){
				permutacao = 1;
				if(posicoes[x] == posicoes[x+1]){
					permutacao = 0;
					verificado = 1;
					break;
				}
			}
		}
		break;
	}
	if(permutacao){
			printf("\nEh uma matriz de permutacao");
	} else{
		printf("\nNao eh uma matriz de permutacao");
	}
	
}
