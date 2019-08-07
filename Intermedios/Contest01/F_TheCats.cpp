#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define MAX_COTA 1000000

typedef long long int lli;
typedef vector<int> vi;
typedef vector<bool> vb;

vi primes;
vb isPrime;
void sievePrime(){
	//primes.clear();
	isPrime.resize(MAX_COTA+1,true);
	int cota = sqrt(MAX_COTA)+1;
	isPrime[0] = false;
	isPrime[1] = false;
	//primes.push_back(2);
	for(int j = 4; j<=MAX_COTA ; j+=2) /*Optimización 01*/
		isPrime[j] = false;
	
	for(int k = 3; k<=MAX_COTA; k+=2){ /*Optimización 02*/
		if(isPrime[k]){
			//primes.push_back(k);
			if(k <= cota){			   /*Optimización 03*/
				for (int i = k*k; i <= MAX_COTA; i+=2*k)
					isPrime[i] = false;				
			}
		}
	}
}

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

bool testPrime(lli n){
    if(n > MAX_COTA){
        for(auto & p : primes){
			if(p * p > n) break;
			if(n % p == 0) return false;
		}
        return true;
    }else 
        return isPrime[n];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);      cout.tie(0);
    lli n, b, a = 0, flag;
    sievePrime();
    
    while(cin >> b >> n){
        for(int i = 0; i < n; i++){
            cin >> flag;
            if(testPrime())
                a++;
        }
        if(a == n) cout << n << "\n";
        break;
    }


}