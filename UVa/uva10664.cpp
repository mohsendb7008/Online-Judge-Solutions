#include <bits/stdc++.h>
using namespace std;

// Luggage

int dp[103][103][23];
vector<int> suitcases;

int cdp(int i, int j, int k){
    if(k == -1)
        return i == 0 && j == 0;
    if(dp[i][j][k] != -1)
        return dp[i][j][k];
    int w = suitcases[k];
    int ans = 0;
    if(i >= w)
        ans = ans || cdp(i-w, j, k-1);
    if(!ans && j >= w)
        ans = ans || cdp(i, j-w, k-1);
    return dp[i][j][k] = ans;
}

bool solution(){
    int n = suitcases.size();
    int sum = accumulate(suitcases.begin(), suitcases.end(), 0);
    if(sum % 2 != 0)
        return false;
    for(int i = 0; i <= sum / 2; i++)
        for(int j = 0; j <= sum / 2; j++)
            for(int k = 0; k < n; k++)
                dp[i][j][k] = -1;
    return cdp(sum / 2, sum / 2, n-1);
}

int main(){
    int m;
    cin >> m;
    string line;
    getline(cin, line);
    while(m--){
        getline(cin, line);
        stringstream ss(line);
        suitcases.clear();
        int suitcase;
        while(ss >> suitcase)
            suitcases.push_back(suitcase);
        bool ans = solution();
        cout << (ans ? "YES" : "NO") << endl;
    }
}