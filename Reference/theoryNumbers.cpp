#include <vector.h>
#include <iostream>
#include <math.h>

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi;
typedef long long int lli;
typedef pair<int,int> FACTOR; /*Se usa para el factorial*/

vi primes;
vb isPrime;

void sievePrime(lli MAX_COTA){
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

vi factoresPrimos(lli N){
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

vi suma;
void sieveDivisors(int n){
	suma.resize(n + 1, 0);
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j += i){
			suma[j] += i;
		}
	}
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

bool testisPrime(lli n){
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

/*
	=========== FACTORES DEL FACTORIAL ==========
	@param: lli n -> Numero factorial
	@param: const vector<int> & primos -> Criba de numeros primos
	
	@return: vector<FACTOR>: Se comporta como un Hash

	@desc: Regresa un vector de pares con los factores primos
		   del factorial de un número n: n!
		   La criba de los primos debe estar previamente ordenada.
*/

vector<FACTOR> factoresFactorial(lli n, const vi & sieve_primos){
	vector<FACTOR> factores;
	for(int i = 0; i < primes.size(); i++){
		if( primes[i] > n ) break;
		int p = primes[i];
		int reps = n / p;

		while( primes[i] <= ( n / p ) ){
			p *= primes[i];
			reps += ( n / p );
		}
		factores.push_back( FACTOR ( primes[i], reps ) );
	}
	return factores;
}

lli GCD(lli a, lli b){
	return (b)? GCD(b,a%b): a;
}

lli LCM(lli a, lli b){
	return (abs(a*b)/GCD(a,b));
}

/*
	@name:	phi_euler_v1
	@param: int n;
	@return: int phi
	@desc:	Es la primera versión de phi de Euler.
			Probablemente pueda ser optimizada.
*/
lli phi_euler_v1(lli n){
	lli i = 1, phi = 0;
	if(n <= 2)
		return 1;
	while(i < n){
		if(GCD(i,n) == 1) 
			phi++;
		i++;
	}
	return phi;
}

/*
	@name:	phi_euler
	@param: int n;
	@return: int phi
	@desc:	Es la primera versión de phi de Euler optimizada.
*/
lli phi_euler(lli n, vi & primes){
	lli ans = n;
	for(lli & p : primes){
		if(p * p > n) break;
		if(n % p == 0){
			while(n % p == 0){
				n /= p;
			}
			ans -= ans / p;
		}
	}
	if(n > 1) ans -= ans / n;
	return ans;
}

lli phi(lli n){
    lli res=0;
    lli j;
    if (n==1) return 1;
    res=n;
    if (n%2==0){
        res-=res/2;
        while (n%2==0) n/=2;
    }
    for (j=3; j*j<=n; j+=2){
        if (n%j==0){
            res-=res/j;
            while (n%j==0) n/=j;
        }
    }
    if (n>1) res-=res/n;
    return res;
}

vi sieveOfFactorsPhiEuler;
vi sievePhiEuler(lli n){
	sieveOfFactorsPhiEuler.resize(n+1,1)
	for(int i = 1; i <= n; i++){
		//sieveOfFactorsPhiEuler[i] = phi_euler_v1(i);
		sieveOfFactorsPhiEuler[i] = phi_euler(i);
	}
	return sieveOfFactorsPhiEuler;
}
