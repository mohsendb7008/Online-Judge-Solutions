#include <bits/stdc++.h>
using namespace std;

// Reconnaissance

int n;
double x[100003], v[100003];

double f(double t){
    double mi = LLONG_MAX, ma = LLONG_MIN;
    for(int i = 0; i < n; i++){
        double nx = v[i] * t + x[i];
        mi = min(mi, nx);
        ma = max(ma, nx);
    }
    return ma - mi;
}

int judge(double t){
    double a = f(t - 0.00001), b = f(t), c = f(t + 0.00001);
    if(b < a && b > c)
        return 2;
    else if(b > a && b < c)
        return 3;
    return 1;
}

int main(){
    cout << fixed << setprecision(4);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> x[i] >> v[i];
    double start = 0, end = 200000, ans;
    while(fabs(end - start) > 0.000000001){
        ans = (start + end) / 2;
        int r = judge(ans);
        if(r == 1)
            break;
        if(r == 2)
            start = ans;
        else end = ans;
    }
    cout << f(ans) << endl;
}