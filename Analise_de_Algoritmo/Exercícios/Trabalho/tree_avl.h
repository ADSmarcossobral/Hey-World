#include <bits/stdc++.h>
using namespace std;

// Namespace da biblioteca
namespace arvore{
    struct aluno_node{
        string matricula, nome, endereco, tel, email;
        int fb; // Fator de balanço
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
            cout << "____________________________________________________" << endl;
            cout << "Matricula: " << this->matricula << endl;
            cout << "Nome: " << this->nome << endl;
            cout << "Endereco: " << this->endereco << endl;
            cout << "Telefone: " << this->tel << endl;
            cout << "E-mail: " << this->email << endl;
            cout << "Nota 1: " << setprecision(2) << this->n1 << endl;
            cout << "Nota 2: " << setprecision(2) << this->n2 << endl;
            cout << "Nota 3: " << setprecision(2) << this->n3 << endl;
            cout << "Media: " << setprecision(2) << this->media << endl;
            cout << "____________________________________________________" << endl;
        }
        // Calcula a média
        double getMedia(){
            return (this->n1 + this->n2 + this->n3) / 3;
        }
    };
    class aluno{
    private:
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
        // Exibe vetor
        void printVetor(aluno_node *vetor, int TAM){
            for(int x = 0; x < TAM; x++)
                vetor[x].toString();
        }
        // Exclue todos os registros da árvore
        void limpar(aluno_node *node){
            if(node != nullptr){
                limpar(node->esq);
                limpar(node->dir);
                delete(node);
            }
        }
        // Tamanho da árvore
        int tamanho(aluno_node *node){
            if(node == nullptr)
                return 0;
            return tamanho(node->esq) + tamanho(node->dir) + 1;
        }
    public:
        aluno_node *raiz;
        // Construtor da classe
        aluno(){
            raiz = nullptr;
        }
        // Percorrendo em pré ordem
        void pre_ordem(){
            pre_ordem(raiz);
        }
        // Percorrendo em ordem
        void em_ordem(){
            em_ordem(raiz);
        }
        // Percorrendo em pós ordem
        void pos_ordem(){
            pos_ordem(raiz);
        }
        // Exclue todos os registros da árvore
        void limpar(){
            limpar(raiz);
            raiz = nullptr;
        }
        // Altura da árvore
        int altura(aluno_node *node){
            if(node == nullptr)
                return -1;
            return max(altura(node->esq), altura(node->dir) + 1);
        }
        // Tamanho da árvore
        int tamanho(){
            return tamanho(raiz);
        }
        // Retorna true se a árvore for avl
        bool isAVL(aluno_node *node){
            int hd = altura(node->dir), he = altura(node->esq);
            return ((hd - he) < 2) && ((hd - he) > -2);
        }
        // Rotaciona para direita
        void rotacao_dir(aluno_node *node){
            aluno_node *a, *tmp;
            a = node->esq;
            tmp = a->dir;
            a->dir = node;
            node->esq = tmp;
            node = a;
        }
        // Rotaciona para esquerda
        void rotacao_esq(aluno_node *node){
            aluno_node *a, *tmp;
            a = node->dir;
            tmp = a->esq;
            a->esq = node;
            node->dir = tmp;
            node = a;
        }
        // Balanceia a árvore
        void balancear(aluno_node *node){
            int h = altura(node);
            if(h <= 1 || h >= -1){
                if(h < 0){

                } else{

                }
            }
        }
        // Copia os dados de um nó para outro
        void copiar(aluno_node *copiando, aluno_node *copiado){
            copiando->matricula = copiado->matricula;
            copiando->nome = copiado->nome;
            copiando->tel = copiado->tel;
            copiando->endereco = copiado->endereco;
            copiando->email = copiado->email;
            copiando->n1 = copiado->n1;
            copiando->n2 = copiado->n2;
            copiando->n3 = copiado->n3;
            copiando->media = copiado->media;
        }
        // Insere um novo aluno na árvore
        void inserirAluno(string matricula, string nome, string endereco, string email, string tel, double n1, double n2, double n3){
            aluno_node *novo = new aluno_node(matricula, nome, endereco, email, tel, n1, n2, n3);
            if(raiz == nullptr){
                raiz = novo;
                return;
            }else{
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
            if(!isAVL(raiz)){
                balancear(raiz);
            }
        }
        // Busca um aluno na lista a partir da matrícula
        aluno_node *buscar(string matricula){
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
                        if(paiAtual != nullptr){
                            if(paiAtual->dir->matricula.compare(matricula) == 0)
                                paiAtual->dir = nullptr;
                            else
                                paiAtual->esq = nullptr;
                        }
                        delete(atual);
                    }else if(atual->esq == nullptr){
                        if(paiAtual != nullptr){
                            if(paiAtual->dir->matricula.compare(matricula) == 0)
                                paiAtual->dir = atual->dir;
                            else
                                paiAtual->esq = atual->dir;
                        }else{
                            raiz = atual->dir;
                        }
                        delete(atual);
                    } else if(atual->dir == nullptr){
                        if(paiAtual != nullptr){
                            if(paiAtual->dir->matricula.compare(matricula) == 0)
                                paiAtual->dir = atual->esq;
                            else
                                paiAtual->esq = atual->esq;
                        }else{
                            raiz = atual->esq;
                        }
                        delete(atual);
                    } else{
                        aluno_node *filho = atual->esq;
                        aluno_node *paiFilho = atual;
                        while(filho->dir != nullptr){
                            paiFilho = filho;
                            filho = filho->dir;
                        }     
                        copiar(atual, filho);
                        atual->esq = nullptr;
                        if(raiz->matricula.compare(filho->matricula) == 0)
                            raiz = atual;
                        else
                            paiAtual->dir = atual;
                        delete(filho);
                    }
                    // balancear(raiz);
                    return true;
                }
            }
            return false;
        }
        // Retorna verdadeiro se a árvore estiver vazia
        bool vazia() {
            if (raiz == nullptr) {
                    return true;
            } else {
                    return false;
            }
        }
        // Preenche um vetor com todos os nós da árvore, percorrendo em pós-ordem
        void toVetor(aluno_node *vetor, int *indice, aluno_node *raiz){
            if(raiz == nullptr)
                return;
            toVetor(vetor, indice, raiz->esq);
            toVetor(vetor, indice, raiz->dir);
            vetor[*indice] = *raiz;
            *indice = *indice + 1;
        }
        // Retorna a média da média de todos os alunos da árvore
        double mediaTurma(){
            double media = 0;
            int TAM = tamanho(), indice = 0;
            aluno_node *vetor = (aluno_node *) malloc(TAM * sizeof(aluno_node));
            toVetor(vetor, &indice, raiz);
            for(int x = 0; x < TAM; x++)
                media += vetor[x].getMedia();
            return media / TAM;
        }
        // Troca a posição de dois nós em um vetor
        void troca(aluno_node *a, aluno_node *b){
            aluno_node aux = *a;
            *a = *b;
            *b = aux;
        }
        // Particiona um vetor (Quick Sort)
        int particiona(aluno_node *vetor, int ini, int fim){
            int i = ini + 1, f = fim;
            aluno_node *pivot = (aluno_node *) malloc(sizeof(aluno_node));
            copiar(pivot, &vetor[ini]);
            while(i <= f){
                if(vetor[i].matricula.compare(pivot->matricula) <= 0)
                    i++;
                else if(pivot->matricula.compare(vetor[f].matricula) < 0)
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
        // Ordena um vetor de aluno_node por Quick Sort
        void quickSort(aluno_node *vetor, int ini, int fim){
            if(ini >= fim)
                return;
            int pivot = particiona(vetor,ini,fim);
            quickSort(vetor, ini, pivot - 1);
            quickSort(vetor, pivot + 1, fim);
        }
        // Ordenador
        void ordena(){
            int TAM = tamanho(raiz), indice = 0;
            aluno_node *vetor = (aluno_node *) malloc(TAM * sizeof(aluno_node));
            toVetor(vetor, &indice, raiz);
            quickSort(vetor, 0, TAM - 1);
            printVetor(vetor, TAM);
        }
    };

}