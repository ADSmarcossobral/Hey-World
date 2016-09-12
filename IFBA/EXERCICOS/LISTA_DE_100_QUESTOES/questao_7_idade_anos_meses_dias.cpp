#include <stdio.h>

main(){
	
	int idade_dias, ano, mes, dia;
	
	printf("Informe a idade em dias:");
	scanf("%d", &idade_dias);
	
	ano = idade_dias / 360;
	mes = (idade_dias % 360) / 30;
	dia = (idade_dias % 360) % 30;
	
	printf("\n\n");
	
	if(ano > 1){
		
		printf("%d anos", ano);
	
	} else if(ano == 1){
		
		printf("%d ano", ano);
		
	}
	
	if(mes > 1){
		
		printf(" %d meses", mes);
	
	} else if(mes == 1){
		
		printf(" %d mes", mes);
		
	}
	
	if(dia > 1){
		
		printf(" %d dias", dia);
	
	} else if(mes == 1){
		
		printf(" %d dia", dia);
		
	}	
	
}
