#include <iostream>
#include <string>
using namespace std;

int main(){
	int n,p, RFP=0;			/*RFP: Número de caso*/
	string req_pro, name_proposal, best_proposal;
	float compliance = 0.0, cost=0.0, d=0.0;  /*d: precio*/
	int r;									  /*r: # de reqs.*/
	while(cin >> n >> p){	/*Requerimientos y propuestas*/
		cin.ignore();
		if((n+p)==0) break;
		for (int i = 0; i < n; i++)
			cin.ignore(),getline(cin,req_pro);  /*Leemos los requerimientos*/

		for (int j = 0; j < p; j++){ /*Leemos las propuestas*/
			cin.ignore(),getline(cin,name_proposal);
			
			cin >> d >> r;
			
			for (int k = 0; k < r; k++)
				cin.ignore(),getline(cin,req_pro);

			if(((float)(r/p)>compliance) || 
				((float)(r/p)==compliance && d<cost)){
				compliance = (float)(r/p);
				cost = d;					   /*Es el mejor costo encontrado*/
				best_proposal = name_proposal; /*El nombre de la propuesta con mejor costo*/
			}
		}

		cout << "RFP #" << ++RFP << "\n";
		cout << best_proposal << "\n";
		cout << "\n";
	}/*cierra while de requerimientos y propuestas*/
}