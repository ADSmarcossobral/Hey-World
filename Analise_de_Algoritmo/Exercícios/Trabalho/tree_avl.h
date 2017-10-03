#include <bits/stdc++.h>
using namespace std;

// Namespace da biblioteca
namespace arvore{
    struct aluno_node{
        string matricula, nome, endereco, tel, email;
        double n1, n2, n3, media;
        aluno_node *dir;
        aluno_node *esq;
        // Construtor da estrutura
        aluno_node(string matricula, string nome, string endereco, string tel, string email, double n1, double n2, double n3){
            this->matricula = matricula;
            this->nome = nome;
            this->endereco = endereco;
            this->tel = tel;
            this->email = email;
            this->n1 = n1;
            this->n2 = n2;
            this->n3 = n3;
            this->media = this->getMedia();
            this->dir = nullptr;
            this->esq = nullptr;
        }
        // Exibição da estrutura
        void toString(){
            cout << "====================================================" << endl;
            cout << "Matricula: " << this->matricula << endl;
            cout << "Nome: " << this->nome << endl;
            cout << "Endereco: " << this->endereco << endl;
            cout << "Telefone: " << this->tel << endl;
            cout << "E-mail: " << this->email << endl;
            cout << "Nota 1: " << setprecision(2) << this->n1 << endl;
            cout << "Nota 2: " << setprecision(2) << this->n2 << endl;
            cout << "Nota 3: " << setprecision(2) << this->n3 << endl;
            cout << "Media: " << setprecision(2) << this->media << endl;
            cout << "====================================================" << endl;
        }
        // Calcula a média
        double getMedia(){
            return (this->n1 + this->n2 + this->n3) / 3;
        }
    };
    class aluno{
    private:
        aluno_node *raiz;
        // Percorrendo em pré ordem
        void pre_ordem(aluno_node *node){
            if(node == nullptr)
                return;
            node->toString();
            pre_ordem(node->esq);
            pre_ordem(node->dir);
        }
        // Percorrendo em ordem
        void em_ordem(aluno_node *node){
            if(node == nullptr)
                return;
            em_ordem(node->esq);
            node->toString();
            em_ordem(node->dir);
        }
        // Percorrendo em pós ordem
        void pos_ordem(aluno_node *node){
            if(node == nullptr)
                return;
            pos_ordem(node->esq);
            pos_ordem(node->dir);
            node->toString();
        }
        // Altura da árvore
        int altura(aluno_node *node){
            if(node == nullptr)
                return 0;
            return max(altura(node->esq), altura(node->dir) + 1);
        }
        // Tamanho da árvore
        int tamanho(aluno_node *node){
            if(node == nullptr)
                return 0;
            return tamanho(node->esq) + tamanho(node->dir) + 1;
        }
        /*// Rotaciona para direita
        void rotacao_dir(aluno_node rotacao_root){

        }
        // Rotaciona para esquerda
        void rotacao_esq(aluno_node rotacao_root){

        }*/
    public:
        // Construtor da classe
        aluno(){
            raiz = nullptr;
        }
        // Percorre em pré ordem a partir da raiz
        void pre_ordem(){
            pre_ordem(raiz);
        }
        // Percorre em pós ordem a partir da raiz
        void pos_ordem(){
            pos_ordem(raiz);
        }
        // Percorre em ordem a partir da raiz
        void em_ordem(){
            em_ordem(raiz);
        }
        // Rotaciona para direita
        void rotacao_dir(aluno_node rotacao_root){
            
        }
        // Rotaciona para esquerda
        void rotacao_esq(aluno_node rotacao_root){
            
        }
        // Insere um novo aluno na árvore
        void inserirAluno(string matricula, string nome, string endereco, string email, string tel, double n1, double n2, double n3){
            aluno_node *novo = new aluno_node(matricula, nome, endereco, email, tel, n1, n2, n3);
            if(raiz == nullptr)
                raiz = novo;
            else{
                aluno_node *atual = raiz;
                aluno_node *pai = nullptr;
                while(atual != nullptr || atual != nullptr){
                    pai = atual;
                    if(atual->matricula.compare(matricula) < 0)
                       atual = atual->dir;
                    else if(atual->matricula.compare(matricula) > 0)
                        atual = atual->esq;
                    else{
                        cout << "O aluno já se encontra cadastrado!" << endl;
                        return;
                    }
                }
                if(pai->matricula.compare(matricula) < 0)
                    pai->dir = novo;
                else
                    pai->esq = novo;
            }
        }
        // Busca um aluno na lista a partir da matrícula
        const aluno_node *buscar(string matricula){
            aluno_node *atual = raiz;
            int comp;
            while(atual != nullptr){
                comp = atual->matricula.compare(matricula);
                if(comp == 0)
                    return atual;
                else if(comp == -1)
                    atual = atual->dir;
                else
                    atual = atual->esq;
            }
            return nullptr;
        }
        // Remove um aluno a partir da matrícula
        bool removerAluno(string matricula) {
            aluno_node *atual = raiz;
            aluno_node *paiAtual = nullptr;
            while(atual != nullptr){
                if(atual->matricula.compare(matricula) > 0){
                    paiAtual = atual;
                    atual = atual->esq; 
                }else if(atual->matricula.compare(matricula) < 0){
                    paiAtual = atual;
                    atual = atual->dir;
                }else{
                    if(atual->esq == nullptr && atual->dir == nullptr){
                        if(paiAtual->dir->matricula.compare(matricula) == 0)
                            paiAtual->dir = nullptr;
                        else
                            paiAtual->esq = nullptr;
                        delete(atual);
                    }else if(atual->esq == nullptr){
                        if(paiAtual->dir->matricula.compare(matricula) == 0)
                            paiAtual->dir = atual->dir;
                        else
                            paiAtual->esq = atual->dir;
                        delete(atual);
                    } else if(atual->dir == nullptr){
                        if(paiAtual->dir->matricula.compare(matricula) == 0)
                            paiAtual->dir = atual->esq;
                        else
                            paiAtual->esq = atual->esq;
                        delete(atual);
                    } else{
                        aluno_node *filho = atual->esq;
                        aluno_node *paiFilho = atual;
                        while(filho->dir != nullptr){
                            filho = filho->dir;
                            paiFilho = filho;
                        }     
                        atual->matricula = filho->matricula;
                        if(filho->esq != nullptr){
                            paiFilho->dir = filho->esq;
                        } else{
                            paiFilho->dir = nullptr;
                        }
                        delete(filho);
                    }
                    return true;
                }
            }
            return false;
        }  
        bool vazia() {
            if (raiz == nullptr) {
                    return true;
            } else {
                    return false;
            }
        } 
    };

}