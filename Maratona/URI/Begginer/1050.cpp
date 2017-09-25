/* Link: https://www.urionlinejudge.com.br/judge/pt/problems/view/1050*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int ddd;
    cin >> ddd;
    if(ddd == 11)
        cout << "Sao Paulo";
    else if(ddd == 19)
        cout << "Campinas";
    else if(ddd == 21)
        cout << "Rio de Janeiro";
    else if(ddd == 27)
        cout << "Vitoria";
    else if(ddd == 31)
        cout << "Belo Horizonte";
    else if(ddd == 32)
        cout << "Juiz de Fora";
    else if(ddd == 61)
        cout << "Brasilia";
    else if(ddd == 71)
        cout << "Salvador";
    else
        cout << "DDD nao cadastrado";
    cout << endl;
    return 0;
}