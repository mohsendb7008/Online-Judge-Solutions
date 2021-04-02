#include <bits/stdc++.h>
using namespace std;

// Darts

double radii[10]{20, 40, 60, 80, 100, 120, 140, 160, 180, 200};

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int ans = 0;
        while(n--){
            double x, y;
            cin >> x >> y;
            double h = hypot(x, y);
            for(int s = 0; s < 10; s++){
                double prevy = (s == 0) ? -1 : radii[s-1];
                double nexty = radii[s];
                if(h > prevy && h <= nexty){
                    ans += 10 - s;
                    break;
                }
            }
        }
        cout << ans << endl;
    }
}