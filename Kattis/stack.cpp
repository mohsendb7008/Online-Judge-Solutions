#include <bits/stdc++.h>
using namespace std;

// Stack Construction

string a;
int dp[203][203];

int cdp(int i, int j){
    if(dp[i][j] != -1)
        return dp[i][j];
    if(i == j)
        return dp[i][j] = 1;
    int ans = 1 + cdp(i + 1, j);
    for(int k = i + 1; k <= j; k++)
        if(a[k] == a[i])
            ans = min(ans, (k > i + 1 ? cdp(i + 1, k - 1) : 0) + cdp(k, j));
    return dp[i][j] = ans;
}

int main(){
    int t;
    cin >> t;
    cin.ignore();
    while(t--){
        getline(cin, a);
        for(int i = 0; i < 203; i++)
            for(int j = 0; j < 203; j++)
                dp[i][j] = -1;
        cout << a.size() + 2 * cdp(0, a.size() - 1) << endl;
    }
}