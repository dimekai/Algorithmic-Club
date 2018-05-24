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
	while(cin>>sz>>p){
		
		if (sz+p==0) break;
		long long ring, square_inside,rings_less, line, column; 

		ring = 1;
		while(p > ring*ring) /*Buscamos el anillo donde p está*/
			ring+=2;	     /*Vamos buscando por numeros impares*/	
		
		cout << "ring: " << ring << "\n";

		if(ring==1){
			cout << "Line = " << (sz/2 + 1);
			cout << ", column: "<< (sz/2 + 1) << ".\n";
		}

		square_inside = (ring-2)*(ring-2); /*Es el cuadrado que está dentro del
									         anillo que hemos encontrado.*/

		rings_less = (sz-ring)/2;   /*Es el # de anillos que no se contemplaron
		                              en el momento de encontrar el anillo real: ring*/

		cout << "square inside: " << square_inside <<"\n";
		cout << "rings discrimined: " << rings_less << "\n";


		if(p <= (square_inside + ring-1) ){ /*Limite en Esquina Superior-Izquierda*/
			line = square_inside + ring + rings_less - p; /*ya*/
			column = sz - rings_less;

		}else if( p >  (square_inside + ring-1) && /*ya*/
			      p <= (square_inside + 2*(ring-1)) ){ /*Limite de Esquina Superior izquierdo 
			      											     a Esquina inferior izquierda*/
			line = rings_less + 1;
			column = square_inside + 2*(ring-1) + rings_less - p + 1;

		}else if( p > (square_inside + 2*(ring-1)) &&
			      p <= (square_inside + 3*(ring-1)) ){ /*Limite de Esquina inferior izquierda
			      											     a Esquina inferior derecha */
			line = square_inside + 3*(ring-1) + rings_less + 1 - p; /*pendiente*/
			column = rings_less + 1;

		}else{ /*Limite de la Esquina inferior izquierda a la Esquina superior derecha: ring^2*/
			line = sz-rings_less;
			column = square_inside + 3*(ring-1) + 1 + rings_less - p;
		}

	}/*cierra while que lee datos*/
}