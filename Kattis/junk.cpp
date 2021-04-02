#include <bits/stdc++.h>
using namespace std;

// Space Junk

void solve(double a, double b, double g, double h, double& A, double& B, double& C){
    A += a * a + g * g - 2 * a * g;
    B += 2 * a * b - 2 * g * b - 2 * a * h + 2 * g * h;
    C += b * b + h * h - 2 * b * h;
}

int main(){
    cout << fixed << setprecision(3);
    int t;
    cin >> t;
    while(t--){
        int x1, y1, z1, r1, v1x, v1y, v1z;
        cin >> x1 >> y1 >> z1 >> r1 >> v1x >> v1y >> v1z;
        int x2, y2, z2, r2, v2x, v2y, v2z;
        cin >> x2 >> y2 >> z2 >> r2 >> v2x >> v2y >> v2z;
        double A = 0, B = 0, C = - (r1 + r2) * (r1 + r2);
        solve(v1x, x1, v2x, x2, A, B, C);
        solve(v1y, y1, v2y, y2, A, B, C);
        solve(v1z, z1, v2z, z2, A, B, C);
        double ans;
        if(A == 0){
            if(B == 0)
                ans = -1;
            else ans = - C / B;
        }
        else{
            double delta = B * B - 4 * A * C;
            if(delta < 0)
                ans = -1;
            else ans = (- B - sqrt(delta)) / (2 * A);
        }
        if(ans < 0)
            cout << "No collision" << endl;
        else
            cout << ans << endl;
    }
}