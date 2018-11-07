#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
const int COTA = 2*100000 + 10;

lli ST[ COTA << 2];
lli arr[ COTA ];
int sum[ COTA ];
int N, Q;

/* ===== SEGMENT TREE ===== */

void f( int nodo) {
    /*Funcion de suma del segment tree por cada nodo*/
    if( ST[ nodo ] ){
        ST[ nodo << 1 ] += ST[ nodo ];
        ST[ nodo << 1 | 1 ] += ST[ nodo ];
        ST[ nodo ] = 0;
    }
    return;
} 


void create_segment(int ini, int fin, int nodo){
    ST[ nodo ] = 0;
    if( ini = fin) return;

    int mitad = ( ini + fin ) >> 1;  // a/2 = a >> 1
    create_segment( ini, mitad, nodo<<1 ); // nodo << 1 = 2*nodo
    create_segment( mitad + 1, fin, nodo<<1 | 1);
    return;
}

void update(int ini, int fin, int nodo, int l, int r, int val){
    if( l == ini && r == fin){
        ST[ nodo ] += val; 
        return;
    }
    f( nodo );
    int mitad = ( ini + fin ) >> 1;
    if( r <= mitad ){
        update( ini, mitad, nodo << 1, l, r, val);
    }else if( l > mitad ){
        update( mitad + 1, fin, nodo << 1 | 1, l, r, val);
    }else{
        update( ini, mitad, nodo << 1, l, mitad, val);
        update( mitad + 1, fin, nodo << 1 | 1, mitad + 1, r, val);
    }
    return;
}

int query(int ini, int fin, int nodo, int pos){
    if( ini == fin ){
        return ST[ nodo ];
    }
    f( nodo );
    int mitad = ( ini + fin ) >> 1;
    if( pos <= mitad )
        return query(ini, mitad, nodo << 1, pos);
    else
        return query(mitad + 1, fin, nodo << 1 | 1, pos);
}


int main(){
   	ios_base::sync_with_stdio(0);
    int l, r;

    cin >> N >> Q;
    
    for(int i = 1; i <= N; i++)
        cin >> arr[i];
    
    create_segment(1,N,1);
    
    for(int i = 1; i <= Q; i++){
        cin >> l >> r;
        update(1,N, 1, l, r, 1);
    }

    sort(arr + 1, arr + N + 1);

    for(int i = 1; i <= N; i++)
        sum[ i ] = query(1, N, 1, i);
    
    sort(sum + 1, sum + N + 1);

    lli max_sum = 0;
    for(int i = 1; i <= N; i++)
        max_sum += 1LL * arr[i] * sum[i];

    cout << max_sum << "\n";

    return 0;
}