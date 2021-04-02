#include <bits/stdc++.h>
using namespace std;

// Digi Comp II

#define num long long int

num n;
int m;
bool st[500003];
int adj[500003][3];
int indeg[500003];
num ba[500003];

int main(){
    cin >> n >> m;
    char c;
    int x, y;
    for(int i = 0; i < m; i++)
        cin >> c >> x >> y, st[i] = c == 'R', adj[i][0] = x-1, adj[i][1] = y-1, indeg[x-1]++, indeg[y-1]++;
    ba[0] = n;
    queue<int> kahn;
    for(int i = 0; i < m; i++)
        if(!indeg[i])
            kahn.push(i);
    while(!kahn.empty()){
        int u = kahn.front();
        kahn.pop();
        num a[2]{ba[u] / 2, ba[u] / 2};
        if(ba[u] % 2)
            a[st[u]]++;
        for(int j = 0; j < 2; j++){
            int v = adj[u][j];
            if(v != -1){
                ba[v] += a[j];
                indeg[v]--;
                if(!indeg[v])
                    kahn.push(v);
            }
        }
        if(ba[u] % 2)
            st[u] = !st[u];
    }
    for(int i = 0; i < m; i++)
        cout << (st[i] ? 'R' : 'L');
    cout << endl;
}