#include <stdio.h>

main(){
	
	int n;
	
	scanf("%d", &n);
	
	if(n <= 999 && n >= 100){
		
		printf("%d%d%d", n % 10, (n / 10) % 10, n / 100); 
		
	} else{
		printf("Numero invalido");
	}
	
}
