/* Link: https://www.urionlinejudge.com.br/judge/pt/problems/view/1047 */

#include <bits/stdc++.h>
using namespace std;

int main(){
    double salario, novo, reajuste;
    cin >> salario;
    cout << fixed;
    cout << setprecision(2);
    cout << "Novo salario: ";
    if(salario <= 400){
        reajuste = salario * 0.15;
        novo = salario + reajuste;
        cout << novo << endl;
        cout << "Reajuste ganho: " << reajuste << endl;
        cout << "Em percentual: 15 %" << endl; 
    } else if(salario > 400 && salario <= 800){
        reajuste = salario * 0.12;
        novo = salario + reajuste;
        cout << novo << endl;
        cout << "Reajuste ganho: " << reajuste << endl;
        cout << "Em percentual: 12 %" << endl; 
    }else if(salario > 800 && salario <= 1200){
        reajuste = salario * 0.10;
        novo = salario + reajuste;
        cout << novo << endl;
        cout << "Reajuste ganho: " << reajuste << endl;
        cout << "Em percentual: 10 %" << endl; 
    }else if(salario > 1200 && salario <= 2000){
        reajuste = salario * 0.07;
        novo = salario + reajuste;
        cout << novo << endl;
        cout << "Reajuste ganho: " << reajuste << endl;
        cout << "Em percentual: 7 %" << endl; 
    }else if(salario > 2000){
        reajuste = salario * 0.04;
        novo = salario + reajuste;
        cout << novo << endl;
        cout << "Reajuste ganho: " << reajuste << endl;
        cout << "Em percentual: 4 %" << endl; 
    }
    return 0;
}