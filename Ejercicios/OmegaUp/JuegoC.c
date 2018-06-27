#include <stdio.h>

int main (){
	int N=0,M=0;
	
	scanf("%d %d",&N,&M);

	for(int j=0; j<N;j++){ /*Iterando sobre el i-ésimo caso*/
		int subTotal = 0;
		int b[11]; /*b[0]: Apuesta del jugador
				     b[j]: Valor de la j-ésima carta, jc[1,10]*/
		int val=0;

		for (int i = 0; i < 11; i++)  {
			scanf("%d",&val);
			b[i] = val; /*Leemos la apuesta y los valores de las cartas*/
		}
		
		for (int i = 1; i <= 10; i++){
			subTotal += b[i];
			//cout << "Subtotal: " << subTotal << "\n";
			if(subTotal >= 16){
				if(subTotal != 21){
					//cout << "La casa gana la partida " << j << "\n";
					printf("La casa gana la partida %d\n",j);
					M -= b[0];
					break;
				}
				else if(subTotal == 21){
					//cout << "El jugador gana la partida " << j << "\n";
					printf("El jugador gana la partida %d\n",j);
					M += b[0];
					//cout << "El jugador tiene " << M << " pesos\n";
					break;
				}/*cierra if al ganas*/
			}/*Cierra if para seguir aumentando*/
		}/*cierra for*/
	}/*cierra for de partidas*/
	printf("El jugador tiene %d pesos\n",M);
}