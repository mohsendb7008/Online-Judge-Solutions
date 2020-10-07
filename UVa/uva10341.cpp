#include <bits/stdc++.h>
using namespace std;

// Solve It

double p, q, r, s, t, u;

inline double f(double x){
    return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}

int main(){
    cout << fixed << setprecision(4);
    while(cin >> p){
        cin >> q >> r >> s >> t >> u;
        if(f(0) * f(1) > 0){
            cout << "No solution" << endl;
            continue;
        }
        double start = 0, end = 1;
        while(fabs(end - start) > 0.000000001){
            double mid = (start + end) / 2;
            if(f(mid) < 0)
                end = mid;
            else start = mid; 
        }
        cout << start << endl;
    }
}