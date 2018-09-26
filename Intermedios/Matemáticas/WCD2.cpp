#include <iostream>

using namespace std;

typedef long long int lli;

lli divisores(lli N){

	for(lli i =2; i*i <= (N); i++)
		if (N%i == 0) return i;
	
	return N;
}

lli GCD(lli a, lli b){
	return (b)? GCD(b,a%b): a;
}

int main(){
	int nums;
	lli A, B;
	cin >> nums;
	cin >> A >> B;
	
	for(int i = 1; i < nums; i++){
		lli p,q;
		cin >> p >> q;

		//cout << "(p , q): (" << p << "," << q << ")\n";
		//cout << "GCD(" << A << "," << p*q << "):  ";
		A = GCD(A, p * q);
		//cout << A << "\n";

		//cout << "GCD(" << B << "," << p*q << "):  ";
		B = GCD(B, p * q);
		//cout << B << "\n";

	}

	//cout << "A: " << A << "\n";
	//cout << "B: " << B << "\n";	

	if(A != 1)		cout << divisores(A);
	else if(B != 1)	cout << divisores(B);
		 else		cout << "-1";

	cout << "\n";
}	