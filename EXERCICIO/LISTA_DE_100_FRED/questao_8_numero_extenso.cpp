#include <stdio.h>

main(){
	
	int n;
	
	printf("Informe um numero: ");
	scanf("%d", &n);
	
	if(n == 100){
		
		printf("\nCem");
		
	} 
	
	if(n >= 90 && n < 100){
		
		printf("\nNoventa");
		
	}
	
	if(n >= 80 && n < 90){
		
		printf("\nOitenta");
		
	}
	
	if(n >= 70 && n < 80){
		
		printf("\nSetenta");
		
	}
	
	if(n >= 60 && n < 70){
		
		printf("\nSessenta");
		
	}
	
	if(n >= 50 && n < 60){
		
		printf("\nCiquenta");
		
	}
	
	if(n >= 40 && n < 50){
		
		printf("\nQuarenta");
		
	}
	
	if(n >= 30 && n < 40){
		
		printf("\nTrinta");
		
	}
	
	if(n >= 20 && n < 30){
		
		printf("\nVinte");
		
	}
	
	if((n > 20 && n % 10 != 0) || n < 10){
		
		if(n > 20){
		
			printf(" e ");
		
		}
		
		
	
	
		if(n % 10 == 1 || n == 1){
		
			printf("um.");
		
		}
	
		if(n % 10 == 2 || n == 2){
		
			printf("dois.");
		
		}
	
		if(n % 10 == 3 || n == 3){
		
			printf("tres.");
		
		}
	
		if(n % 10 == 4 || n == 4){
		
			printf("quatro.");
		
		}
	
		if(n % 10 == 5 || n == 5){
		
			printf("cinco.");
		
		}
	
		if(n % 10 == 6 || n == 6){
		
			printf("seis.");
		
		}
	
	
		if(n % 10 == 7 || n == 7){
		
			printf("sete.");
		
		}
	
		if(n % 10 == 8 || n == 8){
		
			printf("oito.");
		
		}
	
		if(n % 10 == 9 || n == 9){
		
			printf("nove.");
			
		}
	}
	
	if(n == 11){
		
		printf("\nOnze");
		
	}
	
	if(n == 12){
		
		printf("\nDoze");
		
	}
	
	if(n == 13){
		
		printf("\nTreze");
		
	}
	
	if(n == 14){
		
		printf("\nQuartoze");
		
	}
	
	if(n == 15){
		
		printf("\nQuinze");
		
	}
	
	if(n == 16){
		
		printf("\nDezesseis");
		
	}
	
	if(n == 17){
		
		printf("\nDezessete");
		
	}
	
	if(n == 18){
		
		printf("\nDezoito");
		
	}
	
	if(n == 19){
		
		printf("\nDezenove");
		
	}
	
}
