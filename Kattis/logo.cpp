#include <bits/stdc++.h>
using namespace std;

// Logo

#define EPS 1e-9

inline double deg_to_rad(double deg){
    return (deg * M_PI) / 180; 
}

int m, n, theta, l, ans;
double x, y, res;
string c;

int main(){
    cin >> m;
    while(m--){
        cin >> n;
        x = y = theta = 0;
        while(n--){
            cin >> c >> l;
            if(c == "lt")
                theta = (theta + l) % 360;
            else if(c == "rt")
                theta = (theta - l + 360) % 360;
            else if(c == "fd")
                x += l * cos(deg_to_rad(theta)), y += l * sin(deg_to_rad(theta));
            else
                x -= l * cos(deg_to_rad(theta)), y -= l * sin(deg_to_rad(theta)); 
        }
        res = hypot(x, y);
        ans = static_cast<int>(res + EPS);
        if(res - ans <= ans + 1 - res)
            cout << ans << endl;
        else
            cout << ans + 1 << endl;
    }
}