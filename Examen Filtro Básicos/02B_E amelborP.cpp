/*@author: */
/*Problema de OmegaUp: B_E amelborP
URL: https://omegaup.com/arena/problem/E-amelborP*/
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	string cadena; /*Se toma también como un arreglo*/
	string anedac="";

	while( getline(cin,cadena) ){
		/*Imprimará solamente el primer caracter de cadena*/
		
		for (int i = (cadena.length()-1); i>=0 ; i--)
			cout << cadena[i] ;

		cout << "\n";
	}
	return 0;
}