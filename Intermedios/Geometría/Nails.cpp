#include <bits/stdc++.h>
#define PI acos(-1.0)
#define MINUS_INF 1e-6
using namespace std;

typedef long long LL;

struct point{
    LL x;
    LL y;
    double angle;
}    p[ 100 + 5],
  hull[ 100 + 5];

double getAngle(LL x, LL y){
    double alpha = atan2(fabs(y), fabs(x));
    return ( ( x >= 0) ? alpha : PI - alpha );
}

bool compare(point a, point b){
    if (fabs (a.angle - b.angle) < MINUS_INF )
        return (a.x * a.x + a.y * a.y) < (b.x * b.x + b.y * b.y);
    return a.angle < b.angle;
}

bool isInRight (point a, point b, point c)
{
    if ( c.x * (a.y - b.y) + c.y * (b.x - a.x) + (a.x * b.y - a.y * b.x) < 0 )
        return true;
    return false;
}

double pow_square(double a){
    return a * a;
}

int main(){
    int casos;
    cin >> casos;

    while(casos--){
        LL initialLength;
        int totalPoints;

        cin >> initialLength >> totalPoints;
        for ( int i = 0; i < totalPoints; i++ )
            cin >> p [i].x >> p [i].y;

        // Si solo hay un punto
        if ( totalPoints == 1 ) {
            printf ("%.5lf\n", (double) initialLength);
            continue;
        }

        int id = 0;
 
        for ( int i = 1; i < totalPoints; i++ )
            if ( p [i].y < p [id].y ) id = i;
 
        swap (p [id], p [0]);
 
        for ( int i = totalPoints - 1; i >= 0; i-- ) {
            p [i].x -= p [0].x;
            p [i].y -= p [0].y;
        }
 
        for ( int i = 1; i < totalPoints; i++ )
            p [i].angle = getAngle(p [i].x, p [i].y);
 
        sort (p + 1, p + totalPoints, compare);
        hull [0] = p [0];
        hull [1] = p [1];
        int top = 1;

        for ( int i = 2; i < totalPoints; i++ ) {
            while (isInRight (hull [top - 1], hull [top], p [i]))
                top--;
            hull [++top] = p [i];
        }
 
        double finalLength = 0;
 
        for ( int i = 1; i <= top; i++ )
            finalLength += sqrt (pow_square(hull [i - 1].x - hull [i].x) + pow_square(hull [i - 1].y - hull [i].y));
 
        finalLength += sqrt (pow_square(hull [top].x - hull [0].x) + pow_square(hull [top].y - hull [0].y));
 
        if ( finalLength < initialLength ) finalLength = initialLength;
 
        printf ("%.5lf\n", finalLength);
    }

    return 0;
}