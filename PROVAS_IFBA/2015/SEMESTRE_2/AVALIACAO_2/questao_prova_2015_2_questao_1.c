#include <stdio.h>

main(){
	
	float chico_alt = 1.5, ze_alt = 1.1, anos = 0;
	
	while(chico_alt >= ze_alt){
		chico_alt = chico_alt + 0.02;
		ze_alt = ze_alt + 0.03;
		anos++;
	}
	
	printf("%.0f anos", anos);
	
}
