#include <bits/stdc++.h>
using namespace std;

int main(){
    int num, hours;
    float value;
    while(cin >> num >> hours >> value)
        printf("NUMBER = %d\nSALARY = U$ %.2f\n", num, hours * value);
    return 0;
}