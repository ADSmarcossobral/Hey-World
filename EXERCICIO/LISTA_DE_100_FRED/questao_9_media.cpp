#include <stdio.h>

main(){
	
	float n1, n2, n3, media;
	
	printf("Informe a primeira nota: ");
	scanf("%f", &n1);
	
	printf("\nInforme a segunda nota: ");
	scanf("%f", &n2);
	
	printf("\nInforme a terceira nota: ");
	scanf("%f", &n3);
	
	media = (n1 + n2 + n3) / 3;
	
	if(media >= 5){
		
		printf("\nAprovado!");
		
	} else {
		
		printf("\nReprovado");
		
	}
	
}
