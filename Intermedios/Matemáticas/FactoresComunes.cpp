#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
#include <algorithm>

using namespace std;

typedef unsigned long long int ulli;
typedef pair<ulli,ulli> plli; 
typedef vector<int> vi;

vi divisors(ulli N){
	int cont = 0;
	vi divisores;

	for(int i =1; i <= sqrt(N); i++){
		if (N%i == 0) divisores.push_back(i);
		if (i*i != N) divisores.push_back(N/i);
	}
	sort(divisores.begin(), divisores.end());

	return divisores;
}

ulli howDivisors(vi divsA, ulli B){
	ulli divs = 0;
	for(int j = 0; j < divsA.size() ; j++)
		if(B%divsA[j] == 0) divs++;

	return divs;
}

int main(){
	plli numbers;
	ulli divs = 0;
	while(cin >> numbers.first >> numbers.second){
		vi divsA = divisors(numbers.first);
		divs = howDivisors(divsA, numbers.second);
		
		cout << divs << "\n";
	}	

}