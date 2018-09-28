#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef vector<lli> vi;

vi howDivisors(lli N){
	vi divisores;

	for(lli i = 1; i <= sqrt(N); i++){
		if ( N % i == 0){
		   divisores.push_back(i);
		   if ( i*i != N) divisores.push_back( N / i );
		}
	}

	sort(divisores.begin(), divisores.end());

	return divisores;
}

int main(){
	lli n;
	lli num_tetras = 0;
	while(cin >> n){
		vi is_tetra = howDivisors(n);
		if(is_tetra.size() == 4){
			cout << ++num_tetras << " : " << n << " = { ";
			for(auto tetra : is_tetra)
				cout << tetra << " ";
			cout << "}\n";
		}
	}
}