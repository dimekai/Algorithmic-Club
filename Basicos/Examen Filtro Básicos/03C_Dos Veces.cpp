/*@author: */
/*Problema de OmegaUp: C_Dos Veces
URL: https://omegaup.com/arena/problem/Formateando-las-letras*/

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
using namespace std;

int main()
{
	string cadena; /*Se toma también como un arreglo*/
	while( getline(cin,cadena) ){
		for (int i = 0; i < cadena.length(); i++)
			putchar(toupper(cadena[i]));
		cout << "\n";
		for (int i = 0; i < cadena.length(); i++)
			putchar(tolower(cadena[i]));			
		cout << "\n";
	}
	return 0;
}