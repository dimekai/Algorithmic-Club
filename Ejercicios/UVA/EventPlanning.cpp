#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
	int N,B,H,W;						/*Linea uno: Datos del viaje*/
	vector<int> minimo;
	while(cin >> N >> B >> H >> W){		/*N: participantes, B: Presupuesto, H: Hoteles, W: Semanas*/
		minimo.clear();
		for (int i = 0; i < H; i++){
			int p = 0;						/*p: precio personal por semana en el i-ésimo hotel*/
			cin >> p;				    /*p: precio por persona por semana en el hotel i*/
			int cost = N*p;

			for (int j = 0; j < W; j++){
				int a = 0;						/*a: camas disponibles por semana*/	
				cin >> a;
				if (a >= N){				/*Si el número de habitaciones en menor al de personas*/
					if (B >= (N*p)){
						minimo.push_back(cost);
					}
				}
			}//cierra primer for
		} // cierra segundo for

		sort(minimo.begin() , minimo.end() );

		if (minimo.size()!=0)
			cout << minimo.front() << "\n";
		else
			cout << "stay home" << "\n";  

	}//cierra while
}