/*Los tacos de juan
OmegaUp: https://omegaup.com/arena/problem/Los-tacos-de-Juan#problems
*/
#include <iostream>
using namespace std;

float const PRECIO_TACO = 10, 
   			PRECIO_ORDEN = 50, 
   			PRECIO_PLATO = 250, 
   			PRECIO_CANASTA = 1500; /*Precios fijos*/
int main(){
   float in_N, 
   		 in_O,
   		 in_P,
   		 in_C;

   c&in_N,&in_O,&in_P,&in_C);

   float num_T, 
   		 num_O,
   		 num_P, 
   		 num_C,
   		 costo_total;

   num_C = in_N/in_C;		in_N = in_N-(num_C*in_C);
   num_P = in_N/in_P;		in_N = in_N-(num_P*in_P);
   num_O = in_N/in_O;		in_N = in_N-(num_O*in_O);

   costo_total = (num_C * PRECIO_CANASTA) + 
   				 (num_P * PRECIO_PLATO) + 
   				 (num_O * PRECIO_ORDEN) + 
   				 (in_N * PRECIO_TACO);                

   printf("%i\n %i %i %i %i", costo_total, in_N, num_O, num_P, num_C);
   return 0;
}