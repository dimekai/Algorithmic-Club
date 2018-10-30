/*
    Manipulación básica de bits con
    las compuertas de AND, OR, XOR, NOT
    >> (corrimiento a la derecha) y 
    << (corrimiento a la izquierda) 

*/

#include <iostream>
using namespace std;

int main(){
    int A[] = { 0, 1, 3, 4, 5,
                6, 7, 8, 9, 10 };
    int B[] = { 4, 6, 1, 3, 7,
                9, 5, 8, 10, 0 };

    int cota;
    cin >> cota;

    cout << "====== BITWISE AND & ======\n";
    /* ==== BITWISE AND & ===*/
    for(int i = 0; i < cota; i++){
        for(int j = 0; j < cota; j++){
            cout << "(" << A[i] << " & " << B[j] << "): ";
            cout << (A[i] & B[j]) << "\n";
        }
        cout << "________\n";
    }

    cout << "====== BITWISE OR | ======\n";
    /* ==== BITWISE OR | === */
    for(int i = 0; i < cota; i++){
        for(int j = 0; j < cota; j++){
            cout << "(" << A[i] << " | " << B[j] << "): ";
            cout << (A[i] | B[j]) << "\n";
        }
        cout << "________\n";
    }

    cout << "====== BITWISE XOR ^ ======\n";
    /* ==== BITWISE XOR ^ === */
    for(int i = 0; i < cota; i++){
        for(int j = 0; j < cota; j++){
            cout << "(" << A[i] << " ^ " << B[j] << "): ";
            cout << (A[i] ^ B[j]) << "\n";
        }
        cout << "________\n";
    }

    /* ==== BITWISE XOR ^ === */
    for(int i = 0; i < cota; i++){
        for(int j = 0; j < cota; j++){
            cout << "(" << A[i] << " ^ " << B[j] << "): ";
            cout << (A[i] ^ B[j]) << "\n";
        }
        cout << "________\n";
    }

    cout << "====== LEFT SHIFT << ======\n";
    int x, y;
    cin >> x >> y;
    cout << x << " << " << y << ": " << (x << y) << "\n";
    

    cout << "====== RIGHT SHIFT << ======\n";
    int m, n;
    cin >> m >> n;   
    cout << m << " >> " << n << ": " << (m >> n) << "\n";
    
    cout << "====== NOT ~ << ======\n";
    int p;
    cin >> p;
    cout << "~" << p << ": " << (~p) << "\n";

}