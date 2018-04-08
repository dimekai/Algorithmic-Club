#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
	int N,B,H,W;						/*Linea uno: Datos del viaje*/
	vector<int> minimo;
	while(cin >> N >> B >> H >> W){		/*N: participantes, B: Presupuesto, H: Hoteles, W: Semanas*/
		int p = 0;						/*p: precio personal por semana en el i-ésimo hotel*/
		int a = 0;						/*a: camas disponibles por semana*/
		bool accept;
		minimo.clear();

		for (int i = 0; i < H; i++){
			cin >> p;				    /*p: precio por persona por semana en el hotel i*/
			int cost = N*p;

			for (int j = 0; j < W; j++){	
				accept = true;
				cin >> a;
				if (a < N){				/*Si el número de habitaciones en menor al de personas*/
					accept *= false;
					//continue;
				}
			}//cierra primer for

			if (accept){
				if (B >= (N*p))
					minimo.push_back(cost);
				else
					accept = false;	
			}
		} // cierra segundo for
		sort(minimo.begin() , minimo.end() );

		if (minimo.size()!=0)
			cout << minimo.front() << "\n";
		else
			cout << "stay home" << "\n";  

	}//cierra while
}