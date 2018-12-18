#include <bits/stdc++.h>
#define MAX_COTA 9999999
using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;

vi primes;
vb isPrime;

void sievePrime(){
	primes.clear();
	isPrime.resize(MAX_COTA+1,true);
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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);      cout.tie(0);
    int n; sievePrime(); cin >> n;
    cout << primes[n-1] << "\n";
    return 0;
}