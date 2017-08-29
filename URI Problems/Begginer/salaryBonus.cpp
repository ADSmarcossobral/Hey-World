#include <bits/stdc++.h>
using namespace std;

int main(){
    string nome;
    float salary, bonus;
    while(cin >> nome >> salary >> bonus)
        printf("TOTAL = R$ %.2f\n", salary + (bonus * 0.15));
    return 0;
}