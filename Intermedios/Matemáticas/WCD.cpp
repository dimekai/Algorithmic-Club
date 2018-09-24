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

vi primes;
vi isPrime;

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
}


int GCD(lli a, lli b){
	return (b)?GCD(b,a%b):a;
}

vi factoresPrimos(lli N){
	vi factores;
	int root = sqrt(N);

	for(int i = 2; i <= root ; i++){
		while(N%i == 0){
			factores.push_back(i);
			N /= i;
		}
	}

	if(N>1)
		factores.push_back(N);

	return factores;
}

int main(){
	lli numz;
	cin >> numz;
	cout << "Algo" << "\n";
	vi fact = factorsOfaNumber(numz);
	
	cout << "\n";
}