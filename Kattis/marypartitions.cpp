#include <bits/stdc++.h>
using namespace std;

// m-ary Partitions

int m, n;
vector<int> p;
long long int dp[10003][103];

int main(){
    for(int i = 0; i < 103; i++)
        dp[0][i] = 1;
    int q, z;
    cin >> q;
    while(q--){
        cin >> z >> m >> n;
        p.clear();
        int cand = 1;
        while(cand <= n){
            p.push_back(cand);
            cand *= m;
        }
        for(int i = 1; i <= n; i++)
            for(int k = 0; k < p.size(); k++){
                dp[i][k] = 0;
                if(k)
                    dp[i][k] += dp[i][k-1];
                if(i >= p[k])
                    dp[i][k] += dp[i-p[k]][k];
            }
        cout << z << " " << dp[n][p.size()-1] << endl;
    }
}