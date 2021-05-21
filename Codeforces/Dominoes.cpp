#include <bits/stdc++.h>
using namespace std;

const int n = 7;

int m, u[103], v[103], deg[n];
set<int> adj[n];
vector<string> ans;

void euler(int x){
    while(!adj[x].empty()){
        int e = *adj[x].begin();
        int y = (u[e] == x) ? v[e] : u[e];
        adj[x].erase(e), adj[y].erase(e);
        euler(y);
        ans.push_back(to_string(e + 1) + ((u[e] == x) ? " +" : " -"));
    }
}

int check_eulerian(){ 
    int oddcnt = 0, oddv;
    for(int i = 0; i < n; i++)
        if(deg[i] % 2)
            oddcnt++, oddv = i;
    if(oddcnt == 1 || oddcnt > 2)
        return -1;
    if(oddcnt == 0){
        for(int i = 0; i < n; i++)
            if(deg[i])
                return i;
    }
    return oddv;
}

int main(){
    cin >> m;
    for(int i = 0; i < m; i++)
        cin >> u[i] >> v[i], deg[u[i]]++, deg[v[i]]++, adj[u[i]].insert(i), adj[v[i]].insert(i);
    int s = check_eulerian();
    if(s == -1){
        cout << "No solution" << endl;
        return 0;
    }
    euler(s);
    for(int i = 0; i < n; i++)
        if(!adj[i].empty()){
            cout << "No solution" << endl;
            return 0;
        }
    reverse(ans.begin(), ans.end());
    for(string a : ans)
        cout << a << '\n';
}