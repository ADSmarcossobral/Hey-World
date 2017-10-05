#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAM_NOME 50
#define TAM_TEL 11

typedef struct {
    char nome[TAM_NOME];
    char telefone[TAM_TEL];
} Registro;

void getch(){
    system("read x");
}

void menu(){
    system("clear");
    printf("================ MENU =================\n");
    printf("1 -> Inserir\n");
    printf("2 -> Exibir\n");
    printf("3 -> Ordenar\n");
    printf("4 -> Total de registros\n");
    printf("5 -> Tamanho maximo da lista\n");
    printf("6 -> Sair\n");
    printf("=======================================\n");
}

void inserir(Registro *r, char nome[TAM_NOME], char telefone[TAM_TEL]){
    strcpy(r->nome,nome);
    strcpy(r->telefone,telefone);
    printf("\nInsercao bem sucedida!\n");
    getch();
}

void exibir(Registro *r, int pos){
    system("clear");
    printf("\n========================== LISTA ==========================\n");
    for(int x = 0; x < pos; x++){
        printf("Nome: %s\n", r[x].nome);
        printf("\nTelefone: %s\n", r[x].telefone);
        printf("___________________________________________\n");
    }
    printf("\nPressione qualquer tecla para voltar ao menu...\n");
    getch();
}

void troca(Registro *agenda, Registro *r2){
    Registro temp;
    temp = *agenda;
    *agenda = *r2;
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
    printf("\nOrdenado com sucesso!\n");
    getch();
}

void main(){
    int tam = 10;
    Registro *agenda;
    agenda = (Registro *)malloc(tam * sizeof(Registro));
    if(!agenda){
        exit(1);
    }
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
                inserir(&agenda[pos],nome,telefone);
                pos++;
                if(pos == tam){
                    agenda = (Registro *)realloc(agenda, tam * sizeof(Registro));
                    tam *= 2;
                }
                break;
            case 2:
                exibir(agenda, pos);
                break;
            case 3:
                SelectionSort(agenda, pos);
                break;
            case 4:
                printf("\nQuantidade de registros: %d\n", pos);
                getch();
                break;
            case 5:
                printf("\nTamanho maximo atual da lista: %d\n", tam);
                getch();
                break;
            case 6:
                printf("\nPrograma finalizado!!!\n");
                getch();
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while(op != 6);
}