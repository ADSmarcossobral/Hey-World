#include <stdio.h>
#include <string.h>

main(){
	char stringA[20], stringB[20];
	gets(stringA);
	gets(stringB);
	// Descobrindo o tamanho da string
	int tamA = 0;
	while(stringA[tamA] != 0){
		tamA++; // Na tabela ASCII o valor 0 eh nulo. Quando a posi��o da string for igual a 0, ent�o esse � o seu fim.
	}
	printf("\nA string A possui %d caracteres\n", tamA);
	int tamB = 0;
	while(stringB[tamB] != 0){
		tamB++; // Na tabela ASCII o valor 0 eh nulo. Quando a posi��o da string for igual a 0, ent�o esse � o seu fim.
	}
	printf("\nA string B possui %d caracteres\n", tamB);
	// Convertendo do min�sculo para mai�sculo
	for(int x = 0; x < strlen(stringA); x++){
		if(stringA[x] >= 97 && stringA[x] <= 122){ // De 97 a 122 temos as letras de a a z... S� ser� feita a convers�o, se a letra for min�scula.
			stringA[x] = stringA[x] - 32;
		}
	}
	for(int x = 0; x < strlen(stringB); x++){
		if(stringB[x] >= 97 && stringB[x] <= 122){ // De 97 a 122 temos as letras de a a z... S� ser� feita a convers�o, se a letra for min�scula.
			stringB[x] = stringB[x] - 32;
		}
	}
	puts(stringA);
	puts(stringB);
	// Convertendo de mai�sculo para man�sculo
	for(int x = 0; x < strlen(stringA); x++){
		if(stringA[x] >= 65 && stringA[x] <= 90){ // De 65 a 90 temos as letras de A a Z na tabela ASCII... S� ser� feita a convers�o, se a letra for mai�scula.
			stringA[x] = stringA[x] + 32;
		}
	}
	for(int x = 0; x < strlen(stringB); x++){
		if(stringB[x] >= 65 && stringB[x] <= 90){ // De 65 a 90 temos as letras de A a Z... S� ser� feita a convers�o, se a letra for mai�scula.
			stringB[x] = stringB[x] + 32;
		}
	}
	puts(stringA);
	puts(stringB);
	// Comparando se as strings s�o iguais
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
	char stringAeB[tamA+tamB]; // Nova string que ter� tamanho igual a soma do tamanho das duas strings
	for(int x = 0; x < tamA; x++){
		stringAeB[x] = stringA[x]; // Colocando a string A nas primeiras posi��es
	}
	for(int x = tamA; x <= tamB + tamA - 1; x++){
		stringAeB[x] = stringB[x - tamA]; // Colocando a string B nas posi��es depois da string A
	}
	stringAeB[tamA+tamB] = 0; // Ao ser compilado, o programa exibia caracteres a mais em algumas palavras. Ent�o determino o final da string com 0.
	puts(stringAeB);
}
