#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int TAM = 1;

void pauseClear(){
    printf("\nPressione enter para continuar...\n");
    system("read x");
    system("clear");
}

int menu(){
    pauseClear();
    printf("============================= MENU =============================\n");
    printf("1 - Calcular\n");
    printf("2 - Exibir\n");
    printf("3 - Sair\n");
    printf("\nEscolha uma opcao: ");
    int op;
    scanf("%d", &op);
    return op;
}

void troca(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}  

void push(int *vetor, int val){
    vetor = (int *) realloc(vetor, TAM * sizeof(int));
    *(vetor+TAM-1) = val; // Mesmo que vetor[TAM-1] (Menos 1 porque o tamanho parte de 1)
    TAM++;
}

int pop(int *vetor){
    if(TAM == 1){
        return 0;
    }
    int val = vetor[TAM-1];
    vetor = (int *) realloc(vetor, TAM - 2 * sizeof(int));
    TAM--;
    return val;
}

void selectAll(int *vetor){
    if(TAM == 1){
        printf("\nPilha Vazia!\n");
        return;
    }
    printf("Pilha: ");
    for(int x = 0; x < TAM - 1; x++)
        printf("%d ", *(vetor+x));
    printf("\n");
}

int opcao(int *vetor, int op){
    if(op == 1){
        char ent[10];
        int valor;
        int a, b;
        printf("\nInforme a expressao: ");
        scanf(" %s", ent);
        for(int x = 0; x < strlen(ent); x++){
            printf("Aqui: %c", ent[x]);
            if(ent[x] == '+'){
                a = pop(vetor);
                b = pop(vetor);
                push(vetor, a+b);
            } else if(ent[x] == '-'){
                a = pop(vetor);
                b = pop(vetor);
                push(vetor, a-b);
            }else if(ent[x] == '*'){
                a = pop(vetor);
                b = pop(vetor);
                push(vetor, a*b);
            } else if(ent[x] == '/'){
                a = pop(vetor);
                b = pop(vetor);
                push(vetor, a/b);
            }else if(ent[x] == ' ')
                continue;
            else{
                char *tmp = (char *) malloc(sizeof(char));
                for(int y = x; y < strlen(ent); y++){
                    tmp = (char *) realloc(tmp, y-x+1 * sizeof(char));
                    if(ent[y] != ' ')
                        tmp[y-x] = ent[y];
                    else
                        break;
                    x++;
                }
                push(vetor, atoi(tmp));
            }
        }
    }else if(op == 2)
        selectAll(vetor);
    else if(op == 3)
        return 0;
    else
        printf("\nOpcao invalida!!!\n");
    return 1;
}

int main(){
    int *vetor;
    vetor = (int *) malloc(TAM * sizeof(int));
    while(opcao(vetor, menu()));
    free(vetor);
}