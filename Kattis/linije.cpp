#include <bits/stdc++.h>
using namespace std;

// Linije

const int maxn = 1e5 + 3;

int e, n = 0, m = 0;
map<int, int> ml, mr;

int gidl(int s){
    if(ml.find(s) != ml.end())
        return ml[s];
    return ml[s] = n++;
}

int gidr(int s){
    if(mr.find(s) != mr.end())
        return mr[s];
    return mr[s] = m++;
}

vector<int> adj[maxn];
int match[maxn], vis[maxn];

bool augment(int l){
    if(vis[l])
        return 0;
    vis[l] = 1;
    for(int r : adj[l])
        if(match[r] == -1 || augment(match[r])){
            match[r] = l;
            return 1;
        }
    return 0;
}

int main(){
    cin >> e;
    int x, y;
    while(e--)
        cin >> x >> y, adj[gidl(x)].push_back(gidr(y));
    if(n != m){
        cout << "Mirko" << endl;
        return 0;
    }
    fill_n(match, n, -1);
    int mcbm = 0;
    for(int i = 0; i < n; i++)
        fill_n(vis, n, 0), mcbm += augment(i);
    cout << (mcbm == n ? "Slavko" : "Mirko") << endl;
}