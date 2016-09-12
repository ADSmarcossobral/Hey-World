#include <stdio.h>

main(){
	
	float dsa, vpv, atc;
	
	scanf("%f%f%f", &dsa, &vpv, &atc);
	
	printf("%.1f segundos depois", (dsa / vpv - (vpv / atc) - 3));
	
	
}
