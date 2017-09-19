/* Link: https://www.urionlinejudge.com.br/judge/pt/problems/view/1047 */

#include <bits/stdc++.h>
using namespace std;

int main(){
    int hi, hf, mi, mf, ht, mt;
    cin >> hi >> mi >> hf >> mf;
    if(hf <= hi)
        ht = hf - hi + 24;
    else
       ht = hf - hi;
    if(mi <= mf)
        mt = mf - mi;
    else{
        ht--;
        mt = mf - mi + 60;
    }
    cout << "O JOGO DUROU " << ht << " HORA(S) E " << mt << " MINUTO(S)" << endl; 
    return 0;
}