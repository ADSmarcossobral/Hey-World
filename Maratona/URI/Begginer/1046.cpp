/* Link: https://www.urionlinejudge.com.br/judge/pt/problems/view/1046 */

#include <bits/stdc++.h>
using namespace std;

int main(){
    int hi, hf;
    cin >> hi >> hf;
    cout << "O JOGO DUROU ";
    if(hf <= hi)
        cout << hf - hi + 24;
    else
        cout << hf - hi;
    cout << " HORA(S)" << endl;
    return 0;
}