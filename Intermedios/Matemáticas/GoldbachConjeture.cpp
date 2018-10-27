#include <bits/stdc++.h>
#define MAX_COTA 1000000

using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;

vi primes;

void sievePrime(vb & isPrime){
	//primes.clear();
	isPrime.resize(MAX_COTA+1,true);
	int cota = sqrt(MAX_COTA)+1;
	isPrime[0] = false;
	isPrime[1] = false;
	//primes.push_back(2);
	for(int j = 4; j<=MAX_COTA ; j+=2) /*Optimización 01*/
		isPrime[j] = false;
	
	for(int k = 3; k<=MAX_COTA; k+=2){ /*Optimización 02*/
		if(isPrime[k]){
			//primes.push_back(k);
			if(k <= cota){			   /*Optimización 03*/
				for (int i = k*k; i <= MAX_COTA; i+=2*k)
					isPrime[i] = false;				
			}
		}
	}
}

int main(){
    ios_base::sync_with_stdio(0);

    int N;
    vb isPrime;
    sievePrime(isPrime);
    /*Goldbach's Conjecture
        N = a + b
        donde a y b son primos
    */
    while(cin >> N && N != 0){
        int a = 1;
        int b = N - 1;

        while( a <= b ){
            if( isPrime[a] && isPrime[b]) break;
            a++;
            b--;
        }
        cout << N << " = " << a << " + " << b << "\n";
    }
    return 0;
}
