#include <bits/stdc++.h>
#define MX_COTA 1000
using namespace std;

typedef vector<int> vi;

void sieveDivisors(vi & suma){
    for(int i = 1; i <= MX_COTA; i++)
        for(int j = i; j <= MX_COTA; j += i)
            suma[j] += i;       //suma de factores   
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);      cout.tie(0);
    vi suma(MX_COTA + 1,0), res(MX_COTA + 1, -1);
    int s, casos = 1;        sieveDivisors(suma);
    
    for(int i = 1; i <= MX_COTA; i++)
        if(suma[i] <= MX_COTA) 
            res[suma[i]] = max(res[suma[i]], i);
    
    while(cin >> s && s)
        cout << "Case " << (casos++) << ": " << res[s] << "\n";

    return 0;
}