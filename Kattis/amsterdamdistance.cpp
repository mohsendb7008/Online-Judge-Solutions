#include <bits/stdc++.h>
using namespace std;

// Amsterdam Distance

int m, n, ax, ay, bx, by;
double r;

int main(){
    cin >> m >> n >> r >> ax >> ay >> bx >> by;
    double ans = LLONG_MAX;
    for(int c = 0; c <= n; c++){
        double dy = (abs(ay - c) + abs(by - c)) * (r / n);
        double dx = abs(ax - bx) * c * (r /n) * (M_PI / m);
        ans = min(ans, dy + dx);
    }
    cout << fixed << setprecision(10) << ans;
}