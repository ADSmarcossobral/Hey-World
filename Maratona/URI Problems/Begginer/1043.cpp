/* Link: https://www.urionlinejudge.com.br/judge/pt/problems/view/1043 */

#include <bits/stdc++.h>
using namespace std;

int main(){
    double a, b, c;
    cin >> a >> b >> c;
    if((a < b + c) && (b < a + c) && (c < a + b))
        printf("Perimetro = %.1lf\n", a + b + c);
    else
        printf("Area = %.1lf\n", ((a+b) * c) / 2);
    return 0;
}