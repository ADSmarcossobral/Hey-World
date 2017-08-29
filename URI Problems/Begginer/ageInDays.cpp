#include <bits/stdc++.h>
using namespace std;

int main(){
    int day;
    while(cin >> day){
        int anos = day / 365;
        day -= (anos * 365);
        int meses = day / 30;
        day -= (meses * 30);
        cout << anos << " ano(s)" << endl;
        cout << meses << " mes(es)" << endl;
        cout << day << " dia(s)" << endl;
    }
    return 0;
}