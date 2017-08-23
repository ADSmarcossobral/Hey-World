#include <bits/stdc++.h>
using namespace std;

int main(){
    int distance;
    float fuel;
    while(cin >> distance >> fuel)
        printf("%.3f km/l\n", distance / fuel);
    return 0;
}