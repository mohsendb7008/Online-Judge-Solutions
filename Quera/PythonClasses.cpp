#include <bits/stdc++.h>
using namespace std;

string line;

int n = 0;
map<string, int> id;
string parent[2003];

char sub[13], super[13];

int par[2003];
vector<int> adj[2003];
int indeg[2003];

bool cycle(){
    queue<int> kahn;
    int popped = 0;
    for(int i = 1; i <= n; i++)
        if(!indeg[i])
            kahn.push(i);
    while(!kahn.empty()){
        int u = kahn.front();
        kahn.pop();
        popped++;
        for(int v : adj[u]){
            indeg[v]--;
            if(!indeg[v])
                kahn.push(v);
        }
    }
    return popped != n;
}

int dp[2003][2003];

int cdp(int i, int a){
    if(dp[i][a] != -1)
        return dp[i][a];
    int ans1 = 0;
    for(int j : adj[i])
        ans1 += cdp(j, a);
    if(i <= a)
        return dp[i][a] = ans1;
    int ans2 = 1;
    for(int j : adj[i])
        ans2 += cdp(j, i);
    return dp[i][a] = max(ans1, ans2);
}

int main(){
    while(getline(cin, line)){
        n++;
        if(line.find('(') != string::npos){
            sscanf(line.c_str(), "class %[^(](%[^)]):", sub, super);
            id[string(sub)] = n, parent[n] = string(super);
        }
        else{
            sscanf(line.c_str(), "class %[^:]:", sub);
            id[string(sub)] = n;
        }
        getline(cin, line), getline(cin, line);
    }
    fill_n(par, n + 1, -1);
    for(int i = 1; i <= n; i++)
        if(parent[i] != "")
            par[i] = id[parent[i]];
    for(int i = 1; i <= n; i++)
        if(par[i] != -1)
            adj[par[i]].push_back(i), indeg[i] = 1;
    if(cycle()){
        cout << -1 << endl;
        return 0;
    }
    for(int i = 1; i <= n; i++)
        for(int a = 0; a <= n; a++)
            dp[i][a] = -1;
    int ans = 0;
    for(int i = 1; i <= n; i++)
        if(par[i] == -1)
            ans += cdp(i, 0);
    cout << n - ans << endl;
}