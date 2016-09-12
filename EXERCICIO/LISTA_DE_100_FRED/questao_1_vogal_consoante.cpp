#include <stdio.h>

main(){
	
	char letra;
	
	printf("Informe uma letra: ");
	scanf("%c", &letra);
	
	if(letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u'){
		
		printf("\n\nA letra informada eh uma vogal!");
		
	} else {
		
		printf("\n\nA letra informada eh uma consoante!");
		
	}
	
}
