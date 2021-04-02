#include <bits/stdc++.h>
using namespace std;

int n, m;
set<pair<int, int>> edges;

int main(){
    cin >> n >> m;
    if(n <= 2 || m < n){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    if(n == 3){
        cout << "1 2 2" << endl;
        cout << "1 3 5" << endl;
        cout << "2 3 4" << endl;
        return 0;
    }
    for(int i = 1; i <= n; i++)
        for(int j = i + 1; j <= n; j++)
            edges.insert({i, j});
    cout << 1 << " " << n << " " << 1 << endl;
    edges.erase({1, n});
    m--;
    for(int i = 1; i < n-1; i++){
        cout << i << " " << i + 1 << " " << 3 << endl;
        edges.erase({i, i + 1});
        m--;
    }
    cout << n - 1 << " " << n << " " << 4 << endl;
    edges.erase({n-1, n});
    m--;
    while(m){
        auto it = edges.begin();
        cout << it->first << " " << it->second << " " << 1000000 - 1 << endl;
        edges.erase(it);
        m--;
    }
}