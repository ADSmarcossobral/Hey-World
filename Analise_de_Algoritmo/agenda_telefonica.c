#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <curses.h>

#define TAM 100
#define TAM_NOME 50
#define TAM_TEL 11

typedef struct {
    char nome[50];
    char telefone[11];
} Registro;

void menu(){
    printf("================ MENU =================\n");
    printf("1 -> Inserir\n");
    printf("2 -> Exibir\n");
    printf("3 -> Ordenar\n");
    printf("4 -> Sair\n");
    printf("=======================================\n");
}

void inserir(Registro *r, char nome[50], char telefone[11]){
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
    Registro *temp;
    temp = r1;
    r1 = r2;
    r2 = temp;
}

void SelectionSort(Registro *r, int pos){
    Registro *menor;
    for(int x = 0; x < pos - 1; x++){
        menor = &r[x];
        for(int y = x + 1; y < pos; y++){
            if(strcmp(r[y].nome, menor->nome) < 0)
                menor = &r[y];
        }
        if(strcmp(menor->nome, r[x].nome) != 0){
            troca(menor, &r[x]);
        }
    }
}

void main(){
    Registro r1[TAM];
    int op, pos = 0;
    char nome[TAM_NOME], telefone[TAM_TEL];
    do{
        menu();
        scanf("%d", &op);
        switch(op){
            case 1:
                //__fpurge(stdin);
                printf("\nInforme o nome: ");
                scanf("%s", nome);
               // __fpurge(stdin);
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