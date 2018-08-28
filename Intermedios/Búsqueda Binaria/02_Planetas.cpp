/* 	
	Author:     Jesús Kaimorts Díaz Medina       
	Date:		August 27th, 2018.
	Problem:    Planetas 
	Judge:      OmegaUp 
	Topic:      Binary Search 
	URL:		https://omegaup.com/arena/problem/Planetas#problems 
*/
#include <algorithm>
#include <iostream> 
#include <cmath> 
#include <vector> 
#define MAX_N 1100

using namespace std;
typedef unsigned short USh;
typedef double D;
typedef vector<int> vi;

USh num_planetas = 0;
vi planetas(MAX_N,0);

/*
	El análisis de este problema usa la función SystemEquilibrated en donde
	se calculará el punto óptimo es a partir de dos puntos de referencia: 
	plantea X y Xi, posicionados a la izquierda y la derecha respectivamente. 
	El punto de equlibro en el que el meteorito se encuentra, para que el sistema
	esté en equilibrio,se denomina para esta función Xp.

	El margen de error a contemplar para que el metoro, a pesar de la fuerza
	(gravitacional) que todos los planetas ejerzan sobre éste, no sea mayor como para
	poner al sistema inestable. Entonces tenemos que aplicar la ley de conservación
	de energía para que la suma de todas las fuerzas, ejercidas por los N planetas,
	sea igual con cero para que el sistema esté estable, para ello usaremos la función
	balancedForces, la cuál regresará la suma de todas las fuerzas para encontrar el
	punto estable entre un par de planetas.

	Se está encontrando el punto optimo, en un rango determinado, contemplando los planetas
	para que el meteorito no colisione con un planeta.

*/

D balancedForces(D pointM){
	D sum_forces = 0;
	for (int i = 0; i < num_planetas ; i++)
		sum_forces += 1/fabs(planetas[i]-pointM);

	return sum_forces;
}


D systemEquilibrated(int planetaI, int planetaD){
	D pointEquilibrated = 0.0;
	while(planetaI <= planetaD){
		pointEquilibrated = (planetaI + planetaD)/2;

		if(balancedForces(pointEquilibrated) > 0)	/*El sistema está más cargado a la derecha*/
			planetaD = pointEquilibrated;
		else 										/*El sistema está más cargado a la izquierda*/
			planetaI = pointEquilibrated;
	}
}

int main(){
	while(cin >> num_planetas){
		if(num_planetas == 0) break;

		for (int i = 0; i < num_planetas; i++)
			cin >> planetas[i];

		sort(planetas.begin(),planetas.end());

		cout << (num_planetas - 1) << "\n";

		for (int  = 1; i < num_planetas; ++i){
			cout << fixed << showpoint;
			cout << setprecision(4);
			cout << systemEquilibrated(planetas[i-1],planetas[i])
		}
		planetas.clear();
	}

}