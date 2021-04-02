#include <bits/stdc++.h>
using namespace std;

// Majstor

inline int play(char x, char y){
    if(x == y)
        return 1;
    if(x == 'R' && y == 'S')
        return 2;
    if(x == 'S' && y == 'P')
        return 2;
    if(x == 'P' && y == 'R')
        return 2;
    return 0;
}

int r, n;
string m, f[53];

int main(){
    cin >> r >> m >> n;
    for(int i = 0; i < n; i++)
        cin >> f[i];
    int ans = 0, opt = 0;
    for(int i = 0; i < r; i++){
        int S = 0, R = 0, P = 0;
        for(int j = 0; j < n; j++)
            ans += play(m[i], f[j][i]), S += play('S', f[j][i]), R += play('R', f[j][i]), P += play('P', f[j][i]);
        opt += max(S, max(R, P));
    }
    cout << ans << endl << opt << endl;
}