#include <bits/stdc++.h>
using namespace std;

// Committee Assignment

int cnt;
map<string, int> id;
inline int gid(string name){
    if(id.find(name) != id.end())
        return id[name];
    return id[name] = cnt++;
}

int n, m;
bool bad[15][15];

int ans, ptr, co[15];

void track(int i){
    if(ans == 2)
        return;
    if(i == n){
        ans = min(ans, ptr);
        return;
    }
    for(int j = 0; j < ptr; j++){
        bool can = true;
        for(int k = 0; k < n; k++)
            if((co[j] & (1 << k)) && bad[i][k]){
                can = false;
                break;
            }
        if(can){
            co[j] += 1 << i;
            track(i + 1);
            co[j] -= 1 << i;
        }
    }
    if(ptr + 1 < ans){
        co[ptr++] = 1 << i;
        track(i + 1);
        ptr--;
    }
}

int main(){
    while(1){
        cin >> n >> m;
        if(!(n + m))
            break;
        cnt = 0;
        id.clear();
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                bad[i][j] = false;
        string x, y;
        for(int i = 0; i < m; i++){
            cin >> x >> y;
            int j = gid(x), k = gid(y);
            bad[j][k] = bad[k][j] = true;
        }
        if(!m)
            cout << 1 << endl;
        else if(m == 1)
            cout << 2 << endl;
        else if(m == (n * (n - 1)) / 2)
            cout << n << endl;
        else{
            ans = n - 1, ptr = 1, co[0] = 1;
            track(1);
            cout << ans << endl;
        }
    }
}