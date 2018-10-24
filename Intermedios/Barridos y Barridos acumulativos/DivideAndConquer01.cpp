#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef vector<lli> vi;

int main(){
    ios::sync_with_stdio(0); 
	cin.tie(0);
    cout.tie(0);

    int N, i = 0;
    cin >> N;
    vi A(N);
    
    for( ; i < N; i++)
        cin >> A[i];
    
    /*Kadane's Algorithms*/
    lli sum_max = A[0]; 
    lli tmp = A[0];

    for( i = 1; i < N; i++){
        tmp = max(tmp + A[i], A[i]);
        sum_max = max(tmp, sum_max);
    }

    cout << sum_max;
    return 0;
}