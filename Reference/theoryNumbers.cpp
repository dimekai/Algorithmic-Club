#include <vector.h>
#include <iostream>
#include <math.h>

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi;
typedef long long int lli;

vi primes;
vb isPrime;

void sievePrime(){
	primes.clear();
	vb isPrime(MAX_COTA+1,true);
	int cota = sqrt(MAX_COTA)+1;
	isPrime[0] = false;
	isPrime[1] = false;
	primes.push_back(2);
	for(int j = 4; j<=MAX_COTA ; j+=2) /*Optimización 01*/
		isPrime[j] = false;
	
	for(int k = 3; k<=MAX_COTA; k+=2){ /*Optimización 02*/
		if(isPrime[k]){
			primes.push_back(k);
			if(k <= cota){			   /*Optimización 03*/
				for (int i = k*k; i <= MAX_COTA; i+=2*k)
					isPrime[i] = false;				
			}
		}
	}
	//return primes;
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

vi factores;
void factorsOfaNumber(lli number){
	vi cota_primes = sievePrime(number);
	for(int i=0; i < cota_primes.size(); i++){
		if(number%cota_primes[i] == 0){
			factores[i] = cota_primes[i];
			number /= cota_primes[i];
		}
	}
}

vi divisores(lli N){
	vi divisores;

	for(int i =1; i <= sqrt(N); i++){
		if (N%i == 0){
		   divisores.push_back(i);
		   if (i*i != N) divisores.push_back(N/i);
		}
	}

	sort(divisores.begin(), divisores.end());

	return divisores;
}

vi factoresPrimos(ulli N){
	vi factores;
	
	for(int i = 2; i <= sqrt(N) ; i++){
		while(N%i == 0){
			factores.push_back(i);
			N /= i;
		}
	}

	if(N>1)
		factores.push_back(N);

	return factores;
}