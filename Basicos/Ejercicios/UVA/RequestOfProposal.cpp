#include <iostream>
#include <string>
using namespace std;

int main(){
	int n,p, RFP=0;			/*RFP: Número de caso*/
	string req_pro, name_proposal, best_proposal;
	float compliance = 0.0, cost=20000000000.0, d=0.0;  /*d: precio*/
	int r;									  /*r: # de reqs.*/
	while(cin >> n >> p){	/*Requerimientos y propuestas*/
		if((n+p)==0) break;
		RFP++;
		cin.ignore();
		for (int i = 0; i < n; i++)
			getline(cin,req_pro);  /*Leemos los requerimientos*/

		for(int k=0;k<p;k++){ 
			getline(cin,name_proposal);/*Leemos las propuestas*/
			
			cin >> d >> r;
			cin.ignore();
			for (int k = 0; k < r; k++)
				getline(cin,req_pro);

			if(((float)(r/p)>compliance) || 
				((float)(r/p)==compliance && (d<cost || cost==0))){
				compliance = (float)(r/p);
				cost = d;					   /*Es el mejor costo encontrado*/
				best_proposal = name_proposal; /*El nombre de la propuesta con mejor costo*/
			}
		}
		if (RFP>=2)
			cout << "\n";
		cout << "RFP #" << RFP << "\n";
		cout << best_proposal << "\n";
	}/*cierra while de requerimientos y propuestas*/
}