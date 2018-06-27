#include <stdio.h>

int main (){
	int N=0,M=0;
	
	scanf("%d %d",&N,&M);

	for(int j=0; j<N;j++){ /*Iterando sobre el i-ésimo caso*/
		int subTotal = 0;
		int val=0;
		int carta=0;

		for (int i = 0; i < 11; i++)  {
			if (i==0){ /*Es la apuesta*/
				scanf("%d",&val);
				continue;
			}
			scanf("%d",&carta);
			subTotal += carta;
			printf("SubTotal: %d \n",subTotal);
			if(subTotal >= 16){
				if(subTotal != 21){
					//cout << "La casa gana la partida " << j << "\n";
					printf("La casa gana la partida %d\n",j);
					M -= val;
					break;
				}
				else if(subTotal == 21){
					//cout << "El jugador gana la partida " << j << "\n";
					printf("El jugador gana la partida %d\n",j);
					M += val;
					break;
					//cout << "El jugador tiene " << M << " pesos\n";
				}/*cierra if al ganas*/
			}/*Cierra if para seguir aumentando*/
		}/*cierra for*/

	}/*cierra for de partidas*/
	printf("El jugador tiene %d pesos\n",M);
}