#include <iostream>		/*cout y cin*/
#include <algorithm>    /*función sort*/
#include <vector>		/*vector*/
#include <cmath>		/*abs*/
using namespace std;
/*Author: Jesús Kaimorts D.M
Problema: Jolly Jumpers
Juez:	UVA Judge
Ejercicio: 10038 - Jolly Jumpers*/

short N;
int main(){
	bool is;
	while(cin >> N){
		is = true;
		vector<int> element(N,0);
		vector<int> jollys(N-1,0);

		for (int i = 0; i < N; i++)
			cin >> element[i];

		for (int j = 0; j < N-1; j++)
			jollys[j] = abs(element[j+1]-element[j]);

		/*jollys[j] = abs(element[j]-element[j+1]);   : Desigualdad del triágulo*/
			
		sort(jollys.begin(),jollys.begin()+N-1);

		for (int i = 0; i < N-1; i++){
			if (jollys[i]!=(i+1))
				is *= false;
		}  

		if (is)
			cout << "Jolly" << "\n";
		else
			cout << "Not jolly" << "\n";
	}	
}