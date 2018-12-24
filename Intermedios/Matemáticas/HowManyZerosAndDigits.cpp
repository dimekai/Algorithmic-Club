#include <bits/stdc++.h>
#define MILI_INF 1e-9
using namespace std;

int how_digits(int n, int b){
    double sum = 0;
	for(int i = 1; i <= n; i++)
		sum += log((double)i);
	
	sum = sum / log((double)b);
	return floor(sum + MILI_INF) + 1;
}

int how_zeros(int n, int b){
    int cnt1, cnt2;
	int maxprime;
	for(int i = 2; i <= b; i++) {
		cnt1 = 0;
		while(b % i == 0) { // El mayor numero primo
			maxprime = i;
			cnt1++;
			b /= i;
		}
	}
	cnt2 = 0;
	for(int i = maxprime; i <= n; i *= maxprime)
		cnt2 += (n/i)/cnt1;
	
	return cnt2;
}


int main(){
    int n, b;
    while(cin >> n >> b && n && b){
        int digits = how_digits(n,b);
        int zeros  = how_zeros(n,b);
        cout << zeros << " " << digits << "\n";
    }

    return 0;
}