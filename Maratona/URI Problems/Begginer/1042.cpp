/* Link: https://www.urionlinejudge.com.br/judge/pt/problems/view/1042*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    int abc[3];
    abc[0] = a;
    if(b < abc[0]){
        abc[1] = abc[0];
        abc[0] = b;
    } else
        abc[1] = b;
    if(c < abc[1]){
        abc[2] = abc[1];
        abc[1] = c;
        if(abc[1] < abc[0]){
            int temp = abc[1];
            abc[1] = abc[0];
            abc[0] = temp;
        }
    } else
        abc[2] = c;
    cout << abc[0] << endl << abc[1] << endl << abc[2] << endl;
    cout << endl << a << endl << b << endl << c << endl;
    return 0;
}