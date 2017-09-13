/* Link da questão: https://www.urionlinejudge.com.br/judge/pt/problems/view/1036 */

#include <bits/stdc++.h>
using namespace std;

int main(){
    double a, b, c, r1, r2, delta;
    while(cin >> a >> b >> c){
        delta = (b*b) - (4 * a * c);
        if(delta < 0 || a == 0){
            cout << "Impossivel calcular" << endl;
        } else{
            r1 = ((b*-1) + sqrt(delta)) / (2 * a);
            r2 = ((b*-1) - sqrt(delta)) / (2 * a);
            printf("R1 = %.5lf\n", r1);
            printf("R2 = %.5lf\n", r2); 
        }
    }
    return 0;
}