#include <bits/stdc++.h>
using namespace std;

#define num long long int

// Equilibrium Mobile

map<int, vector<int>> nodes;
map<int, num> node_values;
int cnt;

int build(){
    int weight;
    if(scanf("%d", &weight)){
        node_values[cnt] = weight;
        return cnt++;
    }
    vector<int>& adj = nodes[cnt];
    int save = cnt++;
    char c;
    while(true){
        scanf("%c", &c);
        if(c == ']') // else it's [ or ,
            break;
        adj.push_back(build());
    }
    return save;
}

map<num, num> counters;

void track(int node, num denom){
    if(nodes[node].empty())
        counters[node_values[node] * denom]++;
    else for(int child : nodes[node])
        track(child, denom * nodes[node].size());
}

int main(){
    int t;
    scanf("%d\n", &t);
    for(int i = 0; i < t; i++){
        nodes.clear();
        node_values.clear();
        cnt = 0;
        build();
        /*cout << cnt << endl;
        for(int i = 0; i < cnt; i++){
            cout << i << " : " << node_values[i] << endl;
            for(int adj : nodes[i])
                cout << adj << " ";
            if(!nodes[i].empty())
                cout << endl;
        }*/
        counters.clear();
        track(0, 1);
        num ans = 0;
        for(pair<int, num> p : counters)
            ans = max(ans, p.second);
        ans = node_values.size() - ans;
        cout << ans << endl;
        scanf("\n");
    }
}