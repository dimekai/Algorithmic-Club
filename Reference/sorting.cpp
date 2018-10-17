#include <bits/stdc++.h>
#define GetSize(array) (sizeof(array) / sizeof(*(array)))
using namespace std;

typedef vector<int> vi;
typedef vector<float> vf;


/*
    |========== BUCKET SORT ==========|
    @param array[] : Arreglo a ordenar
    @param n:   Longitud del arreglo a ordenar
    @resource   : https://www.youtube.com/watch?v=VuXbEb5ywrU
*/
float * bucketSort(float array[], int n){
    
    vf bucket[n]; //Se crea la cubeta con la longitud del arreglo desordenado
    float * sorted;

    /* Se colocan los elementos del arreglo en distintas cubetas */
    for (int i = 0; i < n ; i++){
        int Bi = n * array[i];
        bucket[Bi].push_back( array[i] );
    }

    /* Se ordena cada cubeta de manera individual: Usando Insertion Sort */
    for (int j = 0; j < n ; j++)
        sort( bucket[j].begin(), bucket[j].end() );

    /* Se concatenan todas las cubetas al arreglo original : array[] */
    int index = 0;
    for (int k = 0; k < n; k++){
        for( int l = 0; l < bucket[k].size(); l++){ //Recorro cada cubeta y las voy enlazando.
            sorted[ index++ ] = bucket[k][l];
        }
    }

    return sorted;
}

/*
    |========== COUNTING SORT ==========|
    Es una técnica basada en llaves entre un rango especifico
    @param array[] : Arreglo a ordenar
    @param n:   Longitud del arreglo a ordenar
    @resource   : https://www.youtube.com/watch?v=VuXbEb5ywrU
*/


int main(){
    float array[] = { .13, .53, 0.12, .90, .82, .45, .91, .70};
    int n = GetSize(array);
    float * sorted;
    
    cout << "Tam : " << n << "\n";
    cout << "Unsorted: [";
    
    for( auto x : array)
        cout << x << ", ";
    cout << "]\n";

    //sorted = bucketSort(array, n);

    cout << "Sorted: [ ";
    
    for( int i = 0; i < n ; i++)
        cout << sorted[i] << " ";
    cout << "]\n";

    return 0;
}