#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tam;

typedef struct Node node;

struct Node {
    int num;
    struct Node *prox;
};

void getch(){
    printf("\nPressione enter para continuar...\n");
    system("read x");
}

int menu(){
    int opt;
    getch();
    system("clear");
    printf("\n================ MENU ==================\n");
    printf("1 - Digitar uma expressao simples | Ex: 2 1 +\n");
    printf("2 - Sair\n");
    printf("\nEscolha uma opcao: ");
    scanf("%d", &opt);
    return opt;
}

void inicia(node *PILHA){
    PILHA->prox = NULL;
    tam = 0;
}

int estahVazia(node *PILHA){
    if(PILHA->prox == NULL)
        return 1;
    return 0;
}

node *aloca(){
    node *novo = (node *)malloc(sizeof(node));
    if(!novo){
        printf("\nSem memoria disponivel\n");
        exit(1);
    }
    return novo;
}

void exibe(node *PILHA){
    if(estahVazia(PILHA))
        printf("\nPilha vazia!\n");
    else{
        printf("\nPILHA: ");
        node *temp;
        temp = PILHA->prox;
        while(temp != NULL){
            printf("%d ", temp->num);
            temp = temp->prox;
        }
        printf("\n");
    }
}

void libera(node *PILHA){
    if(!estahVazia(PILHA)){
        node *proxNode, *atual;
        atual = PILHA->prox;
        while(atual != NULL){
            proxNode = atual->prox;
            free(atual);
            atual = proxNode;
        }
    }
}

void push(int val, node *PILHA){
    node *novo = aloca();
    novo->num = val;
    novo->prox = NULL;
    if(PILHA->prox == NULL)
        PILHA->prox = novo;
    else{
        node *temp;
        temp = PILHA->prox;
        while(temp->prox != NULL)
            temp = temp->prox;
        temp->prox = novo;
    }
    tam++;
}

node *pop(node *PILHA){
    if(estahVazia(PILHA)){
        printf("\nA pilha ja estah vazia\n");
        return NULL;
    }
    node *ultimo = PILHA->prox;
    node *penultimo = PILHA;
    while(ultimo->prox != NULL){
        penultimo = ultimo;
        ultimo = ultimo->prox;
    }
    penultimo->prox = NULL;
    tam--;
    return ultimo;
}

double calcula(char* expressao, node* PILHA){
    node *a, *b;
    for(int x = 0; x < strlen(expressao); x++){
        if(expressao[x] >= 48 && expressao[x] <= 57){
            int val = expressao[x] - 48;
            push(val, PILHA);
        } else{
            if(expressao[x] == ' ')
                continue;
            a = pop(PILHA);
            b = pop(PILHA);
            if(expressao[x] == '+')
                return a->num + b->num;
            else if(expressao[x] == '-')
                return a->num - b->num;
            else if(expressao[x] == '*')
                return a->num * b->num;
            else if(expressao[x] == '/')
                return a->num / b->num;
            else{
                printf("\nErro: expressao mal formulada!\n");
                exit(1);
            }
        }
    }
}

void opcao(node *PILHA, int opt){
    char* expressao;
    expressao = (char *)malloc(10 * sizeof(char));
    double resultado;
    switch(opt){
        case 1:
            printf("\nInforme a expressao: ");
            setbuf(stdin, NULL);
            scanf("%[^\n]s", expressao);
            resultado = calcula(expressao, PILHA);
            printf("\nResultado = %.2lf\n", resultado);
            break;
        case 2:
            printf("\nPrograma finalizado!\n");
            break;
        default:
            printf("\nOpcao invalida!\n");
    }
}

int main(){
    int opt;
    node *PILHA = (node *)malloc(sizeof(node));
    inicia(PILHA);
    do{
        opt = menu();
        opcao(PILHA, opt);
    }while(opt != 2);
    libera(PILHA);
    return 0;
}