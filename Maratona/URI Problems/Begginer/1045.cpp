/* Link: https://www.urionlinejudge.com.br/judge/pt/problems/view/1045 */

#include <bits/stdc++.h>
using namespace std;

int main(){
    double a, b, c, temp;
    cin >> a >> b >> c;
    // Ordenação
    if(a < b){
        temp = b;
        b = a;
        a = temp;
    }
    if(b < c){
        temp = c;
        c = b;
        b = temp;
        if(a < b){
            temp = a;
            a = b;
            b = temp;
        }
    }
    // Verificando o tipo do triângulo
    if(a >= b + c)
        cout << "NAO FORMA UM TRIANGULO" << endl;
    else{
        if((a*a) == (b*b) + (c*c))
            cout << "TRIANGULO RETANGULO" << endl;
        if((a*a) > (b*b) + (c*c))
            cout << "TRIANGULO OBTUSANGULO" << endl;
        if((a*a) < (b*b) + (c*c))
            cout << "TRIANGULO ACUTANGULO" << endl;
        if(a == b && a == c)
            cout << "TRIANGULO EQUILATERO" << endl;
        if((a == b && a != c) || (a == c && a != b) || (c == b && c != a))
            cout << "TRIANGULO ISOSCELES" << endl;
    }
    return 0;
}