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
#include <iomanip>
#include <cmath> 
#include <vector> 
#define MAX 1100

using namespace std;

typedef double D;
typedef vector<D> vd;

int num_planetas;
vd planetas(MAX);
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

	Se está encontrando el punto optimo, en un rango determinado, contemplando los 
	planetas para que el meteorito no colisione con un planeta.
*/

D forcesBalanced(D pointM){
	D sum_forces = 0;
	for(int i = 0; i < num_planetas; i++)
		sum_forces += 1/(planetas[i] - pointM);
	
	return sum_forces;
}


D systemBalanced(D planetaI, D planetaD){
	D point_metheore;
	int cotaMet = 25;
	for(int k = 0; k < cotaMet; k++){
		point_metheore = (planetaI + planetaD) / 2;

		if(forcesBalanced(point_metheore) > 0)
			planetaD = point_metheore;
		else
			planetaI = point_metheore;
	}
	return planetaI;
}

int main(){
	ios::sync_with_stdio(0); 
	cin.tie(0);
	
	while(cin >> num_planetas){
		if (num_planetas == 0) break;
		
		D Pi;		
		for(int j=0; j < num_planetas; j++)
			cin >> Pi, planetas[j] = Pi;

		sort(planetas.begin(), planetas.begin()+num_planetas);

		cout << num_planetas-1 <<"\n";
		
		for(int i=1; i < num_planetas; i++){
			cout << fixed << setprecision(3);
			cout << systemBalanced(planetas[i-1],planetas[i]) << " ";
		}
		cout<<"\n";
	}
}