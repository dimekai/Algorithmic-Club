#include <bits/stdc++.h>
#define MAX_COTA 63246  //Raiz de la cota original
using namespace std;

typedef long long int lli;
typedef vector<lli> vi;
typedef vector<bool> vb;

vi primes;
vb isPrime;

void sievePrime(){
	primes.clear();
	isPrime.resize(MAX_COTA + 1,true);
	lli cota = sqrt(MAX_COTA) + 1;
	isPrime[0] = false;
	isPrime[1] = false;
	primes.push_back(2);
	for(lli j = 4; j <= MAX_COTA ; j+=2) /*Optimización 01*/
		isPrime[j] = false;
	
	for(lli k = 3; k <= MAX_COTA; k+=2){ /*Optimización 02*/
		if(isPrime[k]){
			primes.push_back(k);
			if(k <= cota){			   /*Optimización 03*/
				for (lli i = k*k; i <= MAX_COTA; i+=2*k)
					isPrime[i] = false;				
			}
		}
	}
}

bool prime_near(lli n){
    if(n > MAX_COTA){
        for(lli & p : primes){
			if(p * p > n) break;
			if(n % p == 0) return false;
		}
        return true;
    }else 
        return isPrime[n];
}

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);      cin.tie(0);
    lli n;          sievePrime();
    int cases;      cin >> cases;
    while(cases--){
        cin >> n;
        while(!prime_near(n))   n++;
        cout << n << "\n";
    }
    return 0;
}
