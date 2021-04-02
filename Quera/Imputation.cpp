#include <bits/stdc++.h>
using namespace std;

#define num long long int

const int maxn = 1e4 + 3;
const num inf = LLONG_MAX;

int n, k, m;
bool leaf[maxn];
string b[maxn];
vector<int> adj[maxn];
num delta[4+3][4+3];
map<char, int> dna{
    {'A', 0},
    {'T', 1},
    {'C', 2},
    {'G', 3}
};

num dp[maxn][4+3][203];

num cdp(int u, int d, int j, int p){
    if(dp[u][d][j] != -1)
        return dp[u][d][j];
    if(leaf[u])
        return dp[u][d][j] = (b[u][j] == '?' || dna[b[u][j]] == d) ? 0 : inf;
    num ans = 0;
    for(int v : adj[u])
        if(v != p){
            num curr = inf;
            for(int f = 0; f < 4; f++){
                num subp = cdp(v, f, j, u);
                if(subp != inf)
                    curr = min(curr, delta[d][f] + subp);
            }
            ans += curr;
        }
    return dp[u][d][j] = ans;
}

int main(){
    cin >> n;
    int x, y;
    for(int i = 0; i < n-1; i++)
        cin >> x >> y, adj[x-1].push_back(y-1), adj[y-1].push_back(x-1);
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            cin >> delta[i][j];
    cin >> k;
    while(k--)
        cin >> x, leaf[x-1] = 1, cin >> b[x-1], m = b[x-1].size();
    for(int i = 0; i < n; i++)
        for(int d = 0; d < 4; d++)
            for(int j = 0; j < m; j++)
                dp[i][d][j] = -1;
    num ans = 0;
    for(int j = 0; j < m; j++){
        num curr = inf;
        for(int d = 0; d < 4; d++)
            curr = min(curr, cdp(0, d, j, -1));
        ans += curr;
    }
    cout << ans << endl;
}