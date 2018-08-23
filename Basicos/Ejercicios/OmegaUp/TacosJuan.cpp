/*Los tacos de juan
OmegaUp: https://omegaup.com/arena/problem/Los-tacos-de-Juan#problems
*/
#include <iostream>
using namespace std;

int const PRECIO_TACO = 10, 
   		  PRECIO_ORDEN = 50, 
   		  PRECIO_PLATO = 250, 
   		  PRECIO_CANASTA = 1500; /*Precios fijos*/
int main(){
   int in_N,
   	   in_O,
   	   in_P,
   	   in_C;

    while(cin >> in_N >> in_O >> in_P >> in_C){
   		int num_T=0, 
   			   num_O=0,
   			   num_P=0, 
   			   num_C=0,
   			   costo_total=0;
		
   		num_C = in_N/in_C;	    costo_total += num_C*PRECIO_CANASTA;	
   		in_N = in_N-(num_C*in_C);
		
   		/*cout << "costo: " << costo_total << "\n";
   		cout << "N now: " << in_N << "\n";
   		cout << "Canastas: " << num_C << "\n";
   		cout << "____\n";*/

   		num_P = in_N/in_P;		costo_total += num_P*PRECIO_PLATO;
   		in_N = in_N-(num_P*in_P);

   		/*cout << "costo: " << costo_total << "\n";
   		cout << "N now: " << in_N << "\n";
   		cout << "Platos: " << num_P << "\n";
   		cout << "____\n";*/

   		num_O = in_N/in_O;		costo_total += num_O*PRECIO_ORDEN;
   		in_N = in_N-(num_O*in_O);

   		/*cout << "costo: " << costo_total << "\n";
   		cout << "N now: " << in_N << "\n";
   		cout << "Ordenes: " << num_O << "\n";
   		cout << "____\n";*/

   		costo_total += (in_N * PRECIO_TACO);                

   		cout << costo_total << "\n" << in_N << " "
   							        << num_O << " "
   							        << num_P << " "
   							        << num_C;
   	}
   	return 0;
}