#include <stdio.h>
#define tamL 3
#define tamC 3
main(){
	char matriz[tamL][tamC], cmf;
	int frequente, maisFrequente = 0;
	for(int x = 0; x < tamL; x++){
		for(int y = 0; y < tamC; y++){
			scanf("%c", &matriz[x][y]);
			fflush(stdin);
		}
	}
	for(int x = 0; x < tamL; x++){
		for(int y = 0; y < tamC; y++){
			frequente = 0;
			for(int z = 0; z < tamL; z++){
				for(int w = 0; w < tamC; w++){
					if(matriz[x][y] == matriz[z][w] && x != z && y != w){
						frequente++;
					}
					if(frequente > maisFrequente){
						maisFrequente = frequente;
						cmf = matriz[x][y];
					}
				}
			}
		}
		
	}
	printf("\n%c", cmf);
}
