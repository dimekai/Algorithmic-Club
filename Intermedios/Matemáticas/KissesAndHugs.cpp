#include <bits/stdc++.h>
#define mod 1000000007
typedef long long LL;
using namespace std;

LL pow(LL a, LL b){
	LL r;
	if( b == 0 ) return 1;
	r = pow(a,b/2);
	r = (r*r) % mod;
	if(b%2) r = (r*a) % mod;
	return r;
}

int main(){
    int t;
	cin >> t;
	
	while(t--){
		LL n,n1;
		cin >> n;
		
		n++;
    	n1 = n/2;
    	n = pow(2,n1) + pow(2,(n - n1)) - 2;
 
    	cout << n%mod << "\n";
	}


    return 0;
}