#include <bits/stdc++.h>
using namespace std;

// Password

string s, t;
int n;

int adjR[4]{0, 0, 1, -1};
int adjC[4]{1, -1, 0, 0};
map<char, int> dir{{'R', 0}, {'L', 1}, {'D', 2}, {'U', 3}};

bool valid, vis[3+3][3+3];

void dfs(int i, int j, int x){
    if(vis[i][j]){
        valid = false;
        return;
    }
    vis[i][j] = true;
    if(x == t.size())
        return;
    int k = dir[t[x]];
    if(!(i + adjR[k] >= 0 && i + adjR[k] < 3 && j + adjC[k] >= 0 && j + adjC[k] < 3)){
        valid = false;
        return;
    }
    dfs(i + adjR[k], j + adjC[k], x + 1);
}

int main(){
    cin >> s;
    n = s.size();
    int ans = 0;
    for(int mask = 0; mask < (1 << n); mask++){
        t = "";
        for(int i = 0; i < n; i++){
            t += s[i];
            if(mask & (1 << i))
                t += s[i];
        }
        for(int x = 0; x < 3; x++)
            for(int y = 0; y < 3; y++){
                valid = true;
                for(int i = 0; i < 3; i++)
                    for(int j = 0; j < 3; j++)
                        vis[i][j] = false;
                dfs(x, y, 0);
                if(valid)
                    ans++;
            }
    }
    cout << ans << endl;
}