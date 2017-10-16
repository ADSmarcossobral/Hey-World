#include "./tree_avl.h"
#include <bits/stdc++.h>

#define TAM_MAT 11
#define TAM_TEL 16
#define TAM_NOME 75
#define TAM_EMAIL 50
#define TAM_END 75

using namespace std;

void removeEnter(char *str){
    str[strlen(str) - 1] = '\0';
}

void limpaTela(){
    system("read x");
    cout << "Pressione enter para continuar...";
    system("clear");
}

int menu(){
    printf("================ MENU =================\n");
    printf("1 -> Inserir um aluno\n");
    printf("2 -> Exibir em pre-ordem\n");
    printf("3 -> Exibir em pos-ordem\n");
    printf("4 -> Exibir em ordem\n");
    printf("5 -> Ordenar com QuickSort\n");
    printf("6 -> Media da turma\n");
    printf("7 -> Buscar um aluno\n");
    printf("8 -> Deletar um aluno\n");
    printf("9 -> Limpar arvore\n");
    printf("10 -> Sair\n");
    printf("=======================================\n");
    int op;
    printf("\nEscolha uma opcao: ");
    cin >> op;
    return op;
}

int opcao(arvore::aluno *turma, int op){
    if(op == 1){
        char matricula[TAM_MAT], nome[TAM_NOME], email[TAM_EMAIL], endereco[TAM_END], tel[TAM_TEL];
        double n1, n2, n3;
        cout << "Matricula: ";
        cin >> matricula;
        cout << "Nome: ";
        cin.ignore();
        fgets(nome, TAM_NOME, stdin);
        removeEnter(nome);
        cout << "E-mail: ";
        fflush(stdin);
        cin >> email;
        cout << "Endereco: ";
        cin.ignore();
        fgets(endereco, TAM_END, stdin);
        removeEnter(endereco);
        cout << "Telefone -> (XX) XXXX-XXXX: ";
        fflush(stdin);
        fgets(tel, TAM_TEL, stdin);
        removeEnter(tel);
        cout << "Nota 1: ";
        cin >> n1;
        cout << "Nota 2: ";
        cin >> n2;
        cout << "Nota 3: ";
        cin >> n3;
        turma->inserirAluno((string) matricula,(string) nome,(string)(string) endereco,(string) email,(string) tel, n1, n2, n3);
    } else if(op == 2){
        cout << "============================= PRE-ORDEM =============================" << endl;
        turma->pre_ordem();
    } else if(op == 3){
        cout << "============================= POS-ORDEM =============================" << endl;
        turma->pos_ordem();
    } else if(op == 4){
        cout << "============================= EM ORDEM =============================" << endl;
        turma->em_ordem();
    }else if(op == 5){
        cout << "============================= ORDENADO =============================" << endl;
        turma->ordena();
    }else if(op == 6){
        cout << "Media da turma: "<< turma->mediaTurma() << endl;
    }else if(op == 7){
        string matricula;
        cout << "Informe a matricula: ";
        cin >> matricula;
        arvore::aluno_node *tmp = turma->buscar(matricula);
        if(!tmp)
            cout << "Aluno nao encontrado!" << endl;
        else
            tmp->toString();
    }else if(op == 8){
        string matricula;
        cout << "Informe a matricula: ";
        cin >> matricula;
        bool wasRemoved = turma->removerAluno(matricula);
        if(wasRemoved)
            cout << "Aluno removido com sucesso!" << endl;
        else
            cout << "Aluno nao encontrado na arvore!" << endl;
    }else if(op == 9){
        turma->limpar();
        cout << "Todos os registros foram apagados." << endl;
    }else if(op == 10){
        printf("\nPrograma finalizado!!!\n");
        return 1;
    }
    return 0;
}

int main() {
    arvore::aluno turma;
    while(opcao(&turma, menu()) != 1);
    return 0;
}