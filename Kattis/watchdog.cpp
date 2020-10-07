#include <bits/stdc++.h>
using namespace std;

// Watchdog

int s, h, x[53], y[53]; 
bool hatch[43][43];

int main(){
    int n;
    cin >> n;
    while(n--){
        cin >> s >> h;
        for(int i = 0; i <= s; i++)
            for(int j = 0; j <= s; j++)
                hatch[i][j] = 0;
        for(int i = 0; i < h; i++)
            cin >> x[i] >> y[i], hatch[x[i]][y[i]] = 1;
        bool ans = 0;
        for(int i = 0; i <= s; i++){
            if(ans)
                break;
            for(int j = 0; j <= s; j++)
                if(!hatch[i][j]){
                    double r = INT_MIN;
                    for(int k = 0; k < h; k++)
                        r = max(r, hypot(i - x[k], j - y[k]));
                    if(i - r >= 0 && i + r <= s && j - r >= 0 && j + r <= s)    {
                        cout << i << " " << j << endl;
                        ans = 1;
                        break;
                    }
                }
        }
        if(!ans)
            cout << "poodle" << endl;
    }
}