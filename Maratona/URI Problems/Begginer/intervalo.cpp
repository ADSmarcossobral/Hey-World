/* Link: https://www.urionlinejudge.com.br/judge/pt/problems/view/1037 */

#include <bits/stdc++.h>
using namespace std;

int main(){
    int intervalo[5] = {0,25,50,75,100};
    double num;
    while(cin >> num){
        int fora = 1;
        for(int x = 0; x < 5; x++){
            if(num >= intervalo[x] && num <= intervalo[x + 1]){
                cout << "Intervalo ";
                if(x == 0)
                    cout << "[";
                else
                    cout << "(";
                cout << intervalo[x] << "," << intervalo[x+1] << "]" << endl;
                fora = 0;
                break;
            }
        }
        if(fora == 1)
            cout << "Fora de intervalo" << endl;
    }
    return 0;
}