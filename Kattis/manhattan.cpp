#include <bits/stdc++.h>
using namespace std;

// Manhattan

const int MAX_N = 123;
int s, a, m;
vector<int> adjs[MAX_N];

int n, nums, scc;
int dfs_low[MAX_N], dfs_num[MAX_N];
int compo[MAX_N];
vector<int> st;
bool visited[MAX_N];

void dfs(int u){
    dfs_num[u] = dfs_low[u] = nums++;
    st.push_back(u);
    visited[u] = true;
    for(auto v: adjs[u]){
        if(!dfs_num[v])
            dfs(v);
        if(visited[v])
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }
    if(dfs_low[u] == dfs_num[u]){
        scc++;
        while(true){
            int w = st.back();
            st.pop_back();
            visited[w] = false;
            compo[w] = scc;
            if(w == u)
                break;
        }
    }
}

void add_edge(int a, int b){
    adjs[a ^ 1].push_back(b);
    adjs[b ^ 1].push_back(a);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> s >> a >> m;
        n = 2 * (s + a);
        for(int i = 0; i < n; i++)
            adjs[i].clear();
        fill_n(dfs_num, n, 0);
        fill_n(dfs_low, n, 0);
        fill_n(visited, n, 0);
        nums = 1, scc = 0;
        while(m--){
            int y1, x1, y2, x2;
            cin >> y1 >> x1 >> y2 >> x2;
            y1--, x1--, y2--, x2--;
            x1 *= 2, x2 *= 2, y1 *= 2, y2 *= 2;
            y1 += 2 * a, y2 += 2 * a;
            if(x1 == x2 && y1 == y2)
                continue;
            if(x1 == x2){
                if(y1 > y2)
                    add_edge(x2 ^ 1, x2 ^ 1);
                else
                    add_edge(x2, x2);
            }
            else if(y1 == y2){
                if(x1 > x2)
                    add_edge(y1 ^ 1, y1 ^ 1);
                else
                    add_edge(y1, y1);
            }
            else{
                if(x1 < x2 && y1 < y2)
                    add_edge(y1, x1), add_edge(y1, y2), add_edge(x2, x1), add_edge(x2, y2);
                else if(x1 < x2 && y1 > y2){
                    add_edge(x1 ^ 1, y1), add_edge(x1 ^ 1, x2 ^ 1), add_edge(y2, y1), add_edge(y2, x2 ^ 1);
                }
                else if(x1 > x2 && y1 < y2){
                    add_edge(y1 ^ 1, x1), add_edge(y1 ^ 1, y2 ^ 1), add_edge(x2, x1), add_edge(x2, y2 ^ 1);
                }
                else{
                    add_edge(y1 ^ 1, x1 ^ 1), add_edge(x2 ^ 1, x1 ^ 1), add_edge(y1 ^ 1, y2 ^ 1), add_edge(x2 ^ 1, y2 ^ 1);
                }
            }
        }
        for(int i = 0; i < n; i++)
            if(!dfs_num[i])
                dfs(i);
        bool ans = 1;
        for(int i = 0; i < n; i += 2)
            if(compo[i] == compo[i ^ 1]){
                ans = 0;
                break;
            }
        if(ans)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}