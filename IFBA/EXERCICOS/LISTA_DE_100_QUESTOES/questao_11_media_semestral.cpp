#include <stdio.h>

main(){
	
	float bi_1_nota_1, bi_1_nota_2, bi_2_nota_1, bi_2_nota_2, media_bi_1, media_bi_2, media_semestre;
	
	scanf("%f", &bi_1_nota_1);
	scanf("%f", &bi_1_nota_2);
	scanf("%f", &bi_2_nota_1);
	scanf("%f", &bi_2_nota_2);
	
	media_bi_1 = (bi_1_nota_1 + bi_1_nota_2) / 2;
	media_bi_2 = (bi_2_nota_1 + bi_2_nota_2) / 2;
	
	media_semestre = (media_bi_1 + media_bi_2) / 2;
	
	
}
