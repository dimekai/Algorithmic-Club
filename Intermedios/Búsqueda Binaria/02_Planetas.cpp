/* 	
	Author:     Jesús Kaimorts Díaz Medina Date:       
	Date:		August 25th, 2018.
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

/*
	El análisis de este problema usa la función SystemEquilibrated en donde
	se calculará el punto óptimo es a partir de dos puntos de referencia: 
	plantea X y Xi, posicionados a la izquierda y la derecha respectivamente. 
	El punto de equlibro en el que el meteorito se encuentra, para que el sistema
	esté en equilibrio,se denomina para esta función Xp.
*/
D SystemEquilibrated(int planetaX, int planetaXi){
	D Xp = 0.0;
	while(planetaX < planetaXi ){
		
	}
}

int main(){
	USh num_planetas = 0;
	while(cin >> num_planetas){
		if(num_planetas == 0) break;

		vi planetas(num_planetas,0);
		for (int i = 0; i < num_planetas; i++)
			cin >> planetas[i];

		sort(planetas.begin(),planetas.end());

		cout << (num_planetas - 1) << "\n";

		for (int  = 1; i < num_planetas; ++i){
			cout << 
		}

		planetas.clear();
	}

}