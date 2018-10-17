#include <bits/stdc++.h>
#define INF 10e7

using namespace std;
typedef long long int lli;
lli N;

int num[N];
int ST[f(N)];

/*Donde f(n): Devuelve la 1er potencia >= N, y eso *2 - 1*/

void createSegmentTree(int ini, int fin, int nodo){
    if ( ini == fin){
        ST[ nodo ] = num[ ini ];
    }else{
        int mitad = ( ini + fin ) / 2;
        //createSegmentTree( ini, mitad, nodo * 2); //Indexado desde 1
        createSegmentTree( ini, mitad, (nodo * 2) + 1); //Indexado desde 0
        createSegmentTree( mitad + 1, fin, (nodo * 2) + 2); 
        ST[ nodo ] = min( ST[ (nodo * 2) + 1] , ST[ (nodo * 2) + 2] );
    }
}

void update( int ini, int fin, int nodo, int x, int val ){
    if( ini == fin && ini == x){
        ST[ nodo ] = val;
    }else if( ini <= x && x <= fin){
        int mitad = ( ini + fin ) / 2;
        update (ini, mitad, ( nodo * 2) + 1 , x, val);
        update (mitad + 1, fin, ( nodo * 2) + 2 , x, val);
        ST[ nodo ] = min( ST[ (nodo * 2) + 1] , ST[ (nodo * 2) + 2] );
    }
}

int query( int ini, int fin, int nodo, int i, int j){
    if( fin < i && j < ini){
        return INF;
    }else if( i <= ini  &&  fin <= j ){
        return ST[ nodo ];
    }else{
        int mitad = ( ini + fin ) / 2;
        int izq = query( ini, mitad, (nodo * 2) + 1, i, j);
        int der = query( mitad + 1, fin, (nodo * 2) + 2, i, j);
        
        return min(izq, der);
    }
}