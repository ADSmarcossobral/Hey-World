/* Código com tipos de acessos hierárquicos em árvores binárias e outras funções */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TAM_REG 100
#define TAM_NOME 50
#define TAM_MAT 11

struct node{
    struct node *esq;
    char nome[TAM_NOME];
    char matricula[TAM_MAT];
    double nota;
    struct node *dir;
};

typedef struct node Node;

void limpa(){
    printf("\nPressione qualquer tecla para continuar\n");
    system("read x");
    system("clear");
}

int menu(){
    limpa();
    printf("================ MENU =================\n");
    printf("1 -> Inserir aluno na lista\n");
    printf("2 -> Listar alunos\n");
    printf("3 -> Exibir altura da árvore\n");
    printf("4 -> Buscar aluno por matricula\n");
    printf("5 -> Remover aluno da lista\n");
    printf("6 -> Sair\n");
    printf("=======================================\n");
    int op;
    printf("\nEscolha uma opcao: ");
    scanf("%d", &op);
    return op;
}

Node *newNode(){
    return (Node *) malloc(sizeof(Node));
}

void toString(Node *tmp){
    printf("\n_________________________________________\n");
    printf("Nome: %s\n", tmp->nome);
    printf("\nMatricula: %s\n", tmp->matricula);
    printf("\nNota: %.2lf\n", tmp->nota);
    printf("___________________________________________\n");
}

void emOrdem(Node *node){
    if(node == NULL){
        return;
    }
    emOrdem(node->esq);
    toString(node);
    emOrdem(node->dir);
}

int max(int a, int b){
    if(a > b)
        return a;
    return b;
}

void checaMem(Node *no){
    if(!no){
        printf("\nSem memoria disponivel!\n");
        exit(1);
    }
}

int tamanho(Node *node){
    if(node == NULL)
        return 0;
    return tamanho(node->esq) + tamanho(node->dir) + 1;
}

int altura(Node *node){
    if(node == NULL)
        return -1;
    return max(altura(node->esq), altura(node->dir) + 1);
}

Node *buscar(Node *r, char* busca){
    int comp = strcmp(busca, r->matricula);
    if(r == NULL || comp == 0)
        return r;
    else if(comp < 0)
        return buscar(r->esq, busca);
    else
        return buscar(r->dir, busca);
}

void inserir(Node *raiz, Node *novo){
    if(raiz == NULL){
        raiz = novo;
        return;
    }else{
        Node *atual = raiz;
        Node *pai = NULL;
        while(atual != NULL || atual != NULL){
            int comp = strcmp(atual->matricula, novo->matricula);
            pai = atual;
            if(comp < 0)
               atual = atual->dir;
            else if(comp > 0)
                atual = atual->esq;
            else{
                printf("O aluno já se encontra cadastrado!\n");
                return;
            }
        }
        if(strcmp(pai->matricula, novo->matricula) < 0)
            pai->dir = novo;
        else
            pai->esq = novo;
    }
}

Node *remover(Node *r, char* busca){
    if(r == NULL)
        return NULL;
    int comp = strcmp(busca, r->matricula);
    if(comp == 0){
        if(r->esq == NULL && r->dir == NULL){
            free(r);
            return r;
        } else if(r->esq == NULL){
            Node *t = r;
            r = r->dir;
            free(t);
        } else if(r->dir == NULL){
            Node *t = r;
            r = r->esq;
            free(t);
        } else{
            Node *pai = r;
            Node *f = r->esq;
            while(f->dir != NULL){
                pai = f;
                f = f->dir;
            }
            strcpy(r->matricula, f->matricula);
            strcpy(r->nome, f->nome);
            r->nota = f->nota;
            strcpy(f->matricula, r->matricula);
            r->esq = remover(r->esq, busca);
        }
        return r;
    } else if(comp > 0)
        r->esq = remover(r->esq, busca);
    else
        r->dir = remover(r->dir, busca);
}

int checaRaiz(Node *raiz){
    if(raiz == NULL){
        printf("\nArvore vazia!\n");
        return 1;
    }
    return 0;
}

