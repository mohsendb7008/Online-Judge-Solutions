#include <bits/stdc++.h>
using namespace std;

// Silueta

const int maxn = 1e4 + 3;
const int maxrc = 1e3 + 3;

int n, l[maxn], rr[maxn], h[maxn], r = 0, c = 0;
char g[maxrc][maxrc];
bool vis[maxrc][maxrc];

inline bool u(int i, int j){
    if(i == 0)
        return true;
    return g[i-1][j] == '.';
}

inline bool ri(int i, int j){
    if(j == c-1)
        return true;
    return g[i][j+1] == '.';
}

inline bool le(int i, int j){
    if(j == 0)
        return true;
    return g[i][j-1] == '.';
}

inline int perimeter(int i, int j){
    if(u(i, j)){
        if(ri(i, j) || le(i, j))
            return 2;
        return 1;
    }
    if(ri(i, j) || le(i, j))
        return 1;
    if(i == 0 || j == 0 || j == c - 1)
        return 0;
    if(g[i-1][j-1] == '.' || g[i-1][j+1] == '.')
        return 0;
    return -1;
}

int main(){
    int minv = INT_MAX;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> l[i] >> rr[i] >> h[i], l[i]--, rr[i]--, minv = min(minv, l[i]), c = max(c, rr[i]), r = max(r, h[i]);
    c -= minv;
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            g[i][j] = '.';
    for(int i = 0; i < n; i++){
        l[i] -= minv, rr[i] -= minv;
        for(int x = r - h[i]; x < r; x++)
            for(int y = l[i]; y < rr[i]; y++)
                g[x][y] = '#';
    }
    int ans = 0;
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            if(g[i][j] == '#'){
                int curr = perimeter(i, j);
                if(curr != -1)
                    vis[i][j] = true, ans += curr;
            }
    cout << ans << endl;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++)
            cout << (vis[i][j] ? '#' : '.');
        cout << endl;
    }
    while(c--)
        cout << '*';
    cout << endl;
}