#include <bits/stdc++.h>
#define MAX_COTA 31623  //Raiz de la cota original
using namespace std;

typedef long long int lli;
typedef vector<lli> vi;
typedef vector<bool> vb;

vi primes;
vb isPrime;

void sievePrime(){
	primes.clear();
	isPrime.resize(MAX_COTA + 1,true);
	lli cota = sqrt(MAX_COTA) + 1;
	isPrime[0] = false;
	isPrime[1] = false;
	primes.push_back(2);
	for(lli j = 4; j <= MAX_COTA ; j+=2) /*Optimización 01*/
		isPrime[j] = false;
	
	for(lli k = 3; k <= MAX_COTA; k+=2){ /*Optimización 02*/
		if(isPrime[k]){
			primes.push_back(k);
			if(k <= cota){			   /*Optimización 03*/
				for (lli i = k*k; i <= MAX_COTA; i+=2*k)
					isPrime[i] = false;				
			}
		}
	}
}

bool prime_near(lli n){
    if(n > MAX_COTA){
        for(lli & x : primes){
			if(x * x > n) break;
			if(n % x == 0) return false;
		}
        return true;
    }else 
        return isPrime[n];
}

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);      cin.tie(0);
    lli n;  sievePrime();   cin >> n;
    if(n == 3)          cout << "1\n3\n";
    else if (n == 4)    cout << "2\n2 2\n";
    else if (n == 5)    cout << "2\n2 3\n";
    else if (n == 6)    cout << "2\n3 3\n";
    else{
        n = n - 4;
        lli a = 1, b = n;
        while(a <= b){
            if(prime_near(a) && prime_near(b)) break;
            a++, b--;
        }
        cout << "3\n3 " << a << " " << b << "\n";
    }
    return 0;
}
