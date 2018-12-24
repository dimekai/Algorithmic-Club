#include <bits/stdc++.h>
#define PI acos(-1.0)
using namespace std;

int main(){
    int casos;
    cin >> casos;
    while(casos--){
        int comandos;
        cin >> comandos;
        double x = 0, y = 0, angle = 0;

        for(int i = 0; i < comandos; i++){
            string comando;
            double m;
            
            cin >> comando >> m;

            if ( comando == "fd" ) {
                x += (m * cos (angle * PI / 180));
                y += (m * sin (angle * PI / 180));
            }
            else if ( comando == "lt" ) {
                angle += m;
                angle = fmod (angle, 360);
            }
            else if ( comando == "rt" ) {
                angle -= m;
                angle = fmod (angle, 360);
            }
            else {
                x -= (m * cos (angle * PI / 180));
                y -= (m * sin (angle * PI / 180));
            }
        }
        printf ("%0.lf\n", sqrt (x * x + y * y));
    }
    return 0;
}