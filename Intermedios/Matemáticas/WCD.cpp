#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <set>

using namespace std;

typedef long long int lli;
typedef pair<lli,lli> plli;
typedef vector<int> vi;
typedef vector<bool> vb;

vi sievePrime(lli n){
	cout << "Entra a criba" << "\n";
	vi primes;
	vb isPrime;

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


int GCD(lli a, lli b){
	return (b)?GCD(b,a%b):a;
}

vi factorsOfaNumber(lli numero){
	cout << "Entra a factNum\n";
	vi factores(sqrt(numero),0);
	vi cota_primes = sievePrime(sqrt(numero));
	for(int i=0; i < cota_primes.size(); i++){
		cout << "-" << cota_primes[i] << "\n";
		if(numero%cota_primes[i] == 0){
			factores[i] = cota_primes[i];
			numero /= cota_primes[i];
		}
	}

	for(int i=0; i<factores.size(); i++)
		cout << factores[i] << ",";

	return factores;
}

int main(){
	lli numz;
	cin >> numz;
	cout << "Algo" << "\n";
	vi fact = factorsOfaNumber(numz);
	
	cout << "\n";
}