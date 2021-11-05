#include <bits/stdc++.h>
using namespace std;

int n;
bool mat[23][23];

inline int leng(int mask){
    int cnt = 0;
    for(int i = 0; i < n; i++)
        if(mask & (1 << i))
            cnt++;
    return cnt;
}

inline int depress(int mask, int i){
    for(int j = 0; j < n; j++)
        if(mat[i][j] && !(mask & (1 << j))){
            return 1;
        }
    return 0;
}

inline int process(int mask){
    int ans = 0;
    for(int i = 0; i < n; i++)
        if(mask & (1 << i))
            ans += depress(mask, i);
    return ans;
}

int main(){
    cin >> n;
    n *= 2;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            char x;
            cin >> x;
            if(x == '1')
                mat[i][j] = true;
        }
    }
    int ans = INT_MAX;
    for(int mask = 0; mask < (1 << n); mask++){
        if(leng(mask) == n / 2){
            ans = min(ans, process(mask));
        }
    }
    cout << ans << endl;
}