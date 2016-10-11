#include <stdio.h>
#include <string.h>
#define limite 256
#define tamVogais 12
main(){
	char string[limite];
	char vogais[tamVogais] = {"aAeEiIoOuU "};
	int diferente, encontros;
	gets(string);
	for(int x = 0; x < strlen(string); x++){
		diferente = 0;
		for(int y = 0; y < tamVogais; y++){
			if(string[x] != vogais[y] && string[x+1] != vogais[y]){
				diferente++;
			} else{
				break;
			}
		}
		if(diferente == tamVogais){
			encontros++;
			x++;
		}
	}
	printf("%d", encontros);
}		
