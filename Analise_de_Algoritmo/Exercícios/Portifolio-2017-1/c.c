#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAM_REG 100
#define TAM_NOME 50
#define TAM_MAT 11

struct registro{
    char nome[TAM_NOME];
    char matricula[TAM_MAT];
    double nota;
    struct registro *prox;
};

typedef struct registro Registro;

void limpa(){
    printf("\nPressione enter para continuar\n");
    system("read x");
    system("clear");
}

void menu(){
    limpa();
    printf("================ MENU =================\n");
    printf("1 -> Inserir aluno na lista\n");
    printf("2 -> Exibir lista de alunos\n");
    printf("3 -> Ordenar lista por nome\n");
    printf("4 -> Ordenar lista por matricula\n");
    printf("5 -> Buscar aluno por matricula\n");
    printf("6 -> Remover aluno da lista\n");
    printf("7 -> Calcular e mostrar media da turma\n");
    printf("8 -> Sair\n");
    printf("=======================================\n");
}

void checaMem(Registro *reg){
    if(!reg){
        printf("\nSem memoria disponivel!\n");
        exit(1);
    }
}

void inserir(Registro *LISTA, char *nome, char *matricula, double nota){
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
    strcpy(novo->matricula, matricula);
    novo->nota = nota;
}

void toString(Registro *tmp){
        printf("Nome: %s\n", tmp->nome);
        printf("\nMatricula: %s\n", tmp->matricula);
        printf("\nNota: %.2lf\n", tmp->nota);
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

Registro *remover(char *matricula, Registro *LISTA){
    Registro *atual, *ant;
    atual = LISTA->prox;
    ant = LISTA;
    while(atual != NULL){
        if(strcmp(matricula, atual->matricula) == 0){
            ant->prox = atual->prox;
            return atual;
        }
        ant = atual;
        atual = atual->prox;
    }
    return NULL;
}

Registro *buscarPorMat(char *matricula, Registro *LISTA){
    if(LISTA->prox == NULL)
        return NULL;
    else{
        if(strcmp(matricula, LISTA->prox->matricula) == 0)
            return LISTA->prox;
        else
            return buscarPorMat(matricula, LISTA->prox);
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

double media(Registro *LISTA){
    double media = 0;
    int cont = 0;
    if(LISTA->prox == NULL)
        printf("\nNao existe registros na lista!\n");
    else{
        Registro *atual = LISTA->prox;
        while(atual != NULL){
            media += atual->nota;
            cont++;
            atual = atual->prox;
        }
        return media / cont;
    }
}

void SelectionSortNome(Registro *LISTA){
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

void SelectionSortMatricula(Registro *LISTA){
    if(LISTA->prox == NULL)
        printf("\nNao existe registros na lista!\n");
    else{
        Registro *menor;
        Registro *atualX = LISTA->prox;
        while(atualX->prox != NULL){
            menor = atualX;
            Registro *atualY = atualX->prox;
            while(atualY != NULL){
                if(strcmp(atualY->matricula, menor->matricula) < 0){
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
    Registro *aux;
    int op, pos = 0;
    char nome[TAM_NOME], matricula[TAM_MAT];
    double nota;
    do{
        menu();
        printf("\nEscolha uma opcao: ");
        scanf("%d", &op);
        switch(op){
            case 1:
                printf("\nInforme o nome: ");
                scanf("%s", nome);
                printf("\nInforme a matricula: ");
                scanf("%s", matricula);
                printf("\nInforme a nota: ");
                scanf("%lf", &nota);
                inserir(LISTA, nome, matricula, nota);
                pos++;
                break;
            case 2:
                exibir(LISTA);
                break;
            case 3:
                SelectionSortNome(LISTA);
                exibir(LISTA);
                break;
            case 4:
                SelectionSortMatricula(LISTA);
                exibir(LISTA);
                break;
            case 5:
                printf("\nInforme a matricula do aluno a ser procurado: ");
                scanf(" %s", matricula);
                aux = buscarPorMat(matricula, LISTA);
                toString(aux);
            case 6:
                printf("\nInforme a matricula do aluno a ser excluido: ");
                scanf(" %s", matricula);
                free(remover(matricula, LISTA));
            case 7:
                printf("\n____________________________\n");
                printf("Media da turma: %.2lf", media(LISTA));
                printf("\n____________________________\n");
            case 8:
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while(op != 8);
    apagarLista(LISTA);
}