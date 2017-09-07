#include <stdio.h>
#include <string.h>
main(){
	 char string[80], stringJus[80];	 
	 gets(string);
	 // Contando espaços
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
	 	// Se x for igual a última posição do vetor, e se a última posição for espaço... Break!
	 	if(x == strlen(string) - 1 && string[x] == ' '){
	 		stringJus[auxJus] = 0; // Fim da string
	 		break;
	 	}
	 	if(string[x] != 32){ // Se o caracter da posicao x não for um espaço...
	 		stringJus[auxJus] = string[x]; // A string justificada recebe o caracter
	 		auxJus++; // Próxima posição da string justificada
	 		adicionaEspaco = 1; // Já pode adicionar espaço, quando for encontrado um espaço
	 	} // Se for um espaço, e se adicionaEspaco ativado, e quantidade de distribuição de espaço for igual para todas as palavras...
		 else if(string[x] == 32 && adicionaEspaco == 1 && espacos % (palavras - 1) == 0) { 
	 		for(int y = 0; y < espacos / (palavras - 1); y++){ 
	 			stringJus[auxJus] = ' ';
	 			auxJus++;
	 		}
	 		adicionaEspaco = 0;
	 	} // Se for um espaço, e se adicionaEspaco ativado, e quantidade de distribuição de espaço não for igual para todas as palavras... 
		 else if(string[x] == 32 && adicionaEspaco == 1 && espacos % (palavras - 1) == 1){ 
	 		for(int y = 0; y < espacos / (palavras - 1); y++){
	 			if(primeira){ // Adicionando um espaço a mais na primeira palavra
	 				stringJus[auxJus] = ' ';
	 				auxJus++;
	 				primeira = 0; // Desativando a adicao de um espaço a mais nas próximas palavras.
	 			}
	 			stringJus[auxJus] = ' ';
	 			auxJus++;
	 		}
	 		adicionaEspaco = 0;
	 	}
	 }
	 puts(stringJus);
}
