#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 3;

int n, m, k, fi[maxn], indeg[maxn];
string pats[maxn], que[maxn];
map<string, int> ind;
vector<int> adj[maxn], topoList;
priority_queue<int, vector<int>, greater<int>> pq;

int qi;
string st;

void track(int i){
    if(i == k){
        auto it = ind.find(st);
        if(it == ind.end() || fi[qi] == it->second)
            return;
        adj[fi[qi]].push_back(it->second);
        indeg[it->second]++;
        return;
    }
    st.push_back(que[qi][i]);
    track(i + 1);
    st.pop_back();
    st.push_back('_');
    track(i + 1);
    st.pop_back();
}

bool kahn(){
    for(int i = 0; i < n; i++)
        if(!indeg[i])
            pq.push(i);
    while(!pq.empty()){
        int cur = pq.top();
        pq.pop();
        topoList.push_back(cur);
        for(auto v: adj[cur]){
            indeg[v]--;
            if(!indeg[v])
                pq.push(v);
        }
    }
    return topoList.size() == n;
}

bool match(int i, int f){
    for(int z = 0; z < k; z++){
        if(pats[f][z] == '_')
            continue;
        if(pats[f][z] != que[i][z])
            return false;
    }
    return true;
}

int main(){
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
        cin >> pats[i], ind[pats[i]] = i;
    for(int i = 0; i < m; i++)
        cin >> que[i] >> fi[i], fi[i]--;
    for(int i = 0; i < m; i++)
        if(!match(i, fi[i])){
            cout << "NO" << endl;
            return false;
        }
    for(int i = 0; i < m; i++){
        qi = i;
        st = "";
        track(0);
    }
    if(kahn()){
        cout << "YES" << endl;
        for(int i : topoList)
            cout << i + 1 << " ";
        cout << endl;
    }
    else
        cout << "NO" << endl;
}