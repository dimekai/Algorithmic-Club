#include <iostream>
using namespace std;

int main(){
    int n, m, t, x, y, z;
    cin >> t;
    while(t--){
        cin >> n >> m;
        int ans = 0;
        while(m--) {
            scanf("%d", &x);
            z = 1;
            while(x--)
                scanf("%d", &y), z *= y, z %= n;
            ans += z, ans %= n;
        }
        cout << ans << "\n";
    }
    return 0;
}