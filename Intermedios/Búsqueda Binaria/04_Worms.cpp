/*
Author:		Jesús Kaimorts Díaz Medina
Date:		August 25th, 2018.
Problem:	B. Worms  
Judge:		Codeforces
Topic:		Binary Search
URL:		http://codeforces.com/problemset/problem/474/B
*/
#include <iostream>
#include <vector>
#define MAX_WORMS 1e6

using namespace std;

typedef vector<int> vi;
int main(){
	int n=0,a=0;
	cin >> n;
	vi top_piles(MAX_WORMS,0);
	top_piles[0] = 0;

	for(int j=0; j < n ; j++){
		cin >> a;
		top_piles[j+1] = top_piles[j] + a;
		//cout << j+1 <<"th Top: " << top_piles.at(j+1) << "\n"; 
	}

	int m=0,juicy=0;
	cin >> m;
	while(m--){
		cin >> juicy;
		//cout << "Juicy " << m+1 << "th: " << juicy << "\n";

		int low = 1, 
			high = n,
			middle=0, thisPile=0;
		
		/*cout << "Low: \t" << low << "\n";
		cout << "High: \t" << high <<"\n";*/
		while(low <= high){
			middle = (low+high)/2;
			//cout << "Middle Pile: \t" << middle << "\n";
			if(juicy > top_piles[middle]){
				low  = middle + 1;
				//cout << "Pile: " << middle << "\n"; 
			}
			else{
				high = middle - 1;
				//cout << "Pile: " << middle << "\n";
				thisPile = middle;
			}
		}
		//cout << "Juicy is in "<<thisPile<<"th pile.\n___\n";
		cout << thisPile << "\n";
	}

	top_piles.clear();
	return 0;
}