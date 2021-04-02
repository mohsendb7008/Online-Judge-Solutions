#include <bits/stdc++.h>
using namespace std;

// Elementary Math

#define num long long int

int n, m = 0;
pair<num, num> nums[2503];
vector<pair<int, char>> adj[2503];
num res[3 * 2503];
map<num, int> id;

int gid(num s){
    auto it = id.find(s);
    if(it != id.end())
        return it->second;
    res[m] = s;
    return id[s] = m++;
}

int match[3 * 2503];
char ml[3 * 2503];
bool vis[2503];

bool augment(int l){
    if(vis[l])
        return 0;
    vis[l] = 1;
    for(pair<int, char> r : adj[l])
        if(match[r.first] == -1 || augment(match[r.first])){
            match[r.first] = l, ml[r.first] = r.second;
            return 1;
        }
    return 0;
}

num ans[2503];
char trace[2503];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> nums[i].first >> nums[i].second;
        adj[i].push_back({gid(nums[i].first + nums[i].second), '+'});
        adj[i].push_back({gid(nums[i].first - nums[i].second), '-'});
        adj[i].push_back({gid(nums[i].first * nums[i].second), '*'});
    }
    fill_n(match, m, -1);
    int mcbm = 0;
    for(int i = 0; i < n; i++)
        fill_n(vis, n, 0), mcbm += augment(i);
    if(mcbm != n){
        cout << "impossible" << endl;
        return 0;
    }
    for(int j = 0; j < m; j++)
        if(match[j] != -1)
            ans[match[j]] = res[j], trace[match[j]] = ml[j];
    for(int i = 0; i < n; i++)
        cout << nums[i].first << " " << trace[i] << " " << nums[i].second << " = " << ans[i] << endl; 
}