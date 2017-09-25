/* Link: https://www.urionlinejudge.com.br/judge/pt/problems/view/1060*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    double a;
    int total = 0;
    for(int i = 0; i<6; i++){
        cin >> a;
        if(a > 0) 
            total++;
    }
    cout << total << " valores positivos" << endl;
    return 0;
}