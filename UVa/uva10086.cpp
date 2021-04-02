#include <bits/stdc++.h>
using namespace std;

// Test the Rods

int T1, T2, n;
int m[33];
int NCPC[33][23], BCEW[33][23];
int dp[33][303][303];
int trace[33][303][303];

int cdp(int s, int N, int B){
    if(s == 0)
        return 0;
    if(dp[s][N][B] != -1)
        return dp[s][N][B];
    int ans = INT_MAX;
    for(int i = 0; i <= m[s]; i++){
        int j = m[s] - i;
        if(N-i >= 0 && B-j >= 0){
            int value = cdp(s-1, N-i, B-j) + NCPC[s][i] + BCEW[s][j];
            if(value < ans){
                ans = value;
                trace[s][N][B] = i;
            }
        }

    }
    return dp[s][N][B] = ans;
}

vector<int> rods;

int main(){
    while(true){
        cin >> T1 >> T2;
        if(T1 + T2 == 0)
            break;
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> m[i];
            NCPC[i][0] = 0;
            BCEW[i][0] = 0;
            for(int j = 1; j <= m[i]; j++)
                cin >> NCPC[i][j];
            for(int j = 1; j <= m[i]; j++)
                cin >> BCEW[i][j];
        }
        for(int i = 0; i < 33; i++)
            for(int j = 0; j < 303; j++)
                for(int z = 0; z < 303; z++){
                    dp[i][j][z] = -1;
                    trace[i][j][z] = -1;
                }
        cout << cdp(n, T1, T2) << endl;
        rods.clear();
        int itS = n, itN = T1, itB = T2;
        while(itS){
            int it = trace[itS][itN][itB];
            rods.push_back(it);
            itN -= it;
            itB -= m[itS] - it;
            itS--;
        }
        reverse(rods.begin(), rods.end());
        for(int i = 0; i < rods.size(); i++)
            cout << rods[i] << (i == rods.size() - 1 ? "" : " ");
        cout << endl << endl;
    }

}