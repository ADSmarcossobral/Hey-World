#include <bits/stdc++.h>
#define pesoA 3.5
#define pesoB 7.5
using namespace std;

int main(){
    float a, b;
    while(cin >> a >> b)
        printf("MEDIA = %.5f\n", ((a * pesoA) + (b * pesoB)) / 11);
    return 0;  
}