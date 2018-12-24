#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> FACTOR;
typedef vector<int> vi;
typedef vector<bool> vb;

vi primes;

void print_format(int n){
	if( n > 0 && n < 10 ) cout << "  " << n;
	else if( n > 9 && n < 100 ) cout << " " << n;
	else cout << n;
}

void sievePrime(int MAX_COTA){
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
}

/*
	=========== FACTORES DEL FACTORIAL ==========
	@param: int n -> Numero factorial
	@param: const vector<int> & primes -> Criba de numeros primos
	
	@return: vector<FACTOR>: Se comporta como un Hash

	@desc: Regresa un vector de pares con los factores primos
		   del factorial de un número n: n!
		   La criba de los primos debe estar previamente ordenada.
*/
vector<FACTOR> factoresFactorial(int n, const vi & primes){
	vector<FACTOR> factores;
	for(int i = 0; i < primes.size(); i++){
		if( primes[i] > n ) break;
		int p = primes[i];
		int reps = n / p;

		while( primes[i] <= ( n / p ) ){
			p *= primes[i];
			reps += ( n / p );
		}
		factores.push_back( FACTOR (primes[i], reps) );
	}
	return factores;
}

/*int main(){
	int n;
	while(cin >> n && n!=0){
		sievePrime(n);
		
		int c = 0;
		vector<FACTOR> fac = factoresFactorial(n, primes);
		for( FACTOR f : fac){
			if(c==15) cout << endl << "      ";
            print_format(f.second);
            c++;
		
		}
		cout << "\n";
	}
}*/

int main(){
    int n, max_factorial = 0;
	vi casos;

    while(cin >> n && n != 0){
		casos.push_back(n);
		max_factorial = (n > max_factorial)? n : max_factorial;
    }

	sievePrime(max_factorial);

	for( int k : casos){
		vector<FACTOR> factores = factoresFactorial(k, primes);
		print_format(k); cout << "! =";
		n = 0;
		for( FACTOR f : factores){
			if( n == 15 ) cout << endl << "      ";
			print_format( f.second );
			n++;
		}
		cout << "\n";
	}

	return 0;
}

