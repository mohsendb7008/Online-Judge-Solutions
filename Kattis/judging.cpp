#include <bits/stdc++.h>
using namespace std;

// Judging Troubles

const int maxn = 2e5 + 3;

int n, dom[maxn], kat[maxn];

int cnt = 0;
map<string, int> id;
int gid(string name){
    if(id.find(name) != id.end())
        return id[name];
    return id[name] = cnt++;
}

int main(){
    cin >> n;
    string x;
    for(int i = 0; i < n; i++)
        cin >> x, dom[gid(x)]++;
    for(int i = 0; i < n; i++)
        cin >> x, kat[gid(x)]++;
    int ans = 0;
    for(int i = 0; i < cnt; i++)
        ans += min(dom[i], kat[i]);
    cout << ans << endl;
}