#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <curses.h>

#define TAM 100

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

void inserir(Registro r, char nome[50], char telefone[11]){
    strcpy(r.nome,nome);
    strcpy(r.telefone,telefone);
}

void exibir(Registro *r){
    system("clear");
    printf("========================== LISTA ==========================\n");
    for(int x = 0; x < TAM; x++){
        printf("Nome: %s", r[x].nome);
        printf("\nTelefone: %s", r[x].telefone);
    }
}

void troca(char c1[50], char c2[50]){
    char temp[50];
    strcpy(temp, c1);
    strcpy(c1, c2);
    strcpy(c2, c1);
}

void SelectionSort(Registro *r){
    Registro menor;
    for(int x = 0; x < TAM - 1; x++){
        strcpy(menor.nome, r[x].nome);
        for(int y = x + 1; y < TAM; y++){
            if(strcmp(r[y].nome, menor.nome) < 0)
                strcpy(menor.nome, r[x].nome);
        }
        if(strcmp(menor.nome, r[x].nome) != 0){
            troca(menor.nome, r[x].nome);
            troca(menor.telefone, r[x].telefone);
        }
    }
}


void main(){
    Registro r1[TAM];
    int op, pos = 0;
    char nome[50], telefone[11];
    do{
        menu();
        scanf("%d", &op);
        switch(op){
            case 1:
                fflush(stdin);
                printf("\nInforme o nome: ");
                fgets(nome, TAM, stdin);
                fflush(stdin);
                printf("\nInforme o telefone: ");
                fgets(nome, TAM, stdin);
                inserir(r1[pos],nome,telefone);
                pos++;
                break;
            case 2:
                exibir(r1);
                break;
            case 3:
                SelectionSort(r1);
                break;
            case 4:
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while(op != 4);

}