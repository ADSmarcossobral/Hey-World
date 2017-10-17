/*
	Terceiro Trabalho de Laborat�rio de Programa��o 
	Instituto Federal da Bahia - IFBA
	Discente: Ant�nio Marcos Sobral Ramos
	Matr�cula: 2016116007
	Data: 07/05/2017
*/
#include "funcoes.h"

int main(){
	int saida = 0, op, ler = 0;
	FILE *dados;
	int* vetorAux = NULL;
	principal* LISTA = (principal *)malloc(tamanho * sizeof(principal));
	anula(LISTA);
	printf("\nDeseja carregar os ultimos dados salvos? 0 -> SIM | 1 -> NAO: ");
	op = trataEntrada();
	if(op){
		ler = lerDados(LISTA,dados);
		if(!ler){
			printf("\nErro ao carregador dados salvos ou nao existem dados salvos!\n");
		} else{
			printf("\nDados carregados com sucesso!\n");
		}
		system("pause");
	}
	while(!saida){
		menu();
		op = trataEntrada();
		opcao(LISTA, vetorAux, op, &saida,dados);
		printf("\n\n");
		if(saida){
			int salvar;
			printf("Deseja salvar os ultimos dados alterados das estruturas? 1 -> SIM ou 0 -> NAO: ");
			salvar = trataEntrada();
			if(salvar){
				salvar = salvarDados(LISTA,dados);
				if(salvar)
					printf("\nDados salvos com sucesso!");
				else
					printf("\nErro ao salvar os dados!");
			}
			printf("\nPrograma finalizado!!!\n");
		}
		system("pause");
	}
	free(LISTA);
	return 0;
}

