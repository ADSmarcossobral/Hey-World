#include <bits/stdc++.h>
using namespace std;

int main(){
    int cod;
    float qtde[2], preco[2];
    while(cin >> cod >> qtde[0] >> preco[0] >>  cod >> qtde[1] >> preco[1])
        printf("VALOR A PAGAR: R$ %.2f\n", (preco[0] * qtde[0]) + (preco[1] * qtde[1]));
    return 0;
}