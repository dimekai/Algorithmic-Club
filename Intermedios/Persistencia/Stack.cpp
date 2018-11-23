struct PStack{
    PStack * sig;
    int x;
    PStack(): sig(nullptr), x(0){}
};

PStack * version[1000];

PStack * pop(int v, int x){
    PStack * nuevo = new PStack;
    nuevo->sig = version[v];
    nuevo->x = x;
    return nuevo;
}

PStack * pop(int v){
    return version[v]->sig;
}

/* main
    version[i] = push(i-1, 10);
    vercion[i] = pop(i-1);
*/