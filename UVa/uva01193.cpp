#include <bits/stdc++.h>
using namespace std;

// Radar Installation

int n, d;
pair<double, double> p[1003];
bool wr;

bool cmp(pair<double, double> & p1, pair<double, double> & p2){
    return p1.second < p2.second;
}

int main(){
    int t = 0;
    while(true){
        cin >> n >> d;
        if(n + d == 0)
            break;
        t++;
        wr = false;
        cout << "Case " << t << ": ";
        for(int i = 0; i < n; i++){
            double x, y;
            cin >> x >> y;
            if(y > d)
                wr = true;
            p[i] = {-sqrt(d * d - y * y) + x, sqrt(d * d - y * y) + x};
        }
        if(wr)
            cout << -1 << endl;
        else{
            sort(p, p + n, cmp);
            int ans = 0;
            double last = LLONG_MIN;
            for(int i = 0; i < n; i++)
                if(p[i].first > last){
                    last = p[i].second;
                    ans++;
                }
            
            cout << ans << endl;
        }
    }
}