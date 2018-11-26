#include <bits/stdc++.h>
#define mx 10005
#define b 1.0

using namespace std;

typedef long long ll;

int main(){
    ll n, h;
    double x[mx];

    while(cin >> n >> h){
        for(ll i = 1; i < n; i++){
            x[i] = h * sqrt( i / (n * b));
            //cout << "x[" << i << "]: " << x[i] << "\n";
        }

        printf("%.12llf",x[1]);

        for(ll i = 2; i < n; i++)
            printf(" %.12llf",x[i]);
        
        printf("\n");
    }


    return 0;
}
