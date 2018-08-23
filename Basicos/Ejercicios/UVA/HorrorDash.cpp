#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	ios::sync_with_stdio(0); 
	cin.tie(0);
	short cases;
	while((cin>>cases)){
		for (int i = 1; i <= cases; i++){
			short N, mayor=0,Ci;
			cin >> N;	/*estudiantes*/
			for(int j = 0; j < N; j++){
            	cin >> Ci;
            	mayor = max(mayor,Ci);	/*speed max*/
			}
			cout <<"Case "<< i << ": " << mayor<<"\n";
		}
	}
}