/* Link: https://www.urionlinejudge.com.br/judge/pt/problems/view/1022*/

#include <bits/stdc++.h>
using namespace std;

int mdc(int n1, int n2){
    if(n2 == 0)
        return n1;
    return mdc(n2, n1%n2);
}

int main(){
    int cases, n1, n2, d1, d2;
    char op;
    cin >> cases;
    for(int x = 0;x < cases; x++){
        scanf("%d / %d %c %d / %d", &n1, &d1, &op, &n2, &d2);
        int r1 = 0, r2 = 0;
        if(op == '+'){
            r1 = (n1 * d2) + (n2 * d1);
            r2 = d2 * d1;
        } else if(op == '-'){
            r1 = (n1 * d2) - (n2 * d1);
            r2 = d2 * d1;
        } else if(op == '*'){
            r1 = n1 * n2;
            r2 = d1 * d2;
        } else{
            r1 = n1 * d2;
            r2 = n2 * d1;
        }
        cout << r1 << "/" << r2 << " = ";
        int m = mdc(r1,r2);
        if(m < 0) 
            m = m * -1;
        r1 = r1 / m;
        r2 = r2 / m;
        cout << r1 << "/" << r2 << endl;
    }
    return 0;
}