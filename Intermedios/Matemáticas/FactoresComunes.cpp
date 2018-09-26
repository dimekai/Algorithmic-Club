#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef unsigned long long int lli;
typedef vector<int> vi;

vi divisors(lli N){
	vi divisores;

	for(int i =1; i <= sqrt(N); i++){
		if (N%i == 0){ 
			divisores.push_back(i);
			if (i*i != N) 
				divisores.push_back(N/i);
		}
	}
	sort(divisores.begin(), divisores.end());

	return divisores;
}

lli howDivisors(vi divsA, lli B){
	lli divs = 0;
	for(int j = 0; j < divsA.size() ; j++)
		if(B%divsA[j] == 0) divs++;

	return divs;
}

int main(){
	ios_base::sync_with_stdio(0);
	lli A,B;
	while(cin >> A >> B){
		lli divs = 0;
		vi divsA = divisors(A);
		vi divsB = divisors(B);

		cout << A <<" = { ";
		for(auto d: divsA)
			cout << d << " ";
		cout << "}\n";

		cout << B <<" = { ";
		for(auto d: divsB)
			cout << d << " ";
		cout << "}\n";


		divs = howDivisors(divsA, B);
		cout << "Comun: " <<divs << "\n_______\n";
	}	

}