#include <stdio.h>
main(){
	int fibo[2] = {0,1} , v[50], ult_elemento = 0, elemento, maior;
	// Recebendo os valores das 50 posi��es
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
	// Fazendo enquanto a �ltima posi��o da sequ�ncia de Fibonacci for menor que o maior n�mero
	while(fibo[1] < v[49]){
		for(int y = 0; y < 50; y++){
			// Se o valor da posi��o y do vetor for igual a posi��o 0 ou 1 da sequ�ncia de Fibonacci...
			if(v[y] == fibo[0] || v[y] == fibo[1]){
				elemento = y; // Armazena-se a posi��o encontrada para a seguinte compara��o...
			}		
		}
		// Se a posi��o do elemento encontrado for maior que a �ltima posi��o encontrada, ele se torna a �ltima posi��o
		if(elemento > ult_elemento){
			ult_elemento = elemento; 
		}
		// Gerando a sequ�ncia de Fibonacci de 2 em 2
		for(int x = 0; x < 2; x++){	
			fibo[x] = fibo[0] + fibo[1];		
		}
	}
	if(ult_elemento){ // Se existir elemento no vetor igual � sequ�ncia de Fibonacci...
		printf("%d", ult_elemento); // Mostra-se a posi��o do �ltimo elemento
	} else{ // Caso ao contr�rio, a sa�da dever� ser igual a -1
		ult_elemento = -1;
		printf("%d", ult_elemento);
	}
}
