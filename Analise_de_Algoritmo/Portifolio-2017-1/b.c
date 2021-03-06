#include <stdio.h>
#include <time.h>
#include <stdlib.h>

clock_t t0, t1;

int fiboRec(int termo){
    if(termo == 1){
        return 0;
    }
    else if(termo == 2){
        return 1;
    }else
        return fiboRec(termo-1) + fiboRec(termo-2);
}

int fiboInter(int n){
    int *fibo = (int *) malloc(n * sizeof(int));
    if(n == 1)
        return 0;
    if(n == 2)
        return 1;
    fibo[0] = 0;
    fibo[1] = 1;
    for(int x = 0; x < n; x++){
        if(x > 0 && x != n - 1)
            fibo[x+1] = fibo[x] + fibo[x-1];
    }
    return fibo[n-1];
}

int main(){
    int cont = 1;
    double tempo;
    printf("================ FIBONACCI RECURSIVO =================\n");
    printf("\nOs 5 primeiros termos: ");
    t0 = clock();
    while(cont <= 5)
        printf("%d ", fiboRec(cont++));
    t1 = clock();
    tempo = (double) (t1 - t0) / (CLOCKS_PER_SEC);
    printf("\nTempo de execucao %lf\n", tempo);
    cont = 1;
    printf("\nOs termos dos primeiros 20 tempos: ");
    t1 = 0;
    t0 = clock();
    while((double) (t1 - t0) / (CLOCKS_PER_SEC) < 0.000020){
        printf("%d ", fiboRec(cont++));
        t1 = clock();
    }
    printf("\nTempo de execucao %lf\n", (double) (t1 - t0) / (CLOCKS_PER_SEC));
    printf("\n================ FIBONACCI INTERATIVO =================\n");
    printf("\nOs 5 primeiros termos: ");
    cont = 1;
    t0 = clock();
    while(cont <= 5)
        printf("%d ", fiboInter(cont++));
    t1 = clock();
    tempo = (double) (t1 - t0) / (CLOCKS_PER_SEC);
    printf("\nTempo de execucao %lf\n", tempo);
    printf("\nOs termos dos primeiros 20 tempos: ");
    cont = 1;
    t1 = 0;
    t0 = clock();
    while((double) (t1 - t0) / (CLOCKS_PER_SEC) < 0.000020){
        printf("%d ", fiboRec(cont++));
        t1 = clock();
    }
    printf("\nTempo de execucao %lf\n", (double) (t1 - t0) / (CLOCKS_PER_SEC));
    return 0;
}