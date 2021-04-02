#include <bits/stdc++.h>
using namespace std;

// Half a Cookie

double r, x, y;

int main(){
    cout << fixed << setprecision(10);
    while(cin >> r >> x >> y){
        double d = hypot(x, y);
        if(d > r){
            cout << "miss" << endl;
            continue;
        }
        double k = sqrt(r * r - d * d), a = acos(d / r);
        double s1 = a * r * r - d * k, s2 = M_PI * r * r - s1;
        cout << max(s1, s2) << " " << min(s1, s2) << endl;
    }
}