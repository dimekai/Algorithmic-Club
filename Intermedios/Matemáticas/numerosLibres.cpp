#include <iostream>
#include <utility>

using namespace std;

typedef long long int lli;

int GCD(lli a, lli b){
	if(b == 0) return a;
	return GCD(b, a%b);
}

int main(){
	pair<lli,lli> nums_free;
	short N;
	cin >> N;
	while(N--){
		cin >> nums_free.first >> nums_free.second;
		int isFree = GCD(nums_free.first, nums_free.second);
		//cout << "GCD" << isFree << "\n";
		cout << ((isFree == 1)? "SI":"NO")<< "\n";
		isFree = 0;
	}
}