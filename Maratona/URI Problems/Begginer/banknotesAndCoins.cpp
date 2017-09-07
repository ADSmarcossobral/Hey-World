#include <bits/stdc++.h>
using namespace std;

int main(){
    double saque, coins[6] = {1.00, 0.50, 0.25, 0.10, 0.05, 0.01}, notas[6] = {100, 50, 20, 10, 5, 2};
    int qtde = 0;
    while(cin >> saque){
         cout << "NOTAS:" << endl;
         for(int x = 0; x < 6; x++){
          qtde = 0;
          while(saque >= notas[x]){
              saque -= notas[x];
              qtde++;
          }
         printf("%d nota(s) de R$ %.2lf \n", qtde, notas[x]);
        }
            cout << "MOEDAS:" << endl;
         for(int x = 0; x < 6; x++){
           qtde = 0;
           while(saque >= coins[x]){
                 saque -= coins[x];
                qtde++;
            }
            printf("%d moeda(s) de R$ %.2lf \n", qtde, coins[x]);
        }
    }
    return 0;
}