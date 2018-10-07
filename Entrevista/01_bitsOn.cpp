#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ulli;

int convert(ulli number){
	int my_counter = 0;

	while(number != 1){
		number /= 2;
		my_counter++;
	}

	return my_counter;
}

int main(){
	ulli x;
	while(cin >> x)
		cout << convert(x);
	return 0;
}
