#include <bits/stdc++.h>
#define MX 10005
#define MINUS_INF 1e-4
using namespace std;

double L, u[MX], v[MX];

double f(int n, double x, double L){
    double min_value = x / u[1] +  (L-x) / v[1];
	for (int i = 2; i < n; ++i) 
		min_value = min(min_value, x/u[i] + (L-x)/v[i]);
	return (min_value - x/u[n] - (L-x)/v[n]);
}

int main(){
    int n;
    while(cin >> L >> n && n && L){
        
        for(int i = 1; i <= n; i++)
            cin >> u[i] >> v[i];
        
        /* Busqueda Ternaria */
        double low = 0, 
               high = L,
               div_low, div_high;

        while( high - low > MINUS_INF){
            div_low  = low  + ( high - low) / 3.0;
            div_high = high - ( high - low) / 3.0;

            
            if ( f(n, div_low,L) > f(n, div_high,L) )
                high = div_high;
            else
                low = div_low;
        }
        if ( f(n, low, L) < 0)
			printf("The cheater cannot win.\n");
		else {
			printf("The cheater can win by %.0lf", f(n, low, L) * 3600);
			printf(" seconds with r = %.2lfkm and k = %.2lfkm.\n",low, L - low);
		}        
    }
    return 0;
}