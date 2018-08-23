#include <iostream>

using namespace std;

bool dobleces(char a ,char b,char c);

int main(){
	long L=0;
	char doblez[3]; /*"+letra : [0]="+/-", [1]=x,y o z"*/

	while(cin >> L && L!=0){
		int signo_actual = 1;  /*representa +*/
		char punto_fijo = 'x'; /*Siempre habra un punto fijo y se recorrerá*/
	
		--L;
		for (int i = 0; i < L; ++i){
			cin >> doblez;
			if (doblez[0] == 'N') continue;

			if (dobleces(punto_fijo,doblez[0],doblez[1]))
				signo_actual = -signo_actual;
			
			if (punto_fijo=='x')
				punto_fijo = doblez[1];
			else if(punto_fijo == 'y' && doblez[1] == 'y') 
				punto_fijo = 'x';
			else if (punto_fijo == 'z' && doblez[1] == 'z')
				punto_fijo = 'x';
		}//cierra for

		char signo_final = (signo_actual==1)?'+':'-';
		cout << signo_final << punto_fijo << "\n";
	}//cierra while
}//cierra main

bool dobleces(char actual, char signo, char doblez){
	bool on_x = actual=='x' && signo=='-';
	bool on_y = actual=='y' && doblez=='y' && signo=='+';
	bool on_z = actual=='z' && doblez=='z' && signo=='+';
	if (on_x || on_y || on_z)
		return true;
	return false;	
}