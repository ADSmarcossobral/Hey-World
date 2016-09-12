#include <stdio.h>

main(){
	
	float n1, n2, n3;
	
	scanf("%f%f%f", &n1, &n2, &n3);
	
	if(n1 > n3 && n2 > n3){
		printf("%.2f", n1 + n2);
	} else if(n1 > n2 && n3 > n2){
		printf("%.2f", n1 + n3);
	} else{
		printf("%.2f", n2 + n3);
	}
	
}
