#include <iostream>
#include <vector>
#include <cmath>
#define L long long

using namespace std;
/*Se toma 10^5, ya que al tomar la cota más grande que es
10^9 y sacar la raiz para ver que X satisface la desigualdad
de X^2 <= 10^9, X -> 32,000. Por ello se toman 5 ceros*/

/*La función >> buscarY << nos ayudará a encontrar el número triangular
que hace que la ecuación con la siguiente desigualdad se cumpla:
						Y = N - Xi
En el cual utilizaremos una busqueda binaria, dentro del arreglo,
para ver qué número satisface la ecuación. Si Y existe, entonces
si existe la pareja de números triangulares que satisfacen:

					N = X + Y = f(x) + f(y) 
*/
bool buscarY(vector<L> NT, L Y){
	L low = 1,
	  high = NT.size()-1,
	  middle = 0,
	  guess = 0;
 
	while(low <= high){
		middle = (low+high)/2;

		cout << "low: " << low <<"\n";
		cout << "high: " << high <<"\n";
		cout << "middle: " << middle <<"\n";
		cout << "NT[" << middle << "]: " << NT[middle] <<"\n";

		if (NT[middle] == Y)
			return true;
		else if (NT[middle] > Y)
			high = middle - 1;
		else
			low = middle + 1;
	}
	return false;
}

int main(){
	ios::sync_with_stdio(0); 
	cin.tie(0);

	L n;									/*Este será el numero a evaluar*/
	cin >> n;								/*Leyendo el numero a evaluar*/
	L const COTA = sqrt(2*n) + 1; 
	vector<L> triangularNumbers(COTA,0);		/*Aqui van los sqrt(n) numeros triangulares*/

	triangularNumbers[0] = 0;
	//cout << "# Triangulares < "<< n << ": \n";
	for (int i = 1; i < COTA; i++){
		triangularNumbers[i] = triangularNumbers[i-1] + i;	/*Calculo del i-ésimo número triangular*/
		//cout << triangularNumbers[i] << ",";
	}
	
	for (int j = 1; j < COTA; j++){
		/*cout << "BUSCAR CON: \nX : " << triangularNumbers[j] <<"\n";
		cout << "N-X: " << n - triangularNumbers[j]<<"\n";
		cout << "_______\n";*/
		if(((n- triangularNumbers[j])<n) && buscarY(triangularNumbers, n - triangularNumbers[j])){  /* X = triangularNumbers[j]*/
			cout << "YES" <<"\n";
			return 0;
		}
	}

	cout << "NO" << "\n";
	return 0;
}

