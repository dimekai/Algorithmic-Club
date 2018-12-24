#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

lli GCD(lli a, lli b){
	return (b)? GCD(b,a%b): a;
}

lli LCM(lli a, lli b){
	return (a*b)/GCD(a,b);
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);      lli a, c, b;
    int test;        cin >> test;
    while( test-- ){
        cin >> a >> c;
        if( c%a != 0){
            cout<<"NO SOLUTION\n" ;
            continue;
        }
        b = c / a;
        lli i;
        for( i = b; i <= c; i+=b)
            if( LCM(i,a) == c )
                break ;
        
        cout << i << "\n";
    }
    return 0;
}