#include <stdio.h>
#include <string.h>
#define total 100
struct produto{
		char nome[50];
		float preco;
};
main(){
	float media = 0;
	int menorPreco;
	struct produto p[total];
	for(int x = 0; x < total; x++){
		gets(p[x].nome);
		fflush(stdin);
		scanf("%f", &p[x].preco);
		fflush(stdin);
		media = media + p[x].preco;
	}
	media = media / total;
	printf("%f\n", media);
	for(int x = 0; x < total; x++){
		if(p[x].preco < media){
			p[x].preco = p[x].preco * 1.1;
			printf("n%.2f\n", p[x].preco);
		}
		if(p[x].preco < p[x+1].preco){
			menorPreco = x;
		}
	}
	puts(p[menorPreco].nome);
	printf("\n%.2f", p[menorPreco].preco);	
}
