#include <iostream>
using namespace std;

int main(){
	int N, A,B,C;

	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> A >> B >> C;
		if (A>B & A>C && C>B){
			cout << "Case "<< (i+1) << ":" << C;
		}else if(B>A && B>C && A>C){
			cout << "Case "<< (i+1) << ":" << A;
		}else if(C>A && C>B && B>A){
			cout << "Case "<< (i+1) << ":" << B;
		}
	}

	return 0;
}