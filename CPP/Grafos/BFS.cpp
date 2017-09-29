
void bfs(){
    vector<tree*> fila;
    fila.pushback(this);
    while(!fila.empty()){
        tree *atual = fila.begin();
        fila.push_back(atual->left);
        fila.push_back(atual->right);
        fila.dequeue();
    }
}