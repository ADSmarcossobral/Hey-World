#include <stdio.h>
#include <string.h>

void inverteString(char* str, int inicio, int fim){
	if(inicio >= fim)
		return;
	int aux;
	aux = str[inicio];
	str[inicio] = str[fim];
	str[fim] = aux;
	inverteString(str,inicio+1,fim-1);
}

void main(){
	char str[4] = {"OLAP"};
	inverteString(str,0,strlen(str)-1);
	puts(str);
}
