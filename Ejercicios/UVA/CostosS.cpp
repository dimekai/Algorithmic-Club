#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios::sync_with_stdio(0); 
	cin.tie(0);
	int N;
	vector<int> num(3);
	cin >> N;

	for (int i = 1; i <= N; i++){
		cin >> num[0] >> num[1] >> num[2];
		sort(num.begin(), num.end());
		cout << "Case " << i << ": " << num[1] << "\n";
	}
	return 0;
}