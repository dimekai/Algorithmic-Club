#include <iostream>
#include <utility>
using namespace std;
int main(){
 	int K,N,M,X,Y;
 	
 	
 	while((cin >> K) && K!=0){
 		cin >> N >> M;
 		for(int i=0; i<K; i++){
 			X=0; Y=0;
 			cin >> X >> Y;
 			if ((X == N) || (Y==M)){
 				cout << "divisa" << "\n";
 			}else{
 				if (X>N){
 					if (Y>M)
 						cout << "NE" << "\n";
 					else
 						cout << "SE" << "\n"; 				
 				}else{
 					if (Y>M)
 						cout << "NO" << "\n";
 					else
 						cout << "SO" << "\n"; 	
 				}
 			}
 		}
 	}
 	return 0;
 }