#include <vector.h>
#include <iostream>
#include <math.h>

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi;
typedef long long int lli;

vi primes;
vb isPrime;

void sievePrime(int n){
	isPrime.resize(n+1, true);
	isPrime[0] = false;
	isPrime[1] = false;
	primes.push_back(2);
	for(int j = 4; j<=n ; j+=2) /*Optimización 01*/
		isPrime[j] = false;
	int cota = sqrt(n);
	for(int k = 3; k<=n; k+=2){ /*Optimización 02*/
		if(isPrime[k]){
			primes.push_back(k);
			if(k <= cota){		/*Optimización 03*/
				for (int i = k*k; i <= n; i+=2*k)
					isPrime[i] = false;				
			}
		}
	}
}

vvi factorsPrime;
void sieveFactorsSieve(lli n){
	factorsPrime.resize(n+1,1);
	for(lli i=0; i<=primes.size(); i++){
		lli possible_factor = primes[i];
		for(lli j = possible_factor; j <=n; j+=possible_factor)
			factorsPrime[j].push_back(possible_factor);
	}
}
