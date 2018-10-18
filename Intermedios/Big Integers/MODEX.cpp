#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int lli;
/*
	Implementación recursiva
	@param a: representa la base
	@param b: representa la potencia
	@param n: representa el modulo

    La expresion es de la forma
            a^b % n

	@return res: resultado de la exponenciacion binaria 

	Complejidad: O(log(N))
*/
lli expo_mod_bin(lli x, lli y, lli n){
	lli res = 1;
	if( y == 1) return (x % n);
	if( y % 2 == 0){ // Si la potencia es par
		res = (expo_mod_bin(x, y>>1, n)) % n;
		return ( res * res) % n; 
	}else{
		res = (expo_mod_bin(x, y - 1, n)) % n;
		return ( res * (x % n) ) % n;
	}
}

int main(){
    lli x, y, n, casos;
    
    cin >> casos;
    while(casos--){
        cin >> x >> y >> n;
        cout << expo_mod_bin(x, y, n) << "\n";
    }
    cin >> casos;        
    return 0;
}

