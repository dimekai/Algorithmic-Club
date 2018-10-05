#include <iostream>
#include <cmath>

using namespace std;
typedef long long int lli;

template<typename T>
T GCD(T a, T b){
	return b?GCD(b,a%b):a;
}

template<typename T>
T function_tau(T gcd){
	lli tau = 1, pot = 0;	/*https://es.wikipedia.org/wiki/Función_divisor*/
	/*Hacer la optmización del factor primo 2 viendo la 
	potencia máxima de éste, dividiendo entre 2 el gcd*/
	while((gcd & 1) == 0){
		gcd >>= 1; /*Dividir entre 2*/
		pot++;
	}
	tau *= (pot + 1); /*Esta es la función Tau para el factor primo 2*/

	/*Verifico los factores primos (todos impares ya) del gcd
	y obtengo las potencias máximas de ese factor primo*/
	for(lli i = 3; i <= sqrt(gcd) ; i += 2){
		pot = 0;
		while( gcd % i == 0){
			gcd /= i;
			pot++;
		}
		tau *= (pot + 1); /*Esta es la función Tau para 
							los demás factores primos*/
	}
				
	if(gcd > 1)
		tau *= 2; /*Función Tau para algun factor sobrante*/

	return tau;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	lli  A,B;
	while(cin >> A >> B){
		auto gcd = GCD(A,B);
		cout << function_tau(gcd) << "\n";
	}
}