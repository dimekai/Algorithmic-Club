#include <bits/stdc++.h>
#define MX_COTA 100005
#define st(str) str.size();

using namespace std;
typedef vector<bool> vb;

void sievePrime(vb & isPrime){
	//primes.clear();
	isPrime.resize( MX_COTA + 1,true);
	int cota = sqrt(MX_COTA) + 1;
	isPrime[0] = false;
	isPrime[1] = false;
	//primes.push_back(2);
	for(int j = 4; j <= MX_COTA ; j+=2) /*Optimización 01*/
		isPrime[j] = false;
	
	for(int k = 3; k <= MX_COTA; k+=2){ /*Optimización 02*/
		if(isPrime[k]){
			//primes.push_back(k);
			if(k <= cota){			   /*Optimización 03*/
				for (int i = k*k; i <= MX_COTA; i+=2*k)
					isPrime[i] = false;				
			}
		}
	}
}

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);      cin.tie(0);
	vb isPrime;       sievePrime(isPrime);
    string str;
    while(cin >> str && str != "0"){
        int ans = 0, aux, len_str = st(str);
        for(int i = 0; i < len_str; i++){
            for(int j = len_str; j >= i; j--){
                istringstream buff(str.substr(i,j)); //string to integer;
                buff >> aux;
                if(aux > MX_COTA - 5)  continue;
                if(isPrime[aux])    ans = max(ans, aux);
            }
        }
        cout << ans << "\n";        
    }
    return 0;
}