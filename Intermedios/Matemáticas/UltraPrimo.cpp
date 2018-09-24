#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <string>
#include <cstdlib>

using namespace std;

const int MAX_COTA = 1000;

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
	primes.push_back(1);
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

int ultraSum(string Mi){
	int sum = 0;
	for(int j=0; j< Mi.size(); j++)
		sum += (int)(Mi[j]-48);

	return sum;
}

/*bool isUltraPrime(int sum){
	for(int i=0; i<primes.size();i++){
		if(sum == primes[i]) return true;
	}

	return false;
}*/

bool isUltraPrime(int sum){
	int low = 0,
	  high = primes.size()-1,
	  middle = 0;
 
	while(low <= high){
		middle = (low+high)/2;	

		if (primes[middle] == sum)
			return true;
		else if (primes[middle] > sum)
			high = middle - 1;
		else
			low = middle + 1;
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(0);
	sievePrime();
	short M;
	cin >> M;
	while(M--){
		string Mi;
		cin >> Mi;
		
		int sum = ultraSum(Mi);

		if(isUltraPrime(sum))
			cout << "UltraPrimo";
		else
			cout << "No UltraPrimo";
		
		cout << "\n";	
	}
}