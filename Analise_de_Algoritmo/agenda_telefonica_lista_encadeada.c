#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAM_REG 100
#define TAM_NOME 50
#define TAM_TEL 11

struct registro{
    char nome[TAM_NOME];
    char telefone[TAM_TEL];
    struct registro *prox;
};

typedef struct registro Registro;

void menu(){
    printf("================ MENU =================\n");
    printf("1 -> Inserir\n");
    printf("2 -> Exibir\n");
    printf("3 -> Ordenar\n");
    printf("4 -> Sair\n");
    printf("=======================================\n");
}

void checaMem(Registro *reg){
    if(!reg){
        printf("\nSem memoria disponivel!\n");
        exit(1);
    }
}

void inserir(Registro *LISTA, char nome[TAM_NOME], char telefone[TAM_TEL]){
    Registro *novo = (Registro *) malloc(sizeof(Registro));
    checaMem(novo);
    novo->prox == NULL;
    if(LISTA->prox == NULL){
        LISTA->prox = novo;
    } else{
        Registro *tmp;
        tmp = LISTA->prox;
        while(tmp->prox != NULL)
            tmp = tmp->prox;
        tmp->prox = novo;
    }
    strcpy(novo->nome, nome);
    strcpy(novo->telefone, telefone);
}

void toString(Registro *tmp){
        printf("Nome: %s\n", tmp->nome);
        printf("\nTelefone: %s\n", tmp->telefone);
        printf("___________________________________________\n");
}

void exibir(Registro *LISTA){
    system("clear");
    printf("\n========================== LISTA ==========================\n");
    if(LISTA->prox == NULL)
        printf("\nLista vazia!\n");
    else{
        Registro *tmp;
        tmp = LISTA->prox;
        do{
            toString(tmp);
            tmp = tmp->prox;
        } while(tmp != NULL);
    }
}

void troca(Registro *r1, Registro *r2){
    Registro temp;
    temp = *r1;
    *r1 = *r2;
    *r2 = temp;
}

void apagarLista(Registro *LISTA){
    if(LISTA->prox == NULL)
        printf("\nNao existe registros na lista!\n");
    else{
        Registro *atual;
        Registro *proxReg;
        atual = LISTA->prox;
        proxReg = atual->prox;
        do{
            free(atual);
            atual = proxReg;
            proxReg = atual->prox;
        } while(atual != NULL);
    }
}

void SelectionSort(Registro *LISTA){
    if(LISTA->prox == NULL)
        printf("\nNao existe registros na lista!\n");
    else{
        Registro *menor;
        Registro *atualX = LISTA->prox;
        while(atualX->prox != NULL){
            menor = atualX;
            Registro *atualY = atualX->prox;
            while(atualY != NULL){
                if(strcmp(atualY->nome, menor->nome) < 0){
                    menor = atualY;
                }
                atualY = atualY->prox;            
            }
            if(menor != atualX){
                troca(menor, atualX);
            }
            atualX = atualX->prox;
        }
    }
}

void main(){
    Registro *LISTA = (Registro *) malloc(sizeof(Registro));
    LISTA->prox = NULL;
    int op, pos = 0;
    char nome[TAM_NOME], telefone[TAM_TEL];
    do{
        menu();
        scanf("%d", &op);
        switch(op){
            case 1:
                printf("\nInforme o nome: ");
                scanf("%s", nome);
                printf("\nInforme o telefone: ");
                scanf("%s", telefone);
                inserir(LISTA, nome, telefone);
                pos++;
                break;
            case 2:
                exibir(LISTA);
                break;
            case 3:
                SelectionSort(LISTA);
                break;
            case 4:
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while(op != 4);
    apagarLista(LISTA);
}