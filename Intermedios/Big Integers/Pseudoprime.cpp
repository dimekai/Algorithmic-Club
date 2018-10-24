#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

bool isPrime(lli n){
    /*Casos de rangos*/
    if( n <= 1 ) return false;
    if( n <= 3 ) return true;

    /*Checar primalidad de 
    los primeros casos*/
    if( n % 2 ==0 || n % 3 ==0 ) return false;
    
    for(lli i = 5; i*i <= n ; i += 6){
        if( n%i == 0 || n%(i+2)==0)
            return false;
    }
    return true;    
}

lli expo_mod_bin(lli a, lli b, lli n){
	lli res = 1;
	
	while(b){
		if( b & 1) 
			res = ( res * a) % n;
		b >>= 1;
		a = ( a * a) % n;
	}

	return res;
}

int main(){
    lli a, p;
    lli res = 0;
    while(cin >> p >> a ){

        if(a + p == 0) break;

        if( isPrime(p) ){
            cout << "no";           
        }else{
            res = expo_mod_bin(a, p, p);
            cout << ( (res == a) ? "yes" : "no");
        }
        cout << "\n";
    }
}