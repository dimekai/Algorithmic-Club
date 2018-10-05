#include <bits/stdc++.h>
using namespace std;

string x;
string y = "1000000";

int main(){
	cin >> x;
	if (next_permutation(x.begin(), x.end()))
		cout << x << "\n";
	else
		cout << 0 << "\n";

	return 0;
}