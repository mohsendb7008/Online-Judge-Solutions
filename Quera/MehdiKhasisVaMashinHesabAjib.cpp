#include <bits/stdc++.h>
using namespace std;

int n, m;
queue<int> q;
int dist[100000];

int main(){
    fill_n(dist, 100000, INT_MAX);
    cin >> n >> m;
    dist[n] = 0;
    q.push(n);
    while(!q.empty()){
        int tp = q.front();
        q.pop();
        if(tp == m)
            break;
        if(tp-1 >= 1)
            if(dist[tp-1] > dist[tp] + 1)
                dist[tp-1] = dist[tp] + 1, q.push(tp-1);
        if(tp*2 <= 10000)
            if(dist[tp*2] > dist[tp] + 1)
                dist[tp*2] = dist[tp] + 1, q.push(tp*2);
     }
    cout << dist[m] << endl;
}
