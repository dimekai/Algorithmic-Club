#include <iostream> 	// cin and cout
#include <utility> 		// pair
#include <vector>		// vector
#include <algorithm>    // sort

using namespace std;

int main(){
	/*
	  NQ.first  -> N: # de mármoles
	  NQ.second -> Q: # de consultas
	 */
	ios::sync_with_stdio(0); 
	cin.tie(0);

	pair<int,int> NQ;
	short Case = 0;  
	while(cin >> NQ.first >> NQ.second){
		if((NQ.first + NQ.second) == 0) break;

		vector<int> Ni(NQ.first,0);		//Ni: # del i-ésimo mármol
										//Qi: # de la i-ésima consulta

		for (int i = 0; i < NQ.first; i++)
			cin >> Ni[i];
		sort(Ni.begin(), Ni.end());		//Ordenando los elementos en Ni

		cout<<"CASE#"<<" "<<++Case<<":"<<"\n";
		/*Inicia la Búsqueda Binaria*/
		for (int i = 0; i < NQ.second; i++){
			int Qi=0;
			cin >> Qi;

			int low = 0, 
			high = Ni.size() - 1, 
			res = -1, 
			middle = 0;

			while(low <= high){
				middle = (low + high)/2;
				if(Ni[middle]<Qi)
					low = middle + 1;
				else{
					high = middle - 1;
					res = middle;
				}
			}

			if(Qi == Ni[res])
				cout<<Qi<<" found at "<<res+1<<'\n';
			else
				cout<<Qi<<" not found"<<'\n';
		}/*Cierra for de # de consultas*/
	}/*Cierra for de # de casos*/
}/*Cierra main*/