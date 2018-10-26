#include <bits/stdc++.h>
#define max 1000002
#define INF 2000000
using namespace std;

int m, q;
int arr[max];
int derCercano[max];
int segment_tree[ 2 * max + 1];

void preproceso(){
    map<int,int> mapa;
    for(int i = m; i >= 1; i--){
        if(mapa[ arr[i] ] > 0){
            derCercano[ i ] = mapa[arr[i]];
            mapa[ arr[i] ] = i;
        }else{
            derCercano[i] = INF;
            mapa[ arr[i] ] = i;
        }
    }
}

int f(int nodo){
    return min(segment_tree[nodo * 2], segment_tree[nodo*2 + 1]);
}

void inicializa_ST(int nodo, int ini, int fin){
    if  ( ini == fin)
        segment_tree[ nodo ] = derCercano[ ini ];
    else{
        int mitad = ( ini + fin) / 2;
        inicializa_ST(nodo * 2, ini, mitad);
        inicializa_ST(nodo * 2 + 1, mitad + 1, fin);
        segment_tree[ nodo ] = f(nodo);         
    }
}


int query(int nodo, int ini, int fin, int l, int r){
    if(fin < l || r < ini){
        return INF;
    }else if (l <= ini && fin <= r){
        return segment_tree[nodo];
    }else{
        int mitad = (ini + fin) / 2;
        int izq = query(nodo * 2, ini, mitad, l, r );
        int der = query(nodo * 2 + 1, mitad+1, fin, l, r );
        return min(izq, der);
    }
}

int main(){
    
    while(cin >> m >> q && m!=0 && q!=0){

        for(int i = 1; i <= m; i++ )
            cin >> arr[i];
        
        preproceso();
        inicializa_ST(1, 1, m);

        for(int i = 1; i <= q; i++){
            int l, r;
            cin >> l >> r;
            int indx = query(1,1, m, l, r);
            if( indx > r)
                cout << "OK\n";
            else
                cout << arr[indx] << "\n";
            
        }
        cout << "\n";
    }
    return 0;
}