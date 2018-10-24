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


/*
	Implementación recursiva
	@param a: representa la base
	@param b: representa la potencia
	@param n: representa el modulo

	@return res: resultado de la exponenciacion binaria 

	La expresion es de la forma
			a^b % n

	Complejidad: O(log(N))
*/
lli expo_mod_bin(lli a, lli b, lli n){
	lli res = 1;
	if( b == 1) return (a % n);
	if( b % 2 == 0){ // Si la potencia es par
		res = (expo_mod_bin(a, b>>1, n)) % n;
		return ( res * res) % n; 
	}else{
		res = (expo_mod_bin(a, b - 1, n)) % n;
		return ( res * (a % n) ) % n;
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

bool isPrime(lli n){
    /*Casos de rangos*/
    if( n <= 1 ) return false;
    if( n <= 3 ) return true;

    /*Checar primalidad de 
    los primeros casos*/
    if( n % 2 ==0 || n % 3 ==0 ) return false;
    
    for(lli i = 5; i*i <= n ; i += 6){
        if( n%i == 0 || n%(i+2)==0)
            return false;
    }
    return true;    
}
