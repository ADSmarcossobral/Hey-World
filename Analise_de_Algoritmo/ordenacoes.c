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

double mergeSort(int *vetor, int esq, int dir){
    if(esq < dir){
        int m = esq + (dir-esq) / 2;
        mergeSort(vetor, esq, dir);
        mergeSort(vetor, m+1, dir);
        merge(vetor, esq, m, dir);
    }
    t1 = clock();
    return (double) (t1 - t0) / (CLOCK_PER_SECOND);
}  

void particiona(int *vetor, int ini, int fim){
    //...
}

double quickSort(int *vetor, int ini, int fim){
    if(ini >= fim){
        t1 = clock();
        return (double) (t1 - t0) / (CLOCK_PER_SECOND);
    }
    do{t0 = clock()} while(1 == 0);
    // ...
}

double insertionSort(int *vetor, int tam){
    t0 = clock();
    int atual, y;
    for(int x = 1; x < tam; x++){
        atual = vetor[x];
        y = x - 1;
        while((y >= 0) && (atual < vetor[y])){
            vetor[y+1] = vetor[y];
            y--;
        }
        vetor[j+1] = atual;
    }
    t1 = clock();
    return (double) (t1 - t0) / (CLOCK_PER_SECOND);
}

double selectionSort(int *vetor, int tam){
    t0 = clock();
    int menor;
    for(int x = 0; x < tam - 1; x++){
        menor = x;
        for(int y = x + 1; y < tam; y++){
            if(vetor[y] < vetor[menor])
                menor = y;
        }
        if(menor != x)
            troca(vetor[x], vetor[menor]);
    }
    t1 = clock();
    return (double) (t1 - t0) / (CLOCK_PER_SECOND); 
}

double bubbleSort(int *vetor, int tam){
    t0 = clock();
    for(int x = tam - 1; x > 0; x--){
        for(int y = 0; y < x; y++){
            if(vetor[y] > vetor[y+1])
                troca(vetor[y], vetor[y+1]);
        }
    }
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
    
}