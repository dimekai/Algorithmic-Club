#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;


typedef unsigned long long int lli;
typedef vector<int> vi;

lli howDivisors(lli A, lli B){
	vi divisores;
	lli count = 1;
	
	for(int i = 2; i <= sqrt(min(A,B)); i++){
		if (A%i == 0){ 
			if(B%i == 0){
				count++;
				//cout << "F1: "<< i << " of " << A << " y "<< B << "\n";
			}
			
			if (i*i != A){
				if(B%(A/i) == 0){
					count++; 
					//cout << "F2: "<< A/i << " of " << A << " y "<< B << "\n";
				}
			}
		}
	}

	return count;
}

int main(){
	ios_base::sync_with_stdio(0);
	lli A,B;
	while(cin >> A >> B){
		lli divs = 0;
		divs = howDivisors(A, B);
		cout << divs << "\n";
		//cout << "_______" << "\n";
	}	
}