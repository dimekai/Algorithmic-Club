#include <iostream>
#include <cmath>
using namespace std;

/*...........................
.. 13    12  11  10    25 ...
.. 14  | 3   2   9  |  24 ...
.. 15  | 4   1   8  |  23 ...
.. 16  | 5   6   7  |  22 ...
.. 17    18  19  20    21 ...
.............................*/

int main(){
	unsigned int sz,p;
	long long ring, square_inside,contorno; 
	while(cin>>sz>>p){
		
		if (sz+p==0) break;

		ring = 1;
		while(p > ring*ring) /*Buscamos el anillo donde p está*/
			ring+=2;	   /*Vamos buscando por numeros impares*/	
		
		cout << "ring: " << ring << "\n";

		if(ring==1){
			cout << "Line = " << (sz/2 + 1);
			cout << ", column: "<< (sz/2 + 1) << ".\n";
		}

		square_inside = (ring-2)*(ring-2); /*Es el cuadrado que está dentro del
									       anillo que hemos encontrado.*/

		contorno = (sz-ring)/2;

		cout << "square inside: " << square_inside <<"\n";
		cout << "contorno: " << contorno << "\n";


		cout << "North: " << (square_inside + ring-1) << "\n";
		cout << "West: " << (square_inside + ring-1)  << "-"<< (square_inside + 2*(ring-1)) << "\n";
		cout << "South: " << (square_inside + 2*(ring-1))  <<"-" <<  (square_inside + 3*(ring-1)) << "\n";
	}/*cierra while que lee datos*/
}