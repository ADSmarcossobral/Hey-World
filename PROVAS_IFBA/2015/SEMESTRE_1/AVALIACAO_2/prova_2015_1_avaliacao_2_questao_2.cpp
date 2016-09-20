#include <stdio.h>
main(){
	int fibo[2] = {0,1} , v[50], ult_elemento = 0, elemento, maior;
	// Recebendo os valores das 50 posições
	for(int x = 0; x < 50; x++){
		scanf("%d", &v[x]);
	}
	// Ordenando o vetor
	for(int x = 49; x >= 0; x--){
		for(int y = 0; y < x; y++){
			if(v[y] > v[y+1]){
				maior = v[y];
				v[y] = v[y+1];
				v[y+1] = maior;
			}
		}
	}
	// Fazendo enquanto a última posição da sequência de Fibonacci for menor que o maior número
	while(fibo[1] < v[49]){
		for(int y = 0; y < 50; y++){
			// Se o valor da posição y do vetor for igual a posição 0 ou 1 da sequência de Fibonacci...
			if(v[y] == fibo[0] || v[y] == fibo[1]){
				elemento = y; // Armazena-se a posição encontrada para a seguinte comparação...
			}		
		}
		// Se a posição do elemento encontrado for maior que a última posição encontrada, ele se torna a última posição
		if(elemento > ult_elemento){
			ult_elemento = elemento; 
		}
		// Gerando a sequência de Fibonacci de 2 em 2
		for(int x = 0; x < 2; x++){	
			fibo[x] = fibo[0] + fibo[1];		
		}
	}
	if(ult_elemento){ // Se existir elemento no vetor igual à sequência de Fibonacci...
		printf("%d", ult_elemento); // Mostra-se a posição do último elemento
	} else{ // Caso ao contrário, a saída deverá ser igual a -1
		ult_elemento = -1;
		printf("%d", ult_elemento);
	}
}
