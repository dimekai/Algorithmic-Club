/*
@date:		October 6th, 2018.
@author:	Jesús Díaz
@problem:	Write a function that takes an unsigned integer
			and returns the number of 1 bits it has.
@topic:		Bits manipulation.
*/

#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ulli;

/*CodeLab Solution*/
int convert2(ulli number){
	int my_counter = 0;
	while( number != 0 ){
		number = number & (number - 1);
		my_counter++;
	}
	return my_counter;
}

int convert(ulli number){
	int my_counter = 0;

	while(number != 0){
		my_counter += (number & 1);
		number >>= 1;
	}
	return my_counter;
}

int main(){
	ulli x;
	while(cin >> x)
		cout << convert(x);
	return 0;
}
