/*#ifdef WINDOW_SYSTEM
	#include <bits/stdc++.h>
#endif
#ifdef LINUX_SYSTEM
	#include <bits\stdc++.>
#endif*/

#include <bits/stdc++.h>
#define nullptr NULL
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
        // Retorna true se a matrícula de um nó for igual à do outro
        bool equalsNode(aluno_node *node, aluno_node *outro_node){
            return node->matricula.compare(outro_node->matricula) == 0;
        }
        // Altura da árvore
        int altura(aluno_node *node){
            if(node == nullptr)
                return -1;
            return max(altura(node->esq), altura(node->dir)) + 1;
        }
        // Rotaciona para direita
        void rotacao_dir(aluno_node *node){
            aluno_node *nova_raiz = node->esq;
            aluno_node *sub = nova_raiz->dir;
            node->esq = sub;
            nova_raiz->dir = node;
            if(paiNode(node) == nullptr)
                raiz = nova_raiz;
            else if(equalsNode(node, paiNode(node)->esq))
                paiNode(node)->esq = nova_raiz;
            else
                paiNode(node)->dir = nova_raiz;
        }
        // Rotaciona para esquerda
        void rotacao_esq(aluno_node *node){
            aluno_node *nova_raiz = node->dir;
            aluno_node *sub = nova_raiz->esq;
            node->dir = sub;
            nova_raiz->esq = node;
            if(paiNode(node) == nullptr)
                raiz = nova_raiz;
            else if(equalsNode(node, paiNode(node)->esq))
                paiNode(node)->esq = nova_raiz;
            else
                paiNode(node)->dir = nova_raiz;
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
        // Retorna o pai do nó
        aluno_node* paiNode(aluno_node *node){
            if(equalsNode(node, raiz))
                return nullptr;
            aluno_node *pai = nullptr;
            aluno_node *atual = raiz;
            while(!equalsNode(atual, node)){
                pai = atual;
                if(node->matricula.compare(atual->matricula) > 0)
                    atual = atual->dir;
                else
                    atual = atual->esq;
            }
            return pai;
        }
        // Recalcula os fatores e balanceia os ancestrais do nó
        void balancear(aluno_node *atual){
            while(atual != nullptr){
                int hd = altura(atual->dir);
                int he = altura(atual->esq);
                atual->fb = hd - he;
                if(atual->fb == -2){
                    if(atual->esq->fb == 1){
                        rotacao_esq(atual->esq);
                    }
                    rotacao_dir(atual);
                }else if(atual->fb == 2){
                    if(atual->dir->fb == -1){
                        rotacao_dir(atual->dir);
                    }
                    rotacao_esq(atual);
                }
                atual = paiNode(atual);
            }
        }
        // Insere aluno
        bool inserir(aluno_node *node, aluno_node *novo){
            aluno_node *atual = raiz;
            aluno_node *pai = nullptr;
            
            while(atual != nullptr){
                pai = atual;
                if(novo->matricula.compare(atual->matricula) > 0)
                    atual = atual->dir;
                else if(novo->matricula.compare(atual->matricula) < 0)
                    atual = atual->esq;
                else
                    return false;
            }
            atual = novo;
            if(pai == nullptr)
                raiz = atual;
            else if(atual->matricula.compare(pai->matricula) > 0)
                pai->dir = atual;
            else if(atual->matricula.compare(pai->matricula) < 0)
                pai->esq = atual;

            balancear(atual);
            return true;
        }
        // Remove um aluno a partir da matrícula
        bool remover(string matricula) {
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
                            if(paiAtual->dir != nullptr){
                                if(paiAtual->dir->matricula.compare(matricula) == 0)
                                    paiAtual->dir = nullptr;
                            }else{
                                paiAtual->esq = nullptr;
                            }
                            balancear(paiAtual);
                            delete(atual);
                        }else{
                            delete(atual);
                            raiz = nullptr;
                        }
                    }else if(atual->esq == nullptr){
                        if(paiAtual != nullptr){
                            if(paiAtual->dir != nullptr){
                                if(paiAtual->dir->matricula.compare(matricula) == 0)
                                    paiAtual->dir = atual->dir;
                            }else{
                                paiAtual->esq = atual->dir;
                            }
                        }else{
                            raiz = atual->dir;
                        }
                        balancear(paiAtual);
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
                        balancear(paiAtual);
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
                        if(equalsNode(raiz, filho))
                            raiz = atual;
                        else
                            paiAtual->dir = atual;
                        balancear(atual);
                        delete(filho);
                    }
                    return true;
                }
            }
            return false;
        }
    public:
        aluno_node *raiz;
        // Construtor da classe
        aluno(){
            raiz = NULL;
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
        int altura(){
            return altura(raiz);
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
        // Insere um novo aluno na árvore
        bool inserirAluno(string matricula, string nome, string endereco, string email, string tel, double n1, double n2, double n3){
            aluno_node *novo = new aluno_node(matricula, nome, endereco, email, tel, n1, n2, n3);
            return inserir(raiz, novo);
        }
        // Busca um aluno na lista a partir da matrícula
        aluno_node *buscar(string matricula){
            aluno_node *atual = raiz;
            int comp;
            while(atual != nullptr){
                comp = atual->matricula.compare(matricula);
                if(comp == 0)
                    return atual;
                else if(comp < 0)
                    atual = atual->dir;
                else
                    atual = atual->esq;
            }
            return nullptr;
        }
        // Remove um aluno a partir da matrícula
        bool removerAluno(string matricula) {
            return remover(matricula);
        }
        // Retorna verdadeiro se a árvore estiver vazia
        bool isVazia() {
            if (raiz == nullptr) {
                    return true;
            } else {
                    return false;
            }
        }
        // Preenche um vetor com todos os nós da árvore, percorrendo em pós-ordem
        void toVetor(aluno_node *vetor, int *indice, aluno_node *node){
            if(node == nullptr)
                return;
            toVetor(vetor, indice, node->esq);
            toVetor(vetor, indice, node->dir);
            vetor[*indice] = *node;
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