Node *liberarArv(Node *raiz){
    if(raiz != NULL){
        liberarArv(raiz->esq);
        liberarArv(raiz->dir);
        free(raiz);
    }
    return NULL;
}

void troca(Node *a, Node *b){
    Node aux = *a;
    *a = *b;
    *b = aux;
}

void copiar(Node *copiando, Node *copiado){
    strcpy(copiando->matricula, copiado->matricula);
    strcpy(copiando->nome, copiado->nome);
    copiando->nota = copiado->nota;
}

void printVetor(Node *vetor, int TAM){
    for(int x = 0; x < TAM; x++)
        toString(&vetor[x]);
}

void toVetor(Node *vetor, int *indice, Node *raiz){
    if(raiz == NULL)
        return;
    toVetor(vetor, indice, raiz->esq);
    toVetor(vetor, indice, raiz->dir);
    vetor[*indice] = *raiz;
    *indice = *indice + 1;
}

int particiona(Node *vetor, int ini, int fim){
    int i = ini + 1, f = fim;
    Node *pivot = (Node *) malloc(sizeof(Node));
    copiar(pivot, &vetor[ini]);
    while(i <= f){
        if(strcmp(vetor[i].matricula, pivot->matricula) <= 0)
            i++;
        else if(strcmp(pivot->matricula, vetor[f].matricula) < 0)
            f--;
        else{
            troca(&vetor[i], &vetor[f]);
            i++;
            f--;
        }
    }
    copiar(&vetor[ini], &vetor[f]);
    copiar(&vetor[f], pivot);
    return f;
}

void quickSort(Node *vetor, int ini, int fim){
    if(ini >= fim)
        return;
    int pivot = particiona(vetor,ini,fim);
    quickSort(vetor, ini, pivot - 1);
    quickSort(vetor, pivot + 1, fim);
}

void listarOrdenado(Node *raiz){
    int TAM = tamanho(raiz), indice = 0;
    printf("Tamanho = %d", TAM);
    system("read x");
    Node *vetor = (Node *) malloc(TAM * sizeof(Node));
    toVetor(vetor, &indice, raiz);
    quickSort(vetor, 0, TAM - 1);
    printVetor(vetor, TAM);
}

int opcao(int op, Node *raiz){
    Node *aux;
    if(op == 1){
        char nome[TAM_NOME], matricula[TAM_MAT];
        double nota;
        setbuf(stdin, NULL);
        printf("\nInforme o nome: ");
        fgets(nome, TAM_NOME, stdin);
        setbuf(stdin, NULL);
        printf("\nInforme a matricula: ");
        scanf(" %s", matricula);
        setbuf(stdin, NULL);
        printf("\nInforme a nota: ");
        scanf("%lf", &nota);
        setbuf(stdin, NULL);
        Node *novo = newNode();
        checaMem(novo);
        strcpy(novo->matricula, matricula);
        strcpy(novo->nome, nome);
        novo->nota = nota;
        novo->esq = NULL;
        novo->dir = NULL;
        inserir(raiz, novo);
    } else if(op == 2){
        printf("\n================= ALUNOS ================\n");
        listarOrdenado(raiz);
    } else if(op == 3){
        printf("\n_________________________________________\n");
        printf("Altura = %d", altura(raiz));        
        printf("\n_________________________________________\n");
    } else if(op == 4){
        char matricula[TAM_MAT];
        printf("Informe a matricula do aluno: ");
        scanf(" %s", matricula);
        aux = buscar(raiz, matricula);
        if(aux == NULL)
            printf("\nAluno nao encontrado!\n");
        else
            toString(aux);
    }else if(op == 5){
        char matricula[TAM_MAT];
        printf("Informe a matricula do aluno: ");
        scanf(" %s", matricula);
        aux = remover(raiz, matricula);
        if(aux == NULL)
            printf("\nAluno nao encontrado!\n");
        else
            free(aux);
    }else if(op == 6){
        printf("\nPrograma finalizado!!!\n");
        return 1;
    } else if(op == 7)
        emOrdem(raiz);
    return 0;
}

int main(){
    Node *raiz;
    raiz = NULL;
    while(opcao(menu(), raiz) != 1);
    liberarArv(raiz);
    return 0;
}