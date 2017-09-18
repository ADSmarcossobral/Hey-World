/* Link: https://www.urionlinejudge.com.br/judge/pt/problems/view/1044 */

#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    if(a % b == 0 || b % a == 0)
        cout << "Sao Multiplos" << endl;
    else    
        cout << "Nao sao Multiplos" << endl;
    return 0;
}