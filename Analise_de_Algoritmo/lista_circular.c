#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node *prox;
};

typedef struct node Node;

Node *newNode(){
    return (Node *) malloc(sizeof(Node));
}

Node *insert(Node *lista, int val){
    Node *inicio = lista->prox;
    Node *novo = newNode();
    novo->val = val;
    novo->prox = inicio;
    if(lista->prox == NULL){
        lista->prox = novo;
        novo->prox = novo;
        return novo;
    }else{
        Node *atual = inicio;
        Node *ant;
        do{
            ant = atual;
            atual = atual->prox;
        }while(atual != inicio);
        ant->prox = novo;
        novo->prox = inicio;
    }
    return lista->prox;
}

Node *delete(Node *lista, int val){
    if(lista->prox == NULL)
        return NULL;
    Node *inicio = lista->prox;
    Node *atual = inicio;
    Node *ant = lista;
    do{
        if(atual->val == val){
            if(atual == inicio){
                while(atual->prox != inicio)
                    atual = atual->prox;
                if(atual == inicio){
                    lista->prox = NULL;
                    return atual;
                }
                lista->prox = inicio->prox;
                atual->prox = lista->prox;
                return inicio;
            }else{
                ant->prox = atual->prox;
                return atual;
            }

        }else{
            ant = atual;
            atual = atual->prox;
        }
    }while(atual != inicio);
    return NULL;
}

Node *search(Node *lista, int val){
    if(lista->prox == NULL)
        return NULL;
    Node *inicio = lista->prox;
    Node *atual = inicio;
    do{
        if(atual->val == val)
            return atual;
        atual = atual->prox;
    }while(atual != inicio);
    return NULL;
}

void print(Node *lista){
    printf("\n========================= LISTA CIRCULAR =======================\n");
    if(lista->prox == NULL){
        printf("\nLista vazia!\n");
        return;
    }
    Node *inicio = lista->prox;
    Node *atual = inicio;
    do{
        printf("%d ", atual->val);
        atual = atual->prox;
    }while(atual != inicio);
    printf("\n");
}

void clearList(Node *lista){
    if(lista->prox == NULL)
        return;
    Node *inicio = lista->prox;
    Node *atual = inicio;
    Node *ant;
    do{
        ant = atual;
        atual = atual->prox;
        free(ant);
    }while(atual != inicio);
    lista->prox = NULL;
}

// TESTES
int main(){
    Node *lista = newNode();
    Node *result;
    lista->prox = NULL;
    insert(lista, 10);
    insert(lista, 2);
    insert(lista, 5);
    print(lista);
    result = delete(lista, 10);
    if(result == NULL)
        printf("\nNumero nao encontrado na lista!\n");
    else
        printf("\nNumero %d deletado com sucesso!\n", result->val);
    free(result);
    print(lista);
    result = search(lista, 2);
    if(result == NULL)
        printf("\nNumero nao encontrado na lista!\n");
    else
    printf("\nNumero %d encontrado na lista!\n", result->val);
    result = search(lista, 10);
    if(result == NULL)
        printf("\nNumero nao encontrado na lista!\n");
    else
        printf("\nNumero %d encontrado na lista!\n", result->val);
    clearList(lista);
    return 0;
}