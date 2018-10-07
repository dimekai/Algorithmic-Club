#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef long long int lli;


int main(){
	short dimension, j =0;
	cin >> dimension;
	
	lli A[dimension];
	lli B[dimension];

	lli elemento = 0;

	for( j = 0; j < dimension; j++){
		cin >> elemento;
		A[j] = elemento;
	}
	
	for( j = 0; j < dimension; j++ ){
		cin >> elemento;
		B[j] = elemento;
	}
	j=0, elemento = 0;

	sort(A, A+dimension); 				  //Ascending  sort
	sort(B, B+dimension, greater<lli>()); //Descending sort
	
	for( j ; j < dimension ; j++)
		elemento += A[j]*B[j];

	cout << elemento << "\n";

	return 0;
}