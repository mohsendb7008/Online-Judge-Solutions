#include <bits/stdc++.h>
using namespace std;

// Zipline

int n;
double w, g, h, r;

int main(){
    cout << fixed;
    cout << setprecision(8);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> w >> g >> h >> r;
        if(g == r && h == r){
            cout << w << " " << w << endl;
            continue;
        }  
        if(g > h) swap(g, h);
        cout << sqrt((h-g) * (h-g) + w * w) << " ";
        double x = ((g-r) * w) / (g + h - 2*r);
        double y = w - x;
        cout << sqrt(x * x + (g-r) * (g-r)) + sqrt(y * y + (h-r) * (h-r)) << endl;
    }
}