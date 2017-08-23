#include <bits/stdc++.h>
using namespace std;

int ehMaior(int n1, int n2, int n3){
    int maior = n1;
    if(n2 > maior && n2 > n3)
        return n2;
    else if(n3 > maior)
        return n3;
    return maior;
}

int main(){
    int n1, n2, n3;
    while(cin >> n1 >> n2 >> n3)
        cout << ehMaior(n1, n2, n3) << " eh o maior" << endl;
}