#include "./tree_avl.h"
#include <bits/stdc++.h>

int main(){
    arvore::aluno teste;
    // Inserção
    teste.inserirAluno("2016116007", "Marcos Sobral", "Travessa Ligel",
    "marcossobral94@gmail.com", "(71) 3451-4124", 8.0, 9.5, 9.5);
    teste.inserirAluno("2016116008", "Caio Jordao", "Travessa Java",
    "caio@gmail.com", "(71) 3311-4124", 8.0, 9, 9);
    teste.inserirAluno("2016116006", "Danilo Ferre", "Travessa Ligel",
    "dan@gmail.com", "(71) 3412-4124", 6.0, 9.5, 6.5);
    // Pré-ordem
    teste.pre_ordem();
    // Consulta
    teste.buscar("2016116007")->toString();
    // Media Turma
    cout << "Media turma: " << teste.mediaTurma() << endl;
    // Ordena
    teste.ordena();
    // Deleta
    teste.removerAluno("2016116007");
    // Pré-ordem
    teste.pre_ordem();
    // Limpa árvore
    teste.limpar();
    // Pré-ordem
   teste.pre_ordem();

}