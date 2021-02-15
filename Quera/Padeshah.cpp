#include <bits/stdc++.h>
using namespace std;

map<int, int> dis;
queue<int> bfs;

int main(){
    int n, x, s = 0, e = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> x, s = 10 * s + x, e = 10 * e + i + 1;
    dis[s] = 0;
    bfs.push(s);
    while(1){
        int u = bfs.front();
        bfs.pop();
        if(u == e){
            cout << dis[u] << endl;
            return 0;
        }
        string k = to_string(u);
        for(int x = 0; x < n; x++){
            string w = k;
            reverse(w.begin(), next(w.begin(), x + 1));
            int v = stoi(w);
            if(dis.find(v) == dis.end())
                dis[v] = dis[u] + 1, bfs.push(v);
        }
    }
}