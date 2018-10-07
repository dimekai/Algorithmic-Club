/*
  @date: 	October 6th, 2018
  @author:  Jesus Díaz.
  @problem:	Write a function that takes an unsigned integer
  			and returns the number of 1 bits it has.
  @topic:	Bits manipulations.
*/


#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ulli;

/*CodeLab solution*/
int convert2(ulli number){
	ulli cont = 0;

	while(number != 0){
		cout << "number: " << number << "\t";
		number = number & (number-1);
		cout << "&number: " << number << "\n";
		cont++;
	}

	return cont;
}

int convert(ulli number){
	int cont = 0;
	while( number != 0 ){
		cont += (number&1); //Hace un AND logico con el numero
		number >>= 1; //Divido entre 2
	}
	return cont;
}

int main(){
	ulli x;
	while(cin >> x){
		cout << convert(x) <<"\n";
		cout << convert2(x) << "\n";
	}
	return 0;
}
