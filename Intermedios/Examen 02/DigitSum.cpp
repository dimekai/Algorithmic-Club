#include <bits/stdc++.h>
using namespace std;

int sumDigit(int n){
    int sum = 0;
    for (sum = 0; n > 0; sum += n % 10, n /= 10); 
    return sum;
}

int main(){
    int n, min_sum = 1e7;
    cin >> n;
    for(int i = 1; i <= n/2; i++){
        int A = sumDigit(i);
        int B = sumDigit(n-i);
        min_sum = min(min_sum,A+B);
    }
    cout << min_sum << "\n";

    return 0;
}
