#include <bits/stdc++.h>
using namespace std;

// Internal Rate of Return

int T;
double c[13];

inline double f(double x){
    double ans = c[0];
    double denominator = 1+x;
    for(int i = 1; i < T; i++){
        ans += c[i] / denominator;
        denominator *= (1+x);
    }
    return ans;
}

int main(){
    cout << fixed << setprecision(2);
    while(1){
        cin >> T;
        if(!T)
            break;
        T++;
        for(int i = 0; i < T; i++)
            cin >> c[i];
        double start = -1;
        double end = LLONG_MAX;
        while(fabs(end-start) > 0.000000001){
            double mid = (start + end) / 2;
            if(f(mid) <= 0)
                end = mid;
            else
                start = mid;
        }
        cout << start << endl;
    }
}