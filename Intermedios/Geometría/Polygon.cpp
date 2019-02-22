#include <bits/stdc++.h>
#define mx 1000
using namespace std;

struct Point{
    double x;
    double y;
};

int main(){
    int n, i, j;
    Point p[mx + 5], q;
    while(scanf("%d", &n) == 1 && n) {
        for(i = 0; i < n; i++)
            scanf("%lf %lf", &p[i].x, &p[i].y);
        scanf("%lf %lf", &q.x, &q.y);
        int cnt = 0;
        for(i = 0, j = n-1; i < n; j = i++) {
            if(p[i].y > q.y != p[j].y > q.y && // q.y in [pi.y, pj.y)
               q.x < (p[j].x-p[i].x)*(q.y-p[i].y)/(p[j].y-p[i].y)+p[i].x)
            cnt++;
        }
        puts(cnt&1 ? "T": "F");
    }
    return 0;
}