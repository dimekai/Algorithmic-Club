#include <bits/stdc++.h>
using namespace std;

int y = 1000000;
int x = 0, n = 0;
int arr[10];

int main(){
	cin >> x;
	int cpy_x = x;
	while(cpy_x > 0){
		arr[n] = cpy_x%10;
		cpy_x /= 10;
		n++;
	}

	sort(arr, arr+n);

	while(next_permutation(arr, arr+n)){ //Prueba las permutaciones
		int possible_y = 0, pot_diez = 0;

		/*Formamos un posible_y*/
		for(int j = n-1; j >= ; i--){
			possible_y += arr[j]*pot_diez;
			pot_diez *= 10;
		}
		if(possible_y < y)
			y = min(y, possible_y);  //Guarda el mejor
	}

	cout << (y==1000000)? 0 : y << "\n";
}