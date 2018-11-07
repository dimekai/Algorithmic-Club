#include <bits/stdc++.h>
#define MAX 31000

using namespace std;

typedef vector<int> vi;

int C, N; 
int collar[MAX];

int main(){
    int i , j , tmp = 0, mejor = 100000;
    cin >> C >> N;
        
    for( i = 0; i < N; i++){
        cin >> collar[i];
        collar[i + N] = collar[i];
    }


    return 0;
}