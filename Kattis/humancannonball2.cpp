#include <bits/stdc++.h>
using namespace std;

// The Amazing Human Cannonball

int n;
double v, theta, x1, h1, h2;

int main(){
    cin >> n;
    while(n--){
        cin >> v >> theta >> x1 >> h1 >> h2;
        theta *= M_PI / 180;
        double t = x1 / (v * cos(theta));
        double y = v * t * sin(theta) - 0.5 * 9.81 * t * t;
        cout << ((y >= h1 + 1 && y <= h2 - 1) ? "Safe" : "Not Safe") << endl;
    }
}