#include <bits/stdc++.h>
using namespace std;

void sieve_divisors(int N, vector<int> & divs){
	divs.resize(N+1,0);
	for(int i = 1; i <= N; i++){
		for(int j = i; j <= N; j += i){
			divs[j]++;
		}
	}
}

int main(){
	int n, closest;
	int COTA = 1100000;
	cin >> n;
	vector<int> divisores;
	sieve_divisors(COTA+1, divisores);
	int left = n - 1;
	int rigth = n + 1;
	while(true){
		if(rigth <= COTA && divisores[rigth] == divisores[n]){
			closest = rigth;
			break;
		}
		if(left > 0 && divisores[left] == divisores[n]){
			closest = left;
			break;
		}
		++rigth;
		--left;
	}
	cout << closest;
	return 0;
}