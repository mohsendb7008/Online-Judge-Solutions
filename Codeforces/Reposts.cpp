#include <bits/stdc++.h>
using namespace std;

map<string, int> h;

string lower(string s){
    string ans = "";
    for(char c : s)
        ans += tolower(c);
    return ans;
}

int main(){
    h["polycarp"] = 1;
    int n, ans = 1;
    cin >> n;
    while(n--){
        string u, v;
        cin >> u >> v >> v;
        u = lower(u), v = lower(v);
        h[u] = h[v] + 1;
        ans = max(ans, h[u]);
    }
    cout << ans << endl;
}