#include <stdio.h>

main(){
	
	int num, base = 2, aux, resto = 0, restoAux = 0, par_impar = 2, testado = 0, brasileiro = 0;
	//Recebendo o n�mero
	while(num > 2){ // 
		brasileiro = 0;
		scanf("\n%d", &num);
		if(num <= 2){printf("\nNumero invalido!");break;} // O n�mero tem que ser maior que 2
	for(base = 2; base < num - 1 && !brasileiro; base++){//Convertendo o n�mero a partir da base 2 at� a base menor que N - 1, e at� quando ele n�o for brasileiro.
		aux = num; // Uma vari�vel auxiliar para n�o alterar o valor do n�mero diretamente.
		testado = 0; // Valor v�lido para entrar no WHILE para testar as bases
		par_impar = 2; // Quando o valor dessa vari�vel for par, o resto da primeira divis�o ser� armazenada na vari�vel "resto", caso �mpar, na "restoAux"
		while(testado == 0){ // O WHILE continua at� que o n�mero seja testado na base.
			
			if(aux > base && par_impar % 2 == 0){ // Se o n�mero for maior que a base e a vari�vel "par_impar" for par...
				resto = aux % base; // armazena-se o resto na vari�vel "resto"
				aux = aux / base; // armezanando o quociente para a pr�xima divis�o
				par_impar++; // somando + 1 para que a vari�vel seja �mpar, e o pr�ximo resto seja armazenado na vari�vel "restoAux"
				if(resto == 0){ // Se o resto for igual a zero, o n�mero n�o pode ser brasileiro nessa base.
					break; // Saindo do while.
				}
			} else if(aux > base && par_impar % 2 == 1){ // Se o n�mero for maior que a base e a vari�vel "par_impar" for �mpar...
				restoAux = aux % base; // armazena-se o resto na vari�vel "restoAux"
				aux = aux / base; // armezanando o quociente para a pr�xima divis�o
				par_impar++; // somando + 1 para que a vari�vel seja par, e o pr�ximo resto seja armazenado na vari�vel "resto"
				if(restoAux == 0){ // Se o resto for igual a zero, o n�mero n�o pode ser brasileiro nessa base.
					break; // Saindo do while.
				}
			}
		
			if(aux < base && par_impar % 2 == 1){ // Se o n�mero for menor que a base e "par_impar" for �mpar.
				restoAux = aux; // O �ltimo d�gito da convers�o ser� o quociente (Armazenando na vari�vel "restoAux", para ser comparada com a "resto".
				if(resto == restoAux){ // Se resto for igual a restoAux...
					brasileiro = 1; // O n�mero � brasileiro
					break; // Saindo do WHILE, indo para o pr�ximo passo do FOR
				} else{ // Sen�o o n�mero continua n�o sendo brasileiro...
					break; //Saindo do WHILE e indo ao pr�ximo passo do FOR
				}
			} else if(aux < base && par_impar % 2 == 0){ // Se o n�mero for menor que a base e "par_impar" for par.
				resto = aux; // O �ltimo d�gito da convers�o ser� o quociente (Armazenando na vari�vel "resto", para ser comparada com a "restoAux".
				if(resto == restoAux){ // Se resto for igual a restoAux...
					brasileiro = 1;// O n�mero � brasileiro
					break; // Saindo do WHILE, indo para o pr�ximo passo do FOR
				}
			}
			
			if(aux == base || resto != restoAux){ // Se o quociente for igual a base ou o valor de "resto" seja diferente que "restoAux"...
				break; // O n�mero continua n�o sendo brasileiro. Break para sair do WHILE, indo para o pr�ximo passo do FOR.
			}
		
		}
	}
	
	if(brasileiro == 1){ // Ao final dos testes, se a vari�vel "brasileiro" for igual a 1 o n�mero � brasileiro
		printf("\n%d --> Brasileiro na base %d\n", num, base - 1); // Mostrando o n�mero e a base que ele � brasileiro (Obs: "base - 1" porque ao final do FOR a base foi somada + 1.
	} else{ //Sen�o...
		printf("\n%d --> Nao brasileiro\n", num); //N�mero n�o � brasileiro.
	}
	}
}
