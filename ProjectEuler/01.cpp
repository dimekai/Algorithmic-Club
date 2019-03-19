#include <bits/stdc++.h>
#define alpha 1000
using namespace std;

int main(){

    int sum = 0;
    int comun = 0;
    for(int i = 0; i < alpha; i+=3){
        sum += i;
    }
    for(int i = 0; i < alpha; i+=5)
        if(i % 3 == 0) continue;
        else sum += i;

    cout << sum << "\n";

    return 0;
}