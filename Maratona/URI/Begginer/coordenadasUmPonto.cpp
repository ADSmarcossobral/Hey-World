/* Link: https://www.urionlinejudge.com.br/judge/pt/problems/view/1041 */

#include <bits/stdc++.h>
using namespace std;

int main(){
    double x, y;
    while(cin >> x >> y){
        if(x == 0 && y == 0)
            cout << "Origem";
        else if(x == 0)
            cout << "Eixo Y";
        else if(y == 0)
            cout << "Eixo X";
        else if(x > 0 && y > 0)
            cout << "Q1";
        else if(x > 0 && y < 0)
            cout << "Q4";
        else if(x < 0 && y > 0)
            cout << "Q2";
        else if(x < 0 && y < 0)
            cout << "Q3";
        cout << endl;
    }
    return 0;
}