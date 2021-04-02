#include <bits/stdc++.h>
using namespace std;

// Marbles on a tree

int n;
bool root[10003];
int marbles[10003];
vector<int> childs[10003];

int cnt[10003];
int sum[10003];

int ccnt(int node){
    int ans = 1;
    for(int child : childs[node])
        ans += ccnt(child);
    return cnt[node] = ans;
}

int csum(int node){
    int ans = marbles[node];
    for(int child : childs[node])
        ans += csum(child);
    return sum[node] = ans;
}

int main(){
    while(1){
        cin >> n;
        if(!n)
            break;
        fill(root+1, root+n+1, true);
        int v, m, d, x;
        for(int i = 0; i < n; i++){
            cin >> v >> m >> d;
            marbles[v] = m;
            childs[v].clear();
            for(int i = 0; i < d; i++){
                cin >> x;
                childs[v].push_back(x);
                root[x] = false;
            }
        }
        for(int i = 1; i <= n; i++)
            if(root[i]){
                ccnt(i);
                csum(i);
                break;
            }
        int ans = 0;
        for(int i = 1; i <= n; i++)
            ans += abs(cnt[i] - sum[i]);
        cout << ans << endl;
    }
}