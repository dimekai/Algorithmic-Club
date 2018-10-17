/*
@date:		October 17th, 2018.
@author:	Jesús Díaz
@problem:	Given a string s consists of upper/lower-case alphabets
            and empty space characters ' ', return the length of
            last word in the string.

            If the last word does not exist, return 0

            Note: A word is defined as a character 
                  sequence consists of non-space characters only.

@topic:		Strings.

*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    string cadena = " ";
    
    while( getline(cin,cadena) ){
        int n, count;
        n = cadena.length();
        int i, flag = 0;

        count = 0;
        for( i = n; i >= 0; i--){
            cout << "cadena [" << i << "] : " << cadena[i] << "\n";
            if((cadena[i]>='a' && cadena[i]<='z') || (cadena[i]>='A' && cadena[i]<='Z')){
                count += 1; flag = 1;
            }else{
                if(flag) break;
            }
        }
        cout << count << "\n";  
    }
    return 0;   
}