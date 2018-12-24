#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef vector<lli> vi;
typedef vector<bool> vb;

void sievePrime(lli MX_COTA, vi & primes){
	vb isPrime(MX_COTA+1,true);
	primes.push_back(2);
	for(lli i = 3; i <= MX_COTA; i += 2){
		if(isPrime[i]){
			primes.push_back(i);
			for(lli j = i * i; j <= MX_COTA; j += 2 * i){
				isPrime[j] = false;
			}
		}
	}
}

lli phi_euler(lli n, vi & primes){
	lli ans = n;
	for(lli & p : primes){
		//cout << "p = " << p << "\n";
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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);      cout.tie(0);
	vi primes;sievePrime(31623,primes);
	lli n;
    while(cin >> n && n!=0){
        if(n == 1)   cout << "0\n";
        else    cout << phi_euler(n,primes) << "\n";
    }
    return 0;
}