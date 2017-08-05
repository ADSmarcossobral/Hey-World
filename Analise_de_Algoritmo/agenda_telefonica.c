#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAM_REG 100
#define TAM_NOME 50
#define TAM_TEL 11

typedef struct {
    char nome[TAM_NOME];
    char telefone[TAM_TEL];
} Registro;

void menu(){
    printf("================ MENU =================\n");
    printf("1 -> Inserir\n");
    printf("2 -> Exibir\n");
    printf("3 -> Ordenar\n");
    printf("4 -> Sair\n");
    printf("=======================================\n");
}

void inserir(Registro *r, char nome[TAM_NOME], char telefone[TAM_TEL]){
    strcpy(r->nome,nome);
    strcpy(r->telefone,telefone);
}

void exibir(Registro *r, int pos){
    system("clear");
    printf("\n========================== LISTA ==========================\n");
    for(int x = 0; x < pos; x++){
        printf("Nome: %s\n", r[x].nome);
        printf("\nTelefone: %s\n", r[x].telefone);
        printf("___________________________________________\n");
    }
}

void troca(Registro *r1, Registro *r2){
    Registro temp;
    temp = *r1;
    *r1 = *r2;
    *r2 = temp;
}

void SelectionSort(Registro *r, int pos){
    char menor[TAM_NOME];
    int pos_menor;
    for(int x = 0; x < pos - 1; x++){
        strcpy(menor,r[x].nome);
        pos_menor = x;
        for(int y = x + 1; y < pos; y++){
            if(strcmp(r[y].nome, menor) < 0){
                strcpy(menor, r[y].nome);
                pos_menor = y;
            }                
        }
        if(pos_menor != x){
            troca(&r[pos_menor], &r[x]);
        }
    }
}

void main(){
    Registro r1[TAM_REG];
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
                inserir(&r1[pos],nome,telefone);
                pos++;
                break;
            case 2:
                exibir(r1, pos);
                break;
            case 3:
                SelectionSort(r1, pos);
                break;
            case 4:
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while(op != 4);

}