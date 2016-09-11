#include <stdio.h>

main(){
	
	int fita[14], pos[14], preenchidos, p = 0, dias = 0, completo = 0, y = 0;
	//Recebendo as gotas nas posi��es inseridas pelo usu�rio
	do{
		p++; // Partindo da posi��o 1 e incrementando + 1 a cada repeti��o.
		scanf("%d", &pos[p]); // Recebendo a posi��o da gota e armezenando em outro vetor.
		if(pos[p] > 0 && pos[p] <= 13){ // A posi��o tem que est� entre 1 e 13.
			fita[pos[p]] = 1; // Caso seja verdadeira a condi��o, a gota cair� na posi��o recebida (O n�mero 1 representar� a gota).
		}
	} while(pos[p] > 0 && pos[p] <= 13); // O WHILE continuar� enquanto a posi��o da gota estiver entre 1 e 13.
	 
	 preenchidos = p; // Essa vari�vel ser� o contador de quantas posi��es foram preenchidas. E j� se inicia com quantidade de gotas pingadas.
	 
	while(preenchidos < 13){ // O WHILE continuar� at� que todas as posi��es sejam preenchidas.
		y++; // Incrementador que ajudar� a verificar todas as posi��es, partindo das primeiras gotas.
		int aux = p; // Para que o valor de p n�o seja alterado, usarei uma nova vari�vel para auxiliar no caso.
		for(int z = 0; z < p && preenchidos < 13; z++){ // Esse FOR ir� se repetir o n�mero de vezes da quantidade de gotas pingadas na fita, durante todo WHILE.
			
			if(fita[pos[aux] - y] != 1 && pos[aux] - y > 0){ // Se o n�mero da posi��o da gota pingada menos o valor de y n�o estiver preenchida...
				fita[pos[aux] - y] = 1; // Preenche-se a posi��o.
				preenchidos++; // Incrementando 1 nas posi��es preenchidas.
			}

			if(fita[pos[aux] + y] != 1 && pos[aux] + y <= 13){ // Se o n�mero da posi��o da gota pingada mais o valor de y n�o estiver preenchida...
				fita[pos[aux] + y] = 1; // Preenche-se a posi��o.
				preenchidos++; // Incrementando 1 nas posi��es preenchidas.
			}
			aux--; // Descrementando para testar as outras posi��es.
		}
		dias++;	// Depois de cada FOR, passa-se um dia.
	}
	printf("%d", dias);
}
