#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int lli;
/*
	Implementación no recursiva
	Con la recursiva da TimeLimit
	@param a: representa la base
	@param b: representa la potencia
	@param n: representa el modulo

    La expresion es de la forma
            a^b % n

	@return res: resultado de la exponenciacion binaria 

	Complejidad: O(log(N))
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
    lli b, p, m;
    while(cin >> b >> p >> m){
		cout << expo_mod_bin(b, p, m) << "\n";
	}
    return 0;
}

