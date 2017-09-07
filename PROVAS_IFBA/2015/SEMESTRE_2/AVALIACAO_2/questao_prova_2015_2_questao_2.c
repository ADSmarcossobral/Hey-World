#include <stdio.h>

main(){
	
	int num, base = 2, aux, resto = 0, restoAux = 0, par_impar = 2, testado = 0, brasileiro = 0;
	//Recebendo o número
	while(num > 2){ // 
		brasileiro = 0;
		scanf("\n%d", &num);
		if(num <= 2){printf("\nNumero invalido!");break;} // O número tem que ser maior que 2
	for(base = 2; base < num - 1 && !brasileiro; base++){//Convertendo o número a partir da base 2 até a base menor que N - 1, e até quando ele não for brasileiro.
		aux = num; // Uma variável auxiliar para não alterar o valor do número diretamente.
		testado = 0; // Valor válido para entrar no WHILE para testar as bases
		par_impar = 2; // Quando o valor dessa variável for par, o resto da primeira divisão será armazenada na variável "resto", caso ímpar, na "restoAux"
		while(testado == 0){ // O WHILE continua até que o número seja testado na base.
			
			if(aux > base && par_impar % 2 == 0){ // Se o número for maior que a base e a variável "par_impar" for par...
				resto = aux % base; // armazena-se o resto na variável "resto"
				aux = aux / base; // armezanando o quociente para a próxima divisão
				par_impar++; // somando + 1 para que a variável seja ímpar, e o próximo resto seja armazenado na variável "restoAux"
				if(resto == 0){ // Se o resto for igual a zero, o número não pode ser brasileiro nessa base.
					break; // Saindo do while.
				}
			} else if(aux > base && par_impar % 2 == 1){ // Se o número for maior que a base e a variável "par_impar" for ímpar...
				restoAux = aux % base; // armazena-se o resto na variável "restoAux"
				aux = aux / base; // armezanando o quociente para a próxima divisão
				par_impar++; // somando + 1 para que a variável seja par, e o próximo resto seja armazenado na variável "resto"
				if(restoAux == 0){ // Se o resto for igual a zero, o número não pode ser brasileiro nessa base.
					break; // Saindo do while.
				}
			}
		
			if(aux < base && par_impar % 2 == 1){ // Se o número for menor que a base e "par_impar" for ímpar.
				restoAux = aux; // O último dígito da conversão será o quociente (Armazenando na variável "restoAux", para ser comparada com a "resto".
				if(resto == restoAux){ // Se resto for igual a restoAux...
					brasileiro = 1; // O número é brasileiro
					break; // Saindo do WHILE, indo para o próximo passo do FOR
				} else{ // Senão o número continua não sendo brasileiro...
					break; //Saindo do WHILE e indo ao próximo passo do FOR
				}
			} else if(aux < base && par_impar % 2 == 0){ // Se o número for menor que a base e "par_impar" for par.
				resto = aux; // O último dígito da conversão será o quociente (Armazenando na variável "resto", para ser comparada com a "restoAux".
				if(resto == restoAux){ // Se resto for igual a restoAux...
					brasileiro = 1;// O número é brasileiro
					break; // Saindo do WHILE, indo para o próximo passo do FOR
				}
			}
			
			if(aux == base || resto != restoAux){ // Se o quociente for igual a base ou o valor de "resto" seja diferente que "restoAux"...
				break; // O número continua não sendo brasileiro. Break para sair do WHILE, indo para o próximo passo do FOR.
			}
		
		}
	}
	
	if(brasileiro == 1){ // Ao final dos testes, se a variável "brasileiro" for igual a 1 o número é brasileiro
		printf("\n%d --> Brasileiro na base %d\n", num, base - 1); // Mostrando o número e a base que ele é brasileiro (Obs: "base - 1" porque ao final do FOR a base foi somada + 1.
	} else{ //Senão...
		printf("\n%d --> Nao brasileiro\n", num); //Número não é brasileiro.
	}
	}
}
