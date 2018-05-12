#include <iostream>
using namespace std;
/*H: Altura del pozo (en pies)
  U: Distancia que escala en un dia el caracol (en pies)
  D: Distancia que baja en una noche el caracol (en pies)
  F: Factor de fatiga (en porcentaje)
*/
int main() {
	double H,U,D,F;
	while(cin >> H >> U >> D >> F && H!=0){
		int days = 0;
		double altura_actual = 0;
		double fatiga = (F/100)*U;

		while(true){
			days++;
			if(U>0) 
				altura_actual += U;	/*El caracol sube*/
            U -= fatiga;			/*El caracol se cansa*/
            if(altura_actual>H)
                break;
            altura_actual -= D;		/*El caracol baja en la noche*/
            if(altura_actual<0)
                break;
		}
		(altura_actual>=0)?cout << "success on day "<< days<<"\n":cout << "failure on day "<< days<<"\n";
	}
  return 0;
}
