/* Código com tipo de acesso hierárquico em árvores binárias */

#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node *esq;
    int num;
    struct node *dir;
};

typedef struct node Node;

void limpa(){
    printf("\nPressione qualquer tecla para continuar\n");
    system("read x");
    system("clear");
}

void checaMem(Node *no){
    if(!no){
        printf("\nSem memoria disponivel!\n");
        exit(1);
    }
}

void preOrdem(Node *r){
    if(r != NULL){
        printf("%d ", r->num);
        preOrdem(r->esq);
        preOrdem(r->dir);
    }
}

void posOrdem(Node *r){
    if(r != NULL){
        posOrdem(r->esq);
        posOrdem(r->dir);
        printf("%d ", r->num);
    }
}

void emOrdem(Node *r){
    if(r != NULL){
        emOrdem(r->esq);
        printf("%d ", r->num);
        emOrdem(r->dir);
    }
}

void inserir(Node *raiz, Node *novo){
    if(raiz == NULL){
        raiz = novo;
    } else{
        if(novo->num < raiz->num)
            inserir(raiz->esq, novo);
        else if(novo->num > raiz->num)
            inserir(raiz->dir, novo);
        else{
            // Código para se for igual
        }
    }
}

int menu(){
    limpa();
    system("clear");
    printf("================ MENU =================\n");
    printf("1 -> Inserir\n");
    printf("2 -> Pre-ordem\n");
    printf("3 -> Pos-ordem\n");
    printf("4 -> Em ordem\n");
    printf("5 -> Sair\n");
    printf("=======================================\n");
    int op;
    printf("\nEscolha uma opcao: ");
    scanf("%d", &op);
    return op;
}

int checaRaiz(Node *raiz){
    if(raiz == NULL){
        printf("\nArvore vazia!\n");
        return 1;
    }
    return 0;
}

int opcao(int op, Node *raiz){
    if(op == 1){
        int num;
        printf("Informe o numero a ser inserido: ");
        scanf("%d", &num);
        Node *novo = (Node *)malloc(sizeof(Node));
        checaMem(novo);
        novo->num = num;
        novo->esq = NULL;
        novo->dir = NULL;
        inserir(raiz, novo);
    } else if(op == 2){
        printf("\n================= PRE-ORDEM ================\n");
        if(checaRaiz(raiz))
            preOrdem(raiz);
    } else if(op == 3){
        printf("\n================= POS-ORDEM ================\n");
        if(checaRaiz(raiz))
            posOrdem(raiz);
    } else if(op == 4){
        printf("\n================= EM ORDEM ================\n");
        if(checaRaiz(raiz))
            emOrdem(raiz);
    } else if(op == 5){
        printf("\nPrograma finalizado!!!\n");
        return 1;
    }
    return 0;
}

int main(){
    Node *raiz = (Node *) malloc(sizeof(Node));
    raiz = NULL;
    while(opcao(menu(),raiz) != 1);
    free(raiz);
    return 0;
}