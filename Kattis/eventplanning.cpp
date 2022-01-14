// Event Planning

#include <bits/stdc++.h>
using namespace std;

int n, b, h, w;

int main(){
    cin >> n >> b >> h >> w;
    int ans = INT_MAX;
    for(int i = 0; i < h; i++){
        int p;
        cin >> p;
        for(int d = 0; d < w; d++){
            int a;
            cin >> a;
            if(n <= a && n * p <= b){
                ans = min(ans, n * p);
            }
        }
    }
    if(ans == INT_MAX){
        cout << "stay home" << endl;
    }
    else{
        cout << ans << endl;
    }
}