/* Link: https://www.urionlinejudge.com.br/judge/pt/problems/view/1064*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    double v, soma = 0;
    int total = 0;
    for(int i = 0; i<6; i++){
        cin >> v;
        if(v > 0){
            total++;
            soma += v;
        }
    }
    cout << total << " valores positivos" << endl;
    printf("%.1f\n", soma / total);
    return 0;
}