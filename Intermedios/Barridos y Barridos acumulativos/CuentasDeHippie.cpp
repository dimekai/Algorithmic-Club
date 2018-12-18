#include <bits/stdc++.h>
#define MAX 61100
#define BEST 100000

using namespace std;

typedef vector<int> vi;

int C, N; 
int collar[MAX];

int main(){
    int i , j , tmp = 0, mejor = BEST;
    cin >> C >> N;
        
    for( i = 0; i < N; i++){
        cin >> collar[i];
        collar[i + N] = collar[i];
    }

    /*Hago el collar de manera circular*/
    N *= 2;
    for(i = 0, j = 0; i < N; i++){
        for(; tmp < C && j < N; j++)
            if(!collar[j]) tmp++;
        
        if (tmp == C && j - i - C < mejor)
			mejor = j - i - C;

		if (!collar[i]) tmp--;
    }
    cout << mejor << "\n";
    return 0;
}