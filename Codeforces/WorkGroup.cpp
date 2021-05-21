#include <bits/stdc++.h>
using namespace std;
 
#define num long long int
 
const int maxn = 2e5 + 3;
 
int n, a[maxn], root;
vector<int> childs[maxn];
num dp[maxn][3];
 
num solve(int node, int parity){
    if(dp[node][parity] != -1)
        return dp[node][parity];
    num ans = 0;
    if(parity){
        ans = a[node] + solve(node, 0);
        num sum = 0;
        vector<num> odds;
        for(int c : childs[node])
            sum += solve(c, 0), odds.push_back(solve(c, 1) - solve(c, 0));
        sort(odds.begin(), odds.end());
        reverse(odds.begin(), odds.end());
        num acc = 0;
        for(int i = 0; i < odds.size(); i++){
            acc += odds[i];
            if(!(i % 2))
                ans = max(ans, sum + acc);
        }
    }
    else{
        num sum = 0;
        vector<num> odds;
        for(int c : childs[node])
            sum += solve(c, 0), odds.push_back(solve(c, 1) - solve(c, 0));
        ans = sum;
        sort(odds.begin(), odds.end());
        reverse(odds.begin(), odds.end());
        num acc = 0;
        for(int i = 0; i < odds.size(); i++){
            acc += odds[i];
            if(i % 2)
                ans = max(ans, sum + acc);
        }
    }
    return dp[node][parity] = ans;
}
 
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int p;
        cin >> p >> a[i];
        if(p == -1)
            root = i;
        else
            childs[p-1].push_back(i);
    }
    for(int i = 0; i < n; i++)
        dp[i][0] = dp[i][1] = -1;
    cout << max(solve(root, 0), solve(root, 1)) << endl;
}