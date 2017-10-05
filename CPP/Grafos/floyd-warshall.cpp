#include <bits/stdc++.h>
using namespace std;

int min(int a, int b){
    if(a < b)
        return a;
    return b;
}

void menorCaminho(int **matriz, int n){
    for(int x = 0; x < n; x++)
        for(int y = 0; y < n; y++)
            for(int z = 0; z < n; z++)
                matriz[y][z] = min(matriz[y][z], matriz[y][x] + matriz[x][z]);
}

