#include <bits/stdc++.h>
using namespace std;

// Careful Ascent

double x0, y00;
int n;
pair<pair<double, double>, double> s[103];

double judge(double v){
    double x = 0, y = 0;
    for(int i = 0; i < n; i++){
        if(y < s[i].first.first){
            double t = s[i].first.first - y;
            x += v * t;
        }
        double t = s[i].first.second - s[i].first.first;
        x += t * s[i].second * v;
        y = s[i].first.second;
    }
    double t = y00 - y;
    x += v * t;
    return x - x0;
}

int main(){
    cin >> x0 >> y00;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> s[i].first.first >> s[i].first.second >> s[i].second;
    sort(s, s + n);
    double l = -LLONG_MAX, r = LLONG_MAX, mid;
    while(fabs(r - l) > 1e-9){
        mid = (l + r) / 2;
        double ans = judge(mid);
        if(fabs(ans) <= 1e-9)
            break;
        else if(ans > 0)
            r = mid;
        else
            l = mid;
    }
    cout << fixed << setprecision(8) << mid << endl;
}