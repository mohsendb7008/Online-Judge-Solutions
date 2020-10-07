#include <bits/stdc++.h>
using namespace std;

// Red Black Tree

int n, m;
vector<int> childs[200003];
bool red[200003];

int cnt = 0;
int tree[200003];
bool rred[200003];

int pre_order(int node){
    int c = cnt;
    tree[c] = c + 1;
    rred[c] = red[node];
    cnt++;
    for(int child : childs[node])
        tree[c] = max(tree[c], pre_order(child));
    return tree[c];
}

int mod = 1000000007;
int dp[200003][1003];

int main(){
    cin >> n >> m;
    int x;
    red[1] = rred[1] = false;
    for(int i = 2; i <= n; i++)
        cin >> x, childs[x].push_back(i), red[i] = false, rred[i] = false;;
    for(int i = 0; i < m; i++)
        cin >> x, red[x] = true;
    pre_order(1);
    for(int i = n; i >= 0; i--)
        for(int k = 0; k <= m; k++){
            if(i == n)
                dp[i][k] = k == 0;
            else dp[i][k] = (dp[i+1][k] + dp[tree[i]][rred[i]?k-1:k]) % mod;
        }
    for(int j = 0; j <= m; j++)
        cout << dp[0][j] << endl;
}