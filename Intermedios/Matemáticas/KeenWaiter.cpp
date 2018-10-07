#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef vector<int> vi;

void calculate(short N, vi & nums){
	nums.resize(N+1,0);

	int i = 0;
	for(i = 0; i <= N ; i++)
		nums[i] = N-i;
	
	i = 0;
	cout << "\n";
	while(nums[i] != 1){
		string mayor = to_string(nums[i]);
		string menor = to_string(nums[i+1]);
		cout << "Mayor: " << mayor <<  "\nMenor: " << menor <<"\n";
		i++;
	}
}

int main(){
	short N;
	int casos;
	cin >> casos;
	while(casos--){
		cin >> N;
		vi nums;
		calculate(N, nums);
	}
	return 0;
}