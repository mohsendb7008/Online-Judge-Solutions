#include <bits/stdc++.h>
using namespace std;

// Catenyms

int m, indeg[26+3], outdeg[26+3];
vector<pair<string, int>> adj[26+3];
string s;
vector<string> euler;

void dfs(int u){
    while(!adj[u].empty()){
        auto edge = adj[u][adj[u].size()-1];
        adj[u].pop_back();
        dfs(edge.second);
        euler.push_back(edge.first);
    }
}

bool check(){
    for(int i = 0; i < 26; i++)
        if(adj[i].size())
            return false;
    return true;
}

void path(){
    reverse(euler.begin(), euler.end());
    for(int i = 0; i < euler.size() - 1; i++)
        cout << euler[i] << ".";
    cout << euler[euler.size()-1] << endl;
}

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        for(int i = 0; i < 26; i++)
            adj[i].clear(), indeg[i] = 0, outdeg[i] = 0;
        cin >> m;
        while(m--)
            cin >> s, adj[s[0] - 'a'].push_back({s, s[s.size()-1] - 'a'}), outdeg[s[0] - 'a']++, indeg[s[s.size()-1] - 'a']++;
        for(int i = 0; i < 26; i++)
            sort(adj[i].begin(), adj[i].end()), reverse(adj[i].begin(), adj[i].end());
        euler.clear();
        bool tour = true;
        for(int i = 0; i < 26; i++)
            if(indeg[i] != outdeg[i]){
                tour = false;
                break;
            }
        if(tour){
            for(int i = 0; i < 26; i++)
                if(outdeg[i]){
                    dfs(i);
                    break;
                }
            if(!check()){
                cout << "***" << endl;
                continue;
            }
            path();
            continue;
        }
        int s = -1;
        for(int i = 0; i < 26; i++)
            if(outdeg[i] == indeg[i] + 1){
                s = i;
                break;
            }
        if(s == -1){
            cout << "***" << endl;
            continue;
        }
        int e = -1;
        for(int i = 0; i < 26; i++)
            if(indeg[i] == outdeg[i] + 1){
                e = i;
                break;
            }
        if(e == -1){
            cout << "***" << endl;
            continue;
        }
        bool pat = true;
        for(int i = 0; i < 26; i++)
            if(i != s && i != e && indeg[i] != outdeg[i]){
                pat = false;
                break;
            }
        if(!pat){
            cout << "***" << endl;
            continue;
        }
        dfs(s);
        if(!check()){
            cout << "***" << endl;
            continue;
        }
        path();
    }
}