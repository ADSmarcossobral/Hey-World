#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;

double exp3(double number){
    double result = 1;
    for(int x = 0; x < 3; x++)
        result *= number;
    return result;
}

int main(){
    double value;
    while(cin >> value)
        printf("VOLUME = %.3f\n", (4/3.0) * pi * exp3(value));
    return 0;
}