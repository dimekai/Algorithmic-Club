#include <iostream>
#include <utility>
#include <vector>
#include <cmath>

using namespace std;

typedef long long int lli;
typedef vector<int> vi;
typedef vector<bool> vb;

const lli MAX_COTA = 1299709;
const lli MAX_LIMI = 1000000;

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

/*Aqui se hace una busqueda binaria en la criba para saber
  si es primo y ver si se debe considerar el prime gap*/
lli numberIsPrime(lli number){
	lli low = 0,
	    high = primes.size()-1,
	    middle;
 
	while(low <= high){
		middle = (low+high)/2;
		
	    cout << "low: " << low <<"\n";
		cout << "high: " << high <<"\n";
		cout << "middle: " << middle <<"\n";
		cout << "primes[" << middle << "]: " << primes[middle] <<"\n";
	

		if (primes[middle] == number)
			return middle;
		else if (primes[middle] > number)
			high = middle - 1;
		else
			low = middle + 1;
	}
	return middle;
}

int main(){
	
	lli k, i=0;
	sievePrime();	
	
	
	while(cin >> k){
		if(k==0) break;
		
		lli indice = numberIsPrime(k);

		for (int i = 0; i < 2*sqrt(k); ++i)
			cout << primes[i] <<" ";

		cout << "middle: " << indice <<"\n";

		if(primes[indice] == k) 
			cout << "0";
		else if(k < primes[indice]) 
			cout << primes[indice] - primes[indice-1];
		else
			cout << primes[indice+1] - primes[indice];

		cout << "\n";
	}
}
