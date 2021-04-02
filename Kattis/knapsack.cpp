#include <bits/stdc++.h>
using namespace std;

// Knapsack

int n, C;
int profit[2003];
int weight[2003];

int dp[2003][2003];
bool trace[2003][2003];

int cdp(int i, int c){
    if(i == -1)
        return 0;
    if(dp[i][c] != -1)
        return dp[i][c];
    int ans = cdp(i-1, c);
    trace[i][c] = false;
    if(weight[i] <= c){
        int other = cdp(i-1, c-weight[i]) + profit[i];
        if(other > ans){
            ans = other;
            trace[i][c] = true;
        }
    }
    return dp[i][c] = ans;
}

vector<int> indices;

int main(){
    while(cin >> C){
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> profit[i] >> weight[i];
        for(int i = 0; i < n; i++)
            for(int j = 0; j <= C; j++)
                dp[i][j] = -1;
        cdp(n-1, C);
        indices.clear();
        int iti = n-1, itc = C;
        while(iti >= 0){
            if(trace[iti][itc]){
                indices.push_back(iti);
                itc -= weight[iti];
            }
            iti--;
        }
        cout << indices.size() << endl;
        for(int i = indices.size()-1; i >= 0; i--)
            cout << indices[i] << " ";
        cout << endl;
    }
}