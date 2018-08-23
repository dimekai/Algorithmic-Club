#include <iostream>
#include <iomanip>
#include <string>
#include <utility>
#include <vector>

using namespace std;
const int K = 105;						/*Numero maximo de caracteres a pagar*/

int main(){
	vector<char> characteres(K,0);
	vector<float> price(K,0);
	pair<short,short> N_K;				/*Casos-#caracteres a pagar*/
	double total = 0.0;			
	string line = "";
	
	cin >> N_K.first;					/*# de casos*/
	for (short i = 0; i < N_K.first; i++){
		total = 0;						/*Inicializo total*/
		cin >> N_K.second;
		for (short j = 0; j < N_K.second; j++)		/*#caracteres a pagar*/
			cin >> characteres[j] >> price[j];
		
		int M;
		cin >> M;						/*# de lineas del texto*/
		cin.ignore();
		while(M--){					/*M numero de lineas*/
			getline(cin,line);
			for (int n = 0; n < line.size(); n++){		/*Recorre la cadena ingresada*/
				for (int p = 0; p < N_K.second; p++){
					if (line[n]==characteres[p])
						total += price[p];
				} /*Cierra for de matcheo: caratcerPago-caracterLinea*/
			}/*termina de leer la i-esima cadena*/
		}/*termina de leer las M lineas*/
		total /= 100;		/*total = total/100;*/
		cout.setf(ios::fixed);
		cout.setf(ios::showpoint);
		cout.precision(2);
		cout << total <<"$"<<"\n";
		characteres.clear();
		price.clear();
	}/*cierra el N-ésimo caso*/
}	