void inserirAluno(string matricula, string nome, string endereco, string email, string tel, double n1, double n2, double n3){
    aluno_node *novo = new aluno_node(matricula, nome, endereco, email, tel, n1, n2, n3);
    if(raiz == nullptr){
        raiz = novo;
        return;
    }else{
        aluno_node *atual = raiz;
        aluno_node *pai = nullptr;
        while(atual != nullptr){
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