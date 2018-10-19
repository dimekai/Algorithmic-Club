#include <bits/stdc++.h>
#define MAX 100000

using namespace std;

int elementos[MAX + 10];
int segment_tree[5*MAX + 100];

/*============= SEGMENT TREE =============*/

/* 
    @param nodo: Será el nodo al que se le asignara
                la función.

    f(nodo) : Es la función que puede variar dependiendo
              el problema del Segment Tree: En este caso
              es una simple multiplicación de valores.
*/
int f(int nodo){
    return segment_tree[ (2 * nodo) ] * segment_tree[ (2 * nodo) + 1]; 
}

/* =============== CREATE SEGMENT TREE =================
    @param inicio : especifica el inicio del rango que abarca ese nodo
    @param fin : especifica el fin del rango que abarca ese nodo
    @param nodo: especifica el nodo en cuyo rango se pondrá la operacion

*/
void createSegmentTree(int inicio, int fin, int nodo){
    if ( inicio == fin){
        segment_tree[ nodo ] = elementos[ inicio ];
        return;
    }else{
        int mitad = ( inicio + fin ) / 2;
        //createSegmentTree( inicio, mitad, nodo * 2); //Indexado desde 1
        createSegmentTree( inicio, mitad, (nodo * 2)); //Indexado desde 0
        createSegmentTree( mitad + 1, fin, (nodo * 2) + 1); 
        segment_tree[ nodo ] = f(nodo);
    }
}

/* ============ UPDATE NODE ============
    @param inicio : especifica el inicio del rango que abarca ese nodo
    @param fin : especifica el fin del rango que abarca ese nodo
    @param nodo: especifica el nodo en cuyo rango se pondrá la operacion
    @param indice: indice del nodo que se va actualizar
    @param val  : valor en el nodo del inidice que voy a asignar

*/
void update( int inicio, int fin, int nodo, int index, int val){
    if( inicio == fin){
        segment_tree[ nodo ] = val;
        return;
    }else if( inicio <= index && index <= fin){
        int mitad = ( inicio + fin ) / 2;
        update (inicio, mitad, ( nodo * 2) , index, val);
        update (mitad + 1, fin, ( nodo * 2) + 1 , index, val);
        segment_tree[ nodo ] = f(nodo);
    }
    return;
}

/* ============ QUERY OF THE SEGMENT TREE ============
    @param inicio : especifica el inicio del rango que abarca ese nodo
    @param fin : especifica el fin del rango que abarca ese nodo
    @param nodo: especifica el nodo en cuyo rango se pondrá la operacion
    @param i : Rango de busqueda inferior ().
    @param j : Rango de busqueda superior.

    Ejemplo: Si el rango es [1-7] :->  i = 1, j = 7

*/
int query( int inicio, int fin, int nodo, int i, int j){
    if( i > fin && j < inicio ){
        return 1; /* Se regresa uno por que M*1 = M y no afecta */
    }else if( inicio >= i  &&  fin <= j ){
        return segment_tree[ nodo ];
    }else{
        int mitad = ( inicio + fin ) / 2;
        int izq = query( inicio, mitad, (nodo * 2) , i, j);
        int der = query( mitad + 1, fin, (nodo * 2) + 1, i, j);
        
        return izq * der;
    }
}


int main(){
    int N, K;
    
    while(cin >> N >> K){

        string signo = "";
        
        for(int i = 0; i < N; i++){
            cin >> elementos[i];            
            if( elementos[i] > 1)   elementos[i] = 1;
            if( elementos[i] < -1)  elementos[i] = -1;
        }

        /* ==== Creating Segment Tree ==== */
        createSegmentTree(0, N - 1, 1);
        
        char c[5];

        while( K-- ){
            cin >> c;
            if( c[0] == 'C'){
                /* I : indice   ,   V : valor */
                int I, V;
                cin >> I >> V;

                if(V > 1)   V = 1;
                if(V < -1)  V = -1;
                I--;
            //  update(inicio,fin,nodo,indice,valor)
                update(0, N - 1, 1, I, V);
                elementos[ I ] = V;

            }else{
                /* I = i    , J = j */
                int I , J, res;
                cin >> I >> J;
                I--, J--;
                res = query( 0, N - 1, 1, I, J);
                
                if (res == 1)         signo = signo + "+";
                else if(res == -1)    signo = signo + "-";
                else    signo = signo + "0";
            }
        }
        cout << signo << "\n";
    }
    return 0;
}

