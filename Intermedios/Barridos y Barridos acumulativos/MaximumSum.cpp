#include <bits/stdc++.h>

using namespace std;


void print(int matrix[][], short N){
    for(int i = 1; i <= N; i++){
        for( int j = 1; j <= N; j++)
            cout << matrix[i][j];
    
        cout << "\n";
    }
}

int main(){
    short N;

    while(cin >> N){

        int matrix[N+1][N+1];
        
        for(int i = 0; i < N; i++){
            for( int j = 0; j < N; j++)
                cin >> matrix[i][j];
        }

        
               
    }

}