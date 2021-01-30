#include <bits/stdc++.h>
using namespace std;

// Cat vs. Dog

const int maxn = 502;
const int inf = INT_MAX;

struct edge{
    int u, v, cap, flow = 0;
    edge(int u, int v, int cap){
        this->u = u, this->v = v, this->cap = cap;
    }
};

int n, m, s, t, ptr[maxn], level[maxn];
vector<edge> edges;
vector<int> adjs[maxn];
queue<int> q;

void add_edge(int u, int v, int cap){
    edges.push_back(edge(u, v, cap));
    edges.push_back(edge(v, u, 0));
    adjs[u].push_back(m);
    adjs[v].push_back(m + 1);
    m += 2;
}

bool bfs(){
    q.push(s);
    fill_n(level, n, -1);
    level[s] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int eid : adjs[u]){
            int v = edges[eid].v;
            if(edges[eid].cap - edges[eid].flow == 0)
                continue;
            if(level[v] == -1)
                q.push(v), level[v] = level[u] + 1;
        }
    }
    return level[t] != -1;
}

int dfs(int u, int pushed){
    if(u == t)
        return pushed;
    for(; ptr[u] < adjs[u].size(); ptr[u]++){
        int cid = ptr[u];
        auto& e = edges[adjs[u][cid]];
        int v = e.v;
        if(e.cap - e.flow == 0 || level[v] != level[u] + 1)
            continue;
        int tr = dfs(v, min(pushed, e.cap - e.flow));
        if(tr == 0)
            continue;
        e.flow += tr;
        edges[adjs[u][cid] ^ 1].flow -= tr;
        return tr;
    }
    return 0;
}

int max_flow(){
    int ans = 0;
    while(bfs()){
        fill_n(ptr, n, 0);
        while(1){
            int p = dfs(s, inf);
            if(!p)
                break;
            ans += p;
        }
    }
    return ans;
}

int cat_counter, dog_counter;
unordered_map<string, int> cat_index, dog_index;

inline int cat_id(string cat){
    auto it = cat_index.find(cat);
    if(it == cat_index.end())
        return cat_index[cat] = cat_counter++;
    return it->second;
}

inline int dog_id(string dog){
    auto it = dog_index.find(dog);
    if(it == dog_index.end())
        return dog_index[dog] = dog_counter++;
    return it->second;
}

map<pair<int, int>, int> votes;
vector<pair<int, int>> nodes;

int main(){
    int test_cases;
    cin >> test_cases;
    while(test_cases--){
        int voters;
        cin >> voters >> voters >> voters;
        cat_counter = 1, dog_counter = 1;
        cat_index.clear(), dog_index.clear();
        votes.clear(), nodes.clear();
        string keep, throw_out;
        for(int i = 0; i < voters; i++){
            cin >> keep >> throw_out;
            if(keep[0] == 'C')
                votes[{cat_id(keep), -dog_id(throw_out)}]++;
            else
                votes[{-cat_id(throw_out), dog_id(keep)}]++;
        }
        n = votes.size() + 2, m = 0, s = n - 2, t = n - 1;
        edges.clear();
        for(int i = 0; i < n; i++)
            adjs[i].clear();
        for(auto it : votes){
            if(it.first.first > 0)
                add_edge(s, nodes.size(), it.second);
            else
                add_edge(nodes.size(), t, it.second);
            nodes.push_back(it.first);
        }
        for(int i = 0; i < nodes.size(); i++)
            if(nodes[i].first > 0)
                for(int j = 0; j < nodes.size(); j++)
                    if(nodes[i].first == -nodes[j].first || nodes[i].second == -nodes[j].second)
                        add_edge(i, j, inf);
        cout << voters - max_flow() << endl;
    }
}