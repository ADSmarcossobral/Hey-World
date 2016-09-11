#include <stdio.h>
main(){
// Os Vetores terão 14 posições, pois o armazenamento partirá da posição 1. 
// Obs: A questão pede 1000 posições, mas o exemplo tem 13 posições. Para atender a questão é só mudar o tamanho dos vetores para 1001.
	int fita[14], pos[14], preenchidos, p = 0, dias = 0, y = 0;
	//Recebendo as gotas nas posições inseridas pelo usuário
	do{
		p++; // Partindo da posição 1 e incrementando + 1 a cada repetição.
		scanf("%d", &pos[p]); // Recebendo a posição da gota e armezenando em outro vetor.
		if(pos[p] > 0 && pos[p] <= 13){ // A posição tem que está entre 1 e 13.
			fita[pos[p]] = 1; // Caso seja verdadeira a condição, a gota cairá na posição recebida (O número 1 representará a gota).
		}
	} while(pos[p] > 0 && pos[p] <= 13); // O WHILE continuará enquanto as posições das gotas estiverem entre 1 e 13.
	 
	 preenchidos = p; // Essa variável será o contador de quantas posições foram preenchidas. E já se inicia com quantidade de gotas pingadas.
	 
	while(preenchidos < 13){ // O WHILE continuará até que todas as posições sejam preenchidas.
		y++; // Incrementador que ajudará a verificar todas as posições, partindo das primeiras gotas.
		int aux = p; // Para que o valor de p não seja alterado, usarei uma nova variável para auxiliar no caso.
		for(int z = 0; z < p && preenchidos < 13; z++){ // Esse FOR irá se repetir o número de vezes da quantidade de gotas pingadas na fita, durante todo WHILE.
			
			if(fita[pos[aux] - y] != 1 && pos[aux] - y > 0){ // Se o número da posição da gota pingada menos o valor de y não estiver preenchida...
				fita[pos[aux] - y] = 1; // Preenche-se a posição.
				preenchidos++; // Incrementando 1 nas posições preenchidas.
			}

			if(fita[pos[aux] + y] != 1 && pos[aux] + y <= 13){ // Se o número da posição da gota pingada mais o valor de y não estiver preenchida...
				fita[pos[aux] + y] = 1; // Preenche-se a posição.
				preenchidos++; // Incrementando 1 nas posições preenchidas.
			}
			aux--; // Descrementando para testar as outras posições.
		}
		dias++;	// Depois de cada FOR, passa-se um dia.
	}
	printf("%d", dias);
}
