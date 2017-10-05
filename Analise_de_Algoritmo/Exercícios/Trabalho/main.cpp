#include "./tree_avl.h"
#include <bits/stdc++.h>

using namespace std;

/*void limpaTela(){
        cout << "Pressione enter para continuar...";
        system("read x");
        system("clear");
}*/

int menu(){
        printf("================ MENU =================\n");
        printf("1 -> Inserir um aluno\n");
        printf("2 -> Pre-ordem\n");
        printf("3 -> Pos-ordem\n");
        printf("4 -> Em ordem\n");
        printf("5 -> Restaurar arvore\n");
        printf("6 -> Sair\n");
        printf("=======================================\n");
        int op;
        printf("\nEscolha uma opcao: ");
        cin >> op;
        return op;
}

int opcao(arvore::aluno *turma, int op){
        if(op == 1){
            string matricula, nome, email, endereco, tel;
            double n1, n2, n3;
            cout << "Matricula: ";
            cin >> matricula;
            cin.clear();
            cout << "Nome: ";
            cin >> nome;
            cin.clear();
            cout << "E-mail: ";
            cin >> email;
            cin.clear();
            cout << "Endereco: ";
            cin >> endereco;
            cin.clear();
            cout << "Telefone: ";
            cin >> tel;
            cin.clear();
            cout << "Nota 1: ";
            cin >> n1;
            cin.clear();
            cout << "Nota 2: ";
            cin >> n2;
            cin.clear();
            cout << "Nota 3: ";
            cin >> n3;
            turma->inserirAluno(matricula, nome, endereco, email, tel, n1, n2, n3);
        } else if(op == 2){
            cout << "============================= PRE-ORDEM =============================";
            turma->pre_ordem();
        } else if(op == 3){
            cout << "============================= POS-ORDEM =============================";
            turma->pos_ordem();
        } else if(op == 4){
            cout << "============================= EM ORDEM =============================";
            turma->em_ordem();
        }else if(op == 5){
            
        }else if(op == 6){
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