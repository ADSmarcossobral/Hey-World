#include <stdio.h>
#include <string.h>
main(){
	 char string[80], stringJus[80];
	 int quebrada[80];
	 
	 gets(string);
	 // Contando espa�os
	 int espacos = 0;
	 for(int x = 0; x < strlen(string); x++){
	 	if(string[x] == 32){
	 		espacos++;
	 	}
	 }
	 // Contando palavras
	 int palavras = 0, contLetra = 0;
	 for(int x = 0; x < strlen(string); x++){
	 	if(string[x] != 32){
	 		contLetra++;
	 	} else if(string[x] == 32 && contLetra > 0){
	 		palavras++;
	 		contLetra = 0;
	 	}
	 }
	 // Justificando a string
	 int adicionaEspaco = 0, auxJus = 0, primeira = 1;
	 for(int x = 0; x < strlen(string); x++){
	 	// Se x for igual a �ltima posi��o do vetor, e se a �ltima posi��o for espa�o... Break!
	 	if(x == strlen(string) - 1 && string[x] == ' '){
	 		stringJus[auxJus] = 0; // Fim da string
	 		break;
	 	}
	 	if(string[x] != 32){ // Se o caracter da posicao x n�o for um espa�o...
	 		stringJus[auxJus] = string[x]; // A string justificada recebe o caracter
	 		auxJus++; // Pr�xima posi��o da string justificada
	 		adicionaEspaco = 1; // J� pode adicionar espa�o, quando for encontrado um espa�o
	 	} // Se for um espa�o, e se adicionaEspaco ativado, e quantidade de distribui��o de espa�o for igual para todas as palavras...
		 else if(string[x] == 32 && adicionaEspaco == 1 && espacos % (palavras - 1) == 0) { 
	 		for(int y = 0; y < espacos / (palavras - 1); y++){ 
	 			stringJus[auxJus] = ' ';
	 			auxJus++;
	 		}
	 		adicionaEspaco = 0;
	 	} // Se for um espa�o, e se adicionaEspaco ativado, e quantidade de distribui��o de espa�o n�o for igual para todas as palavras... 
		 else if(string[x] == 32 && adicionaEspaco == 1 && espacos % (palavras - 1) == 1){ 
	 		for(int y = 0; y < espacos / (palavras - 1); y++){
	 			if(primeira){ // Adicionando um espa�o a mais na primeira palavra
	 				stringJus[auxJus] = ' ';
	 				auxJus++;
	 				primeira = 0; // Desativando a adicao de um espa�o a mais nas pr�ximas palavras.
	 			}
	 			stringJus[auxJus] = ' ';
	 			auxJus++;
	 		}
	 		adicionaEspaco = 0;
	 	}
	 }
	 puts(stringJus);
}
