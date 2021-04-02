#include <bits/stdc++.h>
using namespace std;

int n, x[1003], y[1003], vis[1003], cc = 0;

void dfs(int i){
    vis[i] = 1;
    for(int j = 0; j < n; j++)
        if((x[i] == x[j] || y[i] == y[j]) && !vis[j])
            dfs(j);
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    for(int i = 0; i < n; i++)
        if(!vis[i])
            cc++, dfs(i);
    cout << cc - 1 << endl;
}