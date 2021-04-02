#include <bits/stdc++.h>
using namespace std;

// Grand Opening

const int maxn = 1e5 + 3;

int n, m, indeg[maxn], outdeg[maxn];
vector<pair<int, bool>> adj[maxn];
string names[maxn];
vector<string> anims[maxn];
map<string, int> id;
string x;

void euler(int u){
    for(pair<int, bool>& v : adj[u])
        if(v.second)
            v.second = 0, euler(v.first);
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> names[i] >> m;
        while(m--){
            cin >> x;
            if(x != names[i])
                anims[i].push_back(x);
        }
        id[names[i]] = i;
    }
    for(int u = 0; u < n; u++)
        for(string s : anims[u])
            adj[u].push_back({id[s], 1}), outdeg[u]++, indeg[id[s]]++;
    bool alarm = true;
    for(int i = 0; i < n; i++)
        if(!adj[i].empty()){
            alarm = false;
            break;
        }
    if(alarm){
        cout << "FALSE ALARM" << endl;
        return 0;
    }
    bool tour = true;
    for(int i = 0; i < n; i++)
        if(indeg[i] != outdeg[i]){
            tour = false;
            break;
        }
    if(tour){
        for(int i = 0; i < n; i++)
            if(outdeg[i] > 0){
                euler(i);
                break;
            }
        bool valid = true;
        for(int i = 0; i < n; i++)
            for(pair<int, bool> v : adj[i])
                if(v.second){
                    valid = false;
                    break;
                }
        cout << (valid ? "POSSIBLE" : "IMPOSSIBLE") << endl;
        return 0;
    }
    int s = -1;
    for(int i = 0; i < n; i++)
        if(outdeg[i] == indeg[i] + 1){
            s = i;
            break;
        }
    if(s == -1){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    int e = -1;
    for(int i = 0; i < n; i++)
        if(indeg[i] == outdeg[i] + 1){
            e = i;
            break;
        }
    if(e == -1){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    bool path = true;
    for(int i = 0; i < n; i++)
        if(i != s && i != e && indeg[i] != outdeg[i]){
            path = false;
            break;
        }
    if(!path){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    euler(s);
    bool valid = true;
    for(int i = 0; i < n; i++)
        for(pair<int, bool> v : adj[i])
            if(v.second){
                valid = false;
                break;
            }
    cout << (valid ? "POSSIBLE" : "IMPOSSIBLE") << endl;
}
