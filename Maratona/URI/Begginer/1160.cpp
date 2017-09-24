/* Link: https://www.urionlinejudge.com.br/judge/pt/problems/view/1160*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int casos, pa, pb;
    double g1, g2, anos;
    cin >> casos;
    while(casos > 0){
        pa = pb = g1 = g2 = anos = 0;
        cin >> pa >> pb >> g1 >> g2;
        while(pa <= pb && anos <= 100){
            pa += (pa * (g1/100));
            pb += (pb * (g2/100));
            anos++;
        }
        if(anos > 100)
           cout << "Mais de 1 seculo." << endl;
        else
            cout << anos << " anos." << endl;
        casos--;
    }
    return 0;
}