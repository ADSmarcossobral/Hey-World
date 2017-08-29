#include <bits/stdc++.h>
using namespace std;

int main(){
    int seconds;
    while(cin >> seconds){
        int horas, minutos, segundos;
        horas = seconds / 3600;
        seconds = seconds - (horas * 3600);
        minutos = seconds / 60;
        seconds = seconds - (minutos * 60);
        segundos = seconds;
        cout << horas << ":" << minutos << ":" << segundos << endl;
    }
    return 0;
}