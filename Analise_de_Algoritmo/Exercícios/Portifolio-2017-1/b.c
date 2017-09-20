#include <stdio.h>
#include <time.h>

clock_t t0, t1;

int fiboRec(int termo){
    if(termo == 1){
        return 0;
    }
    else if(termo == 2){
        return 1;
    }
    else
        return fiboRec(termo-1) + fiboRec(termo-2);
}

int fiboInter(int n){

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
    printf("\nOs termos dos primeiros 20 segundos: ");
    t1 = 0;
    t0 = clock();
    while((double) (t1 - t0) / (CLOCKS_PER_SEC) < 20){
        printf("%d ", fiboRec(cont++));
        t1 = clock();
    }
    printf("\nTempo de execucao %lf\n", (double) (t1 - t0) / (CLOCKS_PER_SEC));
    return 0;
}