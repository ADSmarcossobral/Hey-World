#include <stdio.h>
#include <time.h>
#include <stdlib.h>

clock_t t0, t1;

void troca(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

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
        D[y] = vetor[meio + 1 + y];
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
        int meio = (dir + esq) / 2;
        mergeSort(vetor, esq, meio);
        mergeSort(vetor, meio+1, dir);
        merge(vetor, esq, meio, dir);
    }
}  

int particiona(int *vetor, int ini, int fim){
    int x, i, aux, j;
    x = vetor[fim];
    i = ini - 1;
    for(j = ini; j < fim; j++){
        if(vetor[j] <= x){
            i++;
            troca(&vetor[i], &vetor[j]);
        }
    }
    troca(&vetor[i+1], &vetor[fim]);
    return i + 1;
}

void quickSort(int *vetor, int ini, int fim){
    if(ini >= fim)
        return;
    int pivot = particiona(vetor,ini,fim);
    quickSort(vetor, ini, pivot - 1);
    quickSort(vetor, pivot + 1, fim);
}

double insertionSort(int *vetor, int tam){
    t0 = clock();
    int atual, y;
    for(int x = 1; x < tam; x++){ // N - 1
        atual = vetor[x];
        y = x - 1;
        while((y >= 0) && (atual < vetor[y])){ // (2 + N - 1) * (N - 1) / 2
            vetor[y+1] = vetor[y];
            y--;
        }
        vetor[y+1] = atual;
    }
    t1 = clock();
    // T(N) = 4(N - 1) + 3((N + 1) * (N - 1)) / 2
    // O(N²)
    return (double) (t1 - t0) / (CLOCKS_PER_SEC);
}

double selectionSort(int *vetor, int tam){
    t0 = clock();
    int menor;
    for(int x = 0; x < tam - 1; x++){ // (N - 1)
        menor = x;
        for(int y = x + 1; y < tam; y++){ // (N + 1) (N - 1 ) / 2
            if(vetor[y] < vetor[menor])
                menor = y;
        }
        if(menor != x)
            troca(&vetor[x], &vetor[menor]);
    }
    t1 = clock();
    // T(N) = 4(N - 1) + 3((N + 1) (N - 1) / 2)
    // O(N²)
    return (double) (t1 - t0) / (CLOCKS_PER_SEC); 
}

double bubbleSort(int *vetor, int tam){
    t0 = clock();
    for(int x = tam - 1; x > 0; x--){ // (N - 1)
        for(int y = 0; y < x; y++){ // N * (N - 1) / 2
            if(vetor[y] > vetor[y+1])
                troca(&vetor[y], &vetor[y+1]);
        }
    }
    t1 = clock();
    // T(N) = (N - 1) + 3((N * N - 1) / 2)
    // O(N²)
    return (double) (t1 - t0) / (CLOCKS_PER_SEC);
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

int main(){
    int n = 32, *vetor;
    double tempo;
    printf("\n============================ BUBBLE SORT ===========================\n");
    while(n <= 128){
        vetor = (int *) malloc(sizeof(int) * n);
        preenche(vetor, n);
        printf("\nVetor nao ordenado: \n");
        exibe(vetor, n);
        tempo = bubbleSort(vetor, n);
        printf("\nVetor ordenado: \n");
        exibe(vetor, n);
        printf("\nTamanho do vetor = %d\n", n);
        printf("\nTempo de execucao para ordenacao = %lf\n", tempo);
        n *= 2;
        free(vetor);
        printf("_________________________________________________________________");
    }
    printf("\n===================================================================\n");
    n = 32;
    printf("\n============================ SELECTION SORT =======================\n");
    while(n <= 128){
        vetor = (int *) malloc(sizeof(int) * n);
        preenche(vetor, n);
        printf("\nVetor nao ordenado: \n");
        exibe(vetor, n);
        tempo = selectionSort(vetor, n);
        printf("\nVetor ordenado: \n");
        exibe(vetor, n);
        printf("\nTamanho do vetor = %d\n", n);
        printf("\nTempo de execucao para ordenacao = %lf\n", tempo);
        n *= 2;
        free(vetor);
        printf("_________________________________________________________________");
    }
    printf("\n===================================================================\n");
    n = 32;
    printf("\n============================ INSERTION SORT =======================\n");
    while(n <= 128){
        vetor = (int *) malloc(sizeof(int) * n);
        preenche(vetor, n);
        printf("\nVetor nao ordenado: \n");
        exibe(vetor, n);
        tempo = insertionSort(vetor, n);
        printf("\nVetor ordenado: \n");
        exibe(vetor, n);
        printf("\nTamanho do vetor = %d\n", n);
        printf("\nTempo de execucao para ordenacao = %lf\n", tempo);
        n *= 2;
        free(vetor);
        printf("_________________________________________________________________");
    }
    printf("\n===================================================================\n");
    n = 32;
    printf("\n============================ QUICK SORT ===========================\n");
    while(n <= 128){
        vetor = (int *) malloc(sizeof(int) * n);
        preenche(vetor, n);
        printf("\nVetor nao ordenado: \n");
        exibe(vetor, n);
        t0 = clock();
        quickSort(vetor, 0, n-1);
        t1 = clock();
        tempo = (double) (t1 - t0) / (CLOCKS_PER_SEC);
        printf("\nVetor ordenado: \n");
        exibe(vetor, n);
        printf("\nTamanho do vetor = %d\n", n);
        printf("\nTempo de execucao para ordenacao = %lf\n", tempo);
        n *= 2;
        free(vetor);
        printf("_________________________________________________________________");
    }
    printf("\n===================================================================\n");
    n = 32;
    printf("\n============================ MERGE SORT ===========================\n");
    while(n <= 128){
        vetor = (int *) malloc(sizeof(int) * n);
        preenche(vetor, n);
        printf("\nVetor nao ordenado: \n");
        exibe(vetor, n);
        t0 = clock();
        mergeSort(vetor, 0, n-1);
        t1 = clock();
        tempo = (double) (t1 - t0) / (CLOCKS_PER_SEC);
        printf("\nVetor ordenado: \n");
        exibe(vetor, n);
        printf("\nTamanho do vetor = %d\n", n);
        printf("\nTempo de execucao para ordenacao = %lf\n", tempo);
        n *= 2;
        free(vetor);
        printf("_________________________________________________________________");
    }
    printf("\n===================================================================\n");
   return 0; 
}