#include <bits/stdc++.h>
using namespace std;

int main(){
    int saque, notas[7] = {100, 50, 20, 10, 5, 2, 1}, qtde;
    while(cin >> saque){
        cout << saque << endl;
        for(int x = 0; x < 7; x++){
            qtde = 0;
            while(saque >= notas[x]){
                saque -= notas[x];
                qtde++;
            }
            cout << qtde << " nota(s) de R$ " << notas[x] << ",00" << endl;
        }
    }
    return 0;
}