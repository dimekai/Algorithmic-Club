#include <bits/stdc++.h>
#define mod 10000007
using namespace std;

typedef long long int lli;

/*
	Implementación no recursiva
	@param a: representa la base
	@param b: representa la potencia
	@param n: representa el modulo

	La expresion es de la forma
			a^b % n

	@return res: resultado de la exponenciacion binaria 
*/
lli expo_mod_bin(lli a, lli b, lli n){
	lli res = 1;
	
	while(b){
		if( b & 1) 
			res = ( res * a) % n;
		b >>= 1;
		a = ( a * a) % n;
	}

	return res;
}

int main(){
    lli n, k;
    while(cin >> n >> k && n && k){
        lli a = (2 * expo_mod_bin((n - 1), k, mod)) % mod,
            b = expo_mod_bin(n, k, mod),
            c = (2 * expo_mod_bin((n - 1), n - 1, mod)) % mod,
            d = expo_mod_bin(n, n, mod);
        lli res = ( (a+b) % mod + (c+d) % mod ) % mod;
        cout << res << "\n";
    }
    return 0;
}

