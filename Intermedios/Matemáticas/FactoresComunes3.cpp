#include <iostream>
#include <algorithm>  

using namespace std;

template<typename T>
T howDivisors(T N){
	T divisores = 0;

	for(T i = 1; i*i <= N; i++){
		if (N % i == 0) 
			divisores = (N/i != i)? divisores + 2: divisores + 1;
	}
	return divisores;
}

int main(){
	ios_base::sync_with_stdio(0);
	uint64_t  A,B;
	cin >> A >> B;
	auto gcd = __gcd(A,B);
	cout << howDivisors(gcd) << "\n";
	//cout << "_______" << "\n";
		
}