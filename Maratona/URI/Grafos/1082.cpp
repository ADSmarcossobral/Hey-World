#include <bits/stdc++.h>

using namespace std;

int tamStr = 1;

struct Arv{
    char val;
    Arv *dir;
    Arv *esq;
};

void selectionSort(string vetor, int tam){
    char menor;
    for(int x = 0; x < tam - 1; x++){
        menor = x;
        for(int y = x + 1; y < tam; y++){
            if(vetor[y] < vetor[menor])
                menor = y;
        }
        if(menor != x){
            char tmp;
            tmp = vetor[x];
            vetor[x] = vetor[menor];
            vetor[menor] = tmp;
        }
    }
}

Arv *insereGrafo(char val, Arv *root){
    Arv *novo = (Arv *) malloc(sizeof(Arv));
    novo->dir = NULL;
    novo->esq = NULL;
    novo->val = val;
    if(root == NULL)
        return novo;
    root->dir = insereGrafo(val, root->dir);
    return root;
}

Arv *insereAdj(Arv *adj, Arv *root, char val){
    Arv *tmp = root;
    while(tmp != NULL){
        if(tmp->val == val)
            break;
        tmp = tmp->dir;
    }
    if(tmp == NULL){
        Arv tmp2 = *root;
        tmp = root->esq;
        while(1){
            if(tmp->val != val)
                tmp = tmp->esq;
            else
                break;
            if(tmp == NULL){
                tmp = tmp2.dir;
                tmp2 = *tmp2.dir;
            }
        }
    }
    Arv *prox = tmp->esq;
    while(prox != NULL){
        if(prox->val == adj->val)
            return root;
        tmp = prox;
        prox = prox->esq;
    }
    tmp->esq = adj;
    return root;
}

Arv *removeGrafo(char val, Arv *root){
    Arv *tmp = root;
    Arv *pai;
    while(tmp->val != val && tmp != NULL){
        pai = tmp;
        tmp = tmp->dir;
    }
    if(tmp == NULL)
        return NULL;
    pai->dir = tmp->dir;
    tmp->dir = NULL;
    return tmp;
}

void runLeft(Arv *root, string *str){
    Arv *tmpEsq = root->esq;
    while(tmpEsq != NULL){
        *str += tmpEsq->val;
        *str += ",";
        tmpEsq = tmpEsq->esq;
    }
}

int run(Arv *root, string *str){
    Arv *tmp = root;
    int cont = 0;
    while(tmp != NULL){
        *str += tmp->val;
        *str += ",";
        runLeft(tmp, str);
        *str += "\n";
        tmp = tmp->dir;
        cont++;
    }
    return cont;
}

bool contem(char l1, char l2, Arv *root){
    Arv *tmp = root;
    while(tmp != NULL){
        if(tmp->val == l1)
            break;
        tmp = tmp->dir;
    }
    if(tmp == NULL){
        Arv *tmp2 = root;
        tmp = root->esq;
        while(1){
            if(tmp->val != l1)
                tmp = tmp->esq;
            else
                break;
            if(tmp == NULL){
                tmp = tmp2->dir;
                tmp2 = tmp2->dir;
            }
                
        }
    }
    Arv *prox = tmp->esq;
    while(prox != NULL){
        if(prox->val == l2){
            return true; 
        }
        tmp = prox;
        prox = prox->esq;
    }
    return false;
}

Arv *liberarArv(Arv *r){
    if(r != NULL){
        liberarArv(r->esq);
        liberarArv(r->dir);
        free(r);
    }
    return NULL;
}

int main(){
    int cases;
    cin >> cases;
    Arv *root = (Arv *) malloc(sizeof(Arv));
    root = NULL;
    for(int y = 1; y <= cases; y++){
        int v, e;
        cin >> v >> e;
        for(int x = 0; x < v; x++)
            root = insereGrafo('a' + x, root);
        for(int y = 0; y < e; y++){
            char l1, l2;
            cin >> l1 >> l2;
            Arv *adj;
            if(contem(l1,l2,root) == false && contem(l2,l1,root) == false){
                if(l1 > l2){
                    adj = removeGrafo(l1, root);
                    insereAdj(adj, root, l2);
                } else{
                    adj = removeGrafo(l2, root);
                    root = insereAdj(adj, root, l1);
                }
            }
        }
        string str;
        int cont = run(root, &str);
        int tam = str.size();
        selectionSort(str,tam-1);
        cout << "Case #" << y << ":" << endl;
        cout << str << cont << " connected components" << endl << endl;
        root = liberarArv(root);
    }
}