#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

int main(){
    lli a, b;
    
    while(cin >> a >> b){

        if( a + b == 0) break;
        short m = 0, p = 0, acarreo = 0, total = 0;    

        while(!(a==0 && b==0)){
            m = a % 10; p = b % 10;
            acarreo = ( acarreo + m + p) / 10;    
            a /= 10; b /= 10;
            if( acarreo > 0) total++;
        }

        if( total == 0)
            cout << "No carry operation.";
        else if( total == 1)
            cout << "1 carry operation.";
        else
            cout << total << " carry operations.";
        
        cout << "\n";
    }
    
}