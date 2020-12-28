#include <bits/stdc++.h>
using namespace std;

// Seven Kingdoms

const int maxn = 4e3 + 3;
int n, e;
bool adjmatrix[maxn][maxn];
int color[maxn];
int nums = 1, scc;
int dfs_low[maxn], dfs_num[maxn];
int compo[maxn];
vector<int> st;
bool visited[maxn];
vector<int> adjs[maxn];
vector<int> sccs[maxn];
int val[maxn];

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
            sccs[scc - 1].push_back(w);
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
    cin >> n >> e;
    for(int i = 0; i < e; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        adjmatrix[u][v] = adjmatrix[v][u] = 1;
    }
    fill_n(color, n, 2);
    color[0] = 0, color[1] = 1;
    for(int i = 0; i < n; i++)
        if(adjmatrix[0][i])
            color[i] = 3;
    for(int i = 0; i < n; i++)
        if(adjmatrix[1][i])
            color[i] = 4;
    for(int i = 2; i < n; i++)
        for(int j = i + 1; j < n; j++)
            if(!adjmatrix[i][j]){
                if(color[i] == 2 && color[j] == 2){
                    cout << "impossible" << endl;
                    return 0;
                }
                if(color[i] == 2)
                    add_edge(2 * j + 1, 2 * j + 1);
                else if(color[j] == 2)
                    add_edge(2 * i + 1, 2 * i + 1);
                else if(color[i] != color[j])
                    add_edge(2 * i + 1, 2 * j + 1);
                else
                    add_edge(2 * i, 2 * j), add_edge(2 * i + 1, 2 * j + 1);
            }
    n *= 2;
    for(int i = 0; i < n; i++)
        if(!dfs_num[i])
            dfs(i);
    for(int i = 0; i < n; i += 2)
        if(compo[i] == compo[i ^ 1]){
            cout << "impossible" << endl;
            return 0;
        }
    fill_n(val, n / 2, -1);
    for(int i = 0; i < n / 2; i++)
        if(color[i] == 2)
            val[i] = 1;
    for(int i = 0; i < scc; i++){
        int v = 1;
        for(int x : sccs[i]){
            if(x % 2 == 0 && val[x / 2] == 0){
                v = 0;
                break;
            }
            else if(x % 2 && val[x / 2] == 1){
                v = 0;
                break;
            }
        }
        for(int x : sccs[i]){
            if(x % 2)
                val[x / 2] = !v;
            else
                val[x / 2] = v;
        }
    }
    cout << 1 << " ";
    for(int i = 0; i < n / 2; i++)
        if(adjmatrix[0][i] && !val[i])
            cout << i + 1 << " ";
    cout << endl << 2 << " ";
    for(int i = 0; i < n / 2; i++)
        if(adjmatrix[1][i] && !val[i])
            cout << i + 1 << " ";
    cout << endl;
}