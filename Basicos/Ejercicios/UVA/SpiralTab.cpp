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
	long long sz,p;
	while(cin>>sz>>p){
		
		if (sz+p==0) break;
		long long ring, square_inside,rings_less, line, column; 

		ring = 1;
		while(p > ring*ring) /*Buscamos el anillo donde p está*/
			ring+=2;	     /*Vamos buscando por numeros impares*/	
		
		//cout << "ring: " << ring << "\n";

		if(ring==1){
			cout << "Line = " << (sz/2)+1 << ", column = " << (sz/2)+1 << ".\n";
			continue;
		}

		square_inside = (ring-2)*(ring-2); /*Es el cuadrado que está dentro del
									         anillo que hemos encontrado.*/

		rings_less = (sz-ring)/2;   /*Es el # de anillos que no se contemplaron
		                              en el momento de encontrar el anillo real: ring*/

		/*cout << "square inside: " << square_inside <<"\n";
		cout << "rings discrimined: " << rings_less << "\n";*/


		if(p <= (square_inside + ring-1) ){ /*Limite en Esquina Superior-Izquierda*/
			line = sz - rings_less;
			column = square_inside + ring + rings_less - p; 

		}else if( (square_inside + ring-1) < p && 
			      p <= (square_inside + 2*(ring-1)) ){ /*Limite de Esquina Superior izquierdo 
			      											     a Esquina inferior izquierda*/
			line = square_inside + 2*(ring-1) + rings_less - p + 1;
			column = rings_less + 1;

		}else if( (square_inside + 2*(ring-1)) < p &&
			      p <= (square_inside + 3*(ring-1)) ){ /*Limite de Esquina inferior izquierda
			      											     a Esquina inferior derecha */
			line = rings_less + 1;
			column = p - (square_inside + 2*(ring-1)) + rings_less + 1;

		}else{ /*Limite de la Esquina inferior izquierda a la Esquina superior derecha: ring^2*/
			line = p - (square_inside + 3*(ring-1)) + 1 + rings_less;
			column = sz-rings_less;
		}

		cout << "Line = " << line << ", column = " << column << ".\n";

	}/*cierra while que lee datos*/
}