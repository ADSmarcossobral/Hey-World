#include <stdio.h>
#include <string.h>

main(){
	char stringA[20], stringB[20];
	gets(stringA);
	gets(stringB);
	// Descobrindo o tamanho da string
	int tamA = 0;
	while(stringA[tamA] != 0){
		tamA++; // Na tabela ASCII o valor 0 eh nulo. Quando a posição da string for igual a 0, então esse é o seu fim.
	}
	printf("\nA string A possui %d caracteres\n", tamA);
	int tamB = 0;
	while(stringB[tamB] != 0){
		tamB++; // Na tabela ASCII o valor 0 eh nulo. Quando a posição da string for igual a 0, então esse é o seu fim.
	}
	printf("\nA string B possui %d caracteres\n", tamB);
	// Convertendo do minúsculo para maiúsculo
	for(int x = 0; x < strlen(stringA); x++){
		if(stringA[x] >= 97 && stringA[x] <= 122){ // De 97 a 122 temos as letras de a a z... Só será feita a conversão, se a letra for minúscula.
			stringA[x] = stringA[x] - 32;
		}
	}
	for(int x = 0; x < strlen(stringB); x++){
		if(stringB[x] >= 97 && stringB[x] <= 122){ // De 97 a 122 temos as letras de a a z... Só será feita a conversão, se a letra for minúscula.
			stringB[x] = stringB[x] - 32;
		}
	}
	puts(stringA);
	puts(stringB);
	// Convertendo de maiúsculo para manúsculo
	for(int x = 0; x < strlen(stringA); x++){
		if(stringA[x] >= 65 && stringA[x] <= 90){ // De 65 a 90 temos as letras de A a Z na tabela ASCII... Só será feita a conversão, se a letra for maiúscula.
			stringA[x] = stringA[x] + 32;
		}
	}
	for(int x = 0; x < strlen(stringB); x++){
		if(stringB[x] >= 65 && stringB[x] <= 90){ // De 65 a 90 temos as letras de A a Z... Só será feita a conversão, se a letra for maiúscula.
			stringB[x] = stringB[x] + 32;
		}
	}
	puts(stringA);
	puts(stringB);
	// Comparando se as strings são iguais
	int iguais = 1;
	for(int x = 0; x < tamA; x++){
		if(stringA[x] == stringB[x]){
			continue;
		} else{
			iguais = 0;
			break;
		}
	}
	if(iguais == 0){
		printf("\nAs strings nao sao iguais\n");
	} else{
		printf("\nAs strings sao iguais\n");
	}
	// Concatenando as strings
	char stringAeB[tamA+tamB]; // Nova string que terá tamanho igual a soma do tamanho das duas strings
	for(int x = 0; x < tamA; x++){
		stringAeB[x] = stringA[x]; // Colocando a string A nas primeiras posições
	}
	for(int x = tamA; x <= tamB + tamA - 1; x++){
		stringAeB[x] = stringB[x - tamA]; // Colocando a string B nas posições depois da string A
	}
	stringAeB[tamA+tamB] = 0; // Ao ser compilado, o programa exibia caracteres a mais em algumas palavras. Então determino o final da string com 0.
	puts(stringAeB);
}
