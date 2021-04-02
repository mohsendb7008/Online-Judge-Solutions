#include <bits/stdc++.h>
using namespace std;

int n, k, h[103];

inline int simulate(){
    for(int i = 0; i < n-1; i++){
        if(h[i] >= h[i+1])
            continue;
        h[i]++;
        return i+1;
    }
    return -1;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 0; i < n; i++)
            cin >> h[i];
        int ans;
        for(int i = 0; i < k; i++){
            ans = simulate();
            if(ans == -1)
                break;
        }
        cout << ans << endl;
    }
}