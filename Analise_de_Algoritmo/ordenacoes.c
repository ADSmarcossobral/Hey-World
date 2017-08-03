#include <stdio.h>
#include <time.h>
#include <stdlib.h>

clock_t t0, t1;

void merge(int *vetor, int inicio, int meio, int fim){
    int x, y, z;
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;
    // Criando vetores temporários
    int E[n1], D[n2];
    // Copiando dados para os vetores temporários E[] e D[]
    for(x = 0; x < n1; x++)
        E[x] = vetor[inicio+x];
    for(y = 0; y < n2; y++)
        D[y] = vetor[meio + 1 + z];
    x = 0;
    y = 0;
    z = inicio;
    while(x < n1 && y < n2){
        if(E[x] <= D[y]){
            vetor[z] = E[x];
            x++;
        } else{
            vetor[z] = D[y];
            y++;
        }
        z++;
    }
    // Copiando o restante dos elementos de E[]
    while(x < n1){
        vetor[z] = E[x];
        x++;
        z++;
    }
    // Copiando o restante dos elementos de D[]
    while(y < n2){
        vetor[z] = D[y];
        z++;
        y++;
    }

}

void mergeSort(int *vetor, int esq, int dir){
    if(esq < dir){
        int m = esq + (dir-esq) / 2;
        mergeSort(vetor, esq, dir);
        mergeSort(vetor, m+1, dir);
        merge(vetor, esq, m, dir);
    }
}

double insertionSort(int *vetor, int tam){
    t0 = clock();
    //...
    t1 = clock();
    return (double) (t1 - t0) / (CLOCK_PER_SECOND);
}

void preenche(int *vetor, int tam){
    for(int x = 0; x < tam; x++)
        vetor[x] = (int)(rand()%tam);
}

void exibe(int *vetor, int tam){
    for(int x = 0; x < tam; x++)
        printf("%d ", vetor[x]);
    printf("\n");
}

void main(){
    int n = 1000;
    printf("-> MergeSort <-\n");
    while(n <= 100000){
        int vetor[n];
        preenche(vetor,n);
        t0 = clock();
        mergeSort(vetor, 0, n-1);
        t1 = clock();
        double tempo = (double) (t1 - t0) / (CLOCKS_PER_SEC);
        printf("Tempo = %lf, quando n = %d\n", tempo, n);
        n *= 10;
    }
    /*n = 100;
    printf("-> InsertionSort <-\n");
    while(n <= 100000){
        int vetor[n];
        printf("Tempo = %lf, quando n = %d\n", insertionSort(vetor,n), n);
        n *= 10;
    }*/

}