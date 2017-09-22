#include <bits/stdc++.h>

using namespace std;


// Representação de uma árvore henária
struct No{
    int peso;
    vector<No*> adj;
};

int maiorSoma(No *r){
    int maior = -1;
    queue<No*> fila;
    fila.push(r);
    No* atual;
    while(!fila.empty()){
        atual = fila.front();
        fila.pop();
        for(No* filho : atual->adj){
            fila.push(filho);
            int soma = filho->peso + atual->peso;
            if(maior == -1 || soma > maior)
                maior = soma;
        }
    }
    return maior;
}

No *add(No* raiz, No* filho){
    if(raiz == NULL)
        return filho;
    else if(){
        r->adj.push(filho);
    }
}



int main(){

    return 0;
}