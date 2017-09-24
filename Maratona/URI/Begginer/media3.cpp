/* Link: https://www.urionlinejudge.com.br/judge/pt/problems/view/1040 */

#include <bits/stdc++.h>
using namespace std;

int main(){
    double n[4], media;
    while(cin >> n[0] >> n[1] >> n[2] >> n[3]){
        media = ((n[0]*2) + (n[1]*3) + (n[2]*4) + (n[3])) / (2 + 3 + 4 + 1);
        printf("Media: %.1lf\n", media);
        if(media >= 7.0)
            cout << "Aluno aprovado." << endl;
        else if(media < 5.0)
            cout << "Aluno reprovado." << endl;
        else{
            cout << "Aluno em exame." << endl;
            double nota;
            cin >> nota;
            printf("Nota do exame: %.1lf\n", nota);
            media = (media + nota) / 2;
            if(media >= 5.0)
                cout << "Aluno aprovado." << endl;
            else
                cout << "Aluno reprovado." << endl;
            printf("Media final: %.1lf\n", media);
        }
    }
    return 0;
}