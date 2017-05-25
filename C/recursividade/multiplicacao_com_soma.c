#include <stdio.h>

int Multip_Rec(int n1, int n2){
	if(n2 == 0)
		return 0;
	return Multip_Rec(n1,n2-1) + n1;
}

void main(){
	printf("%d", Multip_Rec(5,10));
}
