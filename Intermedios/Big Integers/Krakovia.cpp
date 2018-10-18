#include <bits/stdc++.h>
using namespace std;

int main(){

    short cases = 0, N, F; 
    while(cin >> N >> F){
        if( N + F == 0) break;

        //uint64_t cost = 0; //for windows
        __int64 cost = 0;
        while( N-- ){
            //uint64_t item = 0;
            __int64 item = 0;
            cin >> item;
            cost += item;
        }

        cout << "Bill #" << ++cases;
        cout <<  " costs " << cost;
        cout << ": each friend should pay ";
        cout << (cost / F ) << "\n";  
    }

    return 0;
}