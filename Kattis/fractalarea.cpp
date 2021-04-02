#include <bits/stdc++.h>
using namespace std;

// Fractal Area

int t, n;
double r;

int main(){
    cout << fixed << setprecision(7);
    cin >> t;
    while(t--){
        cin >> r >> n;
        if(n == 1)
            cout << M_PI * r * r << endl;
        else if(n == 2)
            cout << 2 * M_PI * r * r << endl;
        else{
            double ans = 2 * M_PI * r * r;
            int it = n - 2;
            r /= 2;
            double c = 4;
            while(it--){
                r /= 2;
                c *= 3;
                ans += c * M_PI * r * r;
            }
            cout << ans << endl;
        }
    }
}