#include <stdio.h>

int mdc(int x, int y){
	if(y == 0)
		return x;
	else{
		return mdc(y, x%y);
	}

}

void main(){
	printf("%d\n", mdc(15,25));
}
