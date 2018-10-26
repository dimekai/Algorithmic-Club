#include <bits/stdc++.h>
#define MAX 100000

using namespace std;

int N, K;
int elementos[MAX + 10];
int segment_tree[4*MAX + 10];

int helper(int x){
    if(x == 0) 
        return 0;
    else if( x < 0) 
        return -1;
    else 
        return 1;
}
/*============= SEGMENT TREE =============*/
/* 
    @param nodo: Será el nodo al que se le asignara
                la función.

    f(nodo) : Es la función que puede variar dependiendo
              el problema del Segment Tree: En este caso
              es una simple multiplicación de valores.
*/
int f(int nodo){
    return segment_tree[ 2 * nodo ] * segment_tree[ 2 * nodo + 1]; 
}

/* =============== CREATE SEGMENT TREE =================
    @param inicio : especifica el inicio del rango que abarca ese nodo
    @param fin : especifica el fin del rango que abarca ese nodo
    @param nodo: especifica el nodo en cuyo rango se pondrá la operacion

*/
void createSegmentTree(int inicio, int fin, int nodo){
    if ( inicio == fin){ /*Es una hoja*/
        segment_tree[ nodo ] = helper( elementos[ inicio ] );
        
    }else{
        int mitad = ( inicio + fin ) / 2;
        //createSegmentTree( inicio, mitad, nodo * 2); //Indexado desde 1
        createSegmentTree( inicio, mitad, nodo * 2); //Indexado desde 0
        createSegmentTree( mitad + 1, fin, nodo * 2 + 1); 
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
    if( inicio == fin && inicio == index){
        segment_tree[ nodo ] = val;

    }else if( inicio <= index && index <= fin){
        int mitad = ( inicio + fin ) / 2;
        update (inicio, mitad, nodo * 2 , index, val);
        update (mitad + 1, fin, nodo * 2 + 1 , index, val);
        segment_tree[ nodo ] = f(nodo);
    }
}

/* ============ QUERY OF THE SEGMENT TREE ============
    @param inicio : especifica el inicio del rango que abarca ese nodo
    @param fin : especifica el fin del rango que abarca ese nodo
    @param nodo: especifica el nodo en cuyo rango se pondrá la operacion
    @param i : Rango de busqueda inferior ().
    @param j : Rango de busqueda superior.

    Ejemplo: Si el rango es [1-7] :->  i = 1, j = 7

*/
int query( int inicio, int fin, int nodo, int l , int r){
    if( fin < l || r < inicio ){
        return 1; /* Se regresa uno por que M*1 = M y no afecta */
    }else if( l <= inicio  &&  fin <= r ){
        return segment_tree[ nodo ];
    }else{
        int mitad = ( inicio + fin ) / 2;
        int izq = query( inicio, mitad, nodo * 2 , l, r);
        int der = query( mitad + 1, fin, nodo * 2 + 1, l, r);
        
        return (izq * der);
    }
}


int main(){
   
    while(cin >> N >> K){
       
        for(int i = 1; i <= N; i++)
            cin >> elementos[i];            
            
        /* ==== Creating Segment Tree ==== */
        //createSegmentTree(inicio, fin, nodo);
        createSegmentTree(1, N, 1);
        
        for(int i = 1; i <= K ; i++){
            char opc;
            cin >> opc;
            if( opc == 'C'){
                int index, val;
                cin >> index >> val;

            //  update(inicio,fin,nodo,indice,valor)
                update(1, N, 1, index, helper(val));
                
            }else{
                /* I = l    , J = r */
                int l , r;
                cin >> l >> r;

            //  query(inicio,fin,nodo,left , right)
                int res = query(1,N,1, l,r);
                
               if(res == 0)
					cout << "0";
				else if(res < 0)
					cout << "-";
				else
					cout << "+";
            }
        }
        cout << "\n";
    }
    return 0;
}