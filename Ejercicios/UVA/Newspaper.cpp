#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

int main(){
	pair <short,short> tests_paid;
	int M;
	string sentence = "";
	float total=0;

	while(cin >> tests_paid.first){					
		for (int i = 0; i < tests_paid.first ; i++){	/*# de casos*/
			vector<float> letters(255,0);				/*Todos los caracteres valen 0*/
			cin >> tests_paid.second;  					/*# de letras a pagar*/
			pair <char,float> char_value;				/*caracter-precio*/

			for (int j = 0; j < tests_paid.second; j++){
				cin >> char_value.first >> char_value.second;	
				letters[char_value.first] = char_value.second;	
			}
			
			cin >> M;
			cin.ignore();
			total = 0;
			while(M--) {
            	sentence="";
            	getline(cin,sentence); 
            	for (int k = 0; k < sentence.size(); k++)
            		total += letters[sentence[k]];
			}

			//total /= 100.00;					/*total = total/100*/						
			
			/*cout.setf(ios::fixed);
			cout.setf(ios::showpoint);
			cout.precision(2);*/
			cout << (int)total/100 <<"."<<(int)total%100<<"$"<<"\n"; 
		}//cilerra for de casos
	}//cierra while de casos
}

