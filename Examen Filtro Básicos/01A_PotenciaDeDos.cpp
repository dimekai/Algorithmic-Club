/*@author */
/*Problema de OmegaUp: A_Potencia de Dos
URL: https://omegaup.com/arena/problem/ptwo*/
#include <iostream>
#include <iomainp>

using namespace std;

int main()
{
	int exp=0;
	double n = 1;
	cin >> exp;
	for (i = 0; i < exp; i++)
		n*=2;

	cout << setprecision(80) << n;
	return 0;
}