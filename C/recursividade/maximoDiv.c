#include <stdio.h>

int maximoDiv(int x, int y, int n){
	if(n > x || n > y)
		return 1;
	if(y == 0)
		return x;
	if(x == 0)
		return y;
	if(x % n == 0 && y % n == 0){
		x = maximoDiv(x/n,y,n) + x/n;
		y = maximoDiv(x,y/n,n) + y/n;
		return maximoDiv(x,y,n+1) * n;	
	} else{
		
	}
}

void main(){
	printf("%d", maximoDiv(15,5,2));
}
