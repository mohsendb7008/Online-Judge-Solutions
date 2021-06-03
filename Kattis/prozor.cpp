#include <bits/stdc++.h>
using namespace std;

// Prozor

int n, m, k, psum[103][103];
char g[103][103];

int main(){
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            cin >> g[i][j];
            psum[i][j] = g[i][j] == '*';
            if(i)
                psum[i][j] += psum[i-1][j];
            if(j)
                psum[i][j] += psum[i][j-1];
            if(i && j)
                psum[i][j] -= psum[i-1][j-1];
        }
    int best = 0;
    pair<int, int> ans;
    for(int i = 1; i+k-3 < n-1; i++)
        for(int j = 1; j+k-3 < m-1; j++){
            int x = i+k-3, y = j+k-3;
            int flies = psum[x][y] - psum[i-1][y] - psum[x][j-1] + psum[i-1][j-1];
            if(flies > best)
                best = flies, ans = {i-1, j-1};
        }
    cout << best << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i == ans.first || i == ans.first+k-1){
                if(j == ans.second || j == ans.second+k-1)
                    cout << '+';
                else if(j > ans.second && j < ans.second+k-1)
                    cout << '-';
                else
                    cout << g[i][j];
            }
            else if(j == ans.second || j == ans.second+k-1){
                if(i > ans.first && i < ans.first+k-1)
                    cout << '|';
                else
                    cout << g[i][j];
            }
            else
                cout << g[i][j];
        }
        cout << endl;
    }
}