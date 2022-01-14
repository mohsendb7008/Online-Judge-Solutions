// EpigDanceOff

#include <bits/stdc++.h>
using namespace std;

int n, m, underlines[2003];
char g[2003][2003];

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> g[i][j];
        }
    }
    int ans = 1;
    for(int j = 0; j < m; j++){
        for(int i = 0; i < n; i++){
            if(g[i][j] == '_'){
                underlines[j]++;
            }
        }
        if(underlines[j] == n){
            ans++;
        }
    }
    cout << ans << endl;
}