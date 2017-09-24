/* Link: https://www.urionlinejudge.com.br/judge/pt/problems/view/1038 */

#include <bits/stdc++.h>
using namespace std;

int main(){
    int cod, qt;
    while(cin >> cod >> qt){
        printf("Total: R$ ");
        if(cod == 1)
            printf("%.2f", qt * 4.00);
        else if(cod == 2)
            printf("%.2f", qt * 4.50);
        else if(cod == 3)
            printf("%.2f", qt * 5.00);
        else if(cod == 4)
            printf("%.2f", qt * 2.00);
        else
            printf("%.2f", qt * 1.50);
        cout << endl;
    }
    return 0;
}