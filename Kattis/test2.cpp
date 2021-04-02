#include <bits/stdc++.h>
using namespace std;

// Test

int n;
string names[303];
map<string, int> id;

int gid(string s){
    if(id.find(s) != id.end())
        return id[s];
    names[n] = s;
    return id[s] = n++;
}

vector<int> adj[303];
int cnt, dfsn[303], dfsl[303];
bool vis[303];
stack<int> scc;
vector<set<string>> sccs;

void dfs(int u){
    dfsn[u] = dfsl[u] = cnt++;
    vis[u] = 1;
    scc.push(u);
    for(int v : adj[u]){
        if(!dfsn[v])
            dfs(v);
        if(vis[v])
            dfsl[u] = min(dfsl[u], dfsl[v]);
    }
    if(dfsl[u] == dfsn[u]){
        set<string> tmp;
        while(1){
            int v = scc.top();
            scc.pop();
            vis[v] = 0;
            tmp.insert(names[v]);
            if(v == u)
                break;
        }
        sccs.push_back(tmp);
    }
}

bool first = true;

int main(){
    int t;
    while(1){
        cin >> t;
        if(!t)
            break;
        if(!first)
            cout << endl;
        first = false;
        n = 0;
        id.clear();
        for(int i = 0; i < 303; i++)
            adj[i].clear();
        while(t--){
            string v[6];
            for(int i = 0; i < 5; i++)
                cin >> v[i];
            cin >> v[5];
            for(int i = 0; i < 5; i++)
                adj[gid(v[5])].push_back(gid(v[i]));               
        }
        cnt = 1;
        fill_n(dfsn, n, 0);
        sccs.clear();
        for(int i = 0; i < n; i++)
            if(!dfsn[i])
                dfs(i);
        set<string> lines;
        for(set<string> tmp : sccs){
            string line = "";
            for(string x : tmp)
                line += x + " ";
            lines.insert(line.substr(0, line.size()-1));
        }
        for(string line : lines)
            cout << line << endl;       
    }
}