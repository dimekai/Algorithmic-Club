#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
lli n,m,k;

bool k_esimo(lli middle){
    lli cont = 0;
    for(lli i = 1; i <= n; i++)
        cont += min(m ,  middle / i);
    return ( cont >= k );    
}

int main(){
    cin >> n >> m >> k;
    lli low = 1, high = n * m, middle, solution;
    while(low <= high){
        middle = (low + high) >> 1;
        if(k_esimo(middle)){
            solution = middle;
            high = middle - 1;
        }else
            low = middle + 1;
    }
    
    cout << solution << "\n";
    return 0;
}