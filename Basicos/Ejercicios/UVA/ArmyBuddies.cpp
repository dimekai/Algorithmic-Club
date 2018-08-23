#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>      
using namespace std;


/*void print_izq_der(int *izq, int *der,int S){
	cout << "izq: ";
	for (int i = 1; i <= S; i++)
			cout << izq[i];
	cout << "\nder: ";
	for (int i = 1; i <=S; i++)
			cout << der[i];
	cout << "\n";
}*/


int main(){
	int S=0, B=0;

	while(cin >> S >> B){
		if((S+B)==0) break; 
		
		int izq[S],der[S];
		pair<int,int> query; /* query.first = izq
								query.second = der*/
		for (int i = 1; i <= S; i++)
			izq[i]=i-1, der[i] = i+1;
		
		izq[1] = -1;
		der[S] = -1;

		for (int j = 0; j < B; j++){
			//print_izq_der(izq,der,S);
			cin >> query.first >> query.second; /*query -> Q(izq,der)*/
		
			izq[der[query.second]] = izq[query.first];
		
			if (izq[query.first]!=-1)
				cout << izq[query.first] <<" ";
			else
				cout << "* ";
			
			der[izq[query.first]] = der[query.second];
		
			if (der[query.second]!=-1)
				cout << der[query.second] << "\n";
			else
				cout << "*\n";				
		}
		cout << "-" << "\n";
	}
}