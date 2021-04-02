#include <bits/stdc++.h>
using namespace std;

const int maxn = 300;

string necklace;
int n, edit_distance[maxn + 1][maxn + 1][maxn + 1], dp[maxn + 1][maxn + 1]; 

int c_edit_distance(int b, int i, int k){
    if(edit_distance[b + 1][i + 1][k + 1] != -1)
        return edit_distance[b + 1][i + 1][k + 1];
    int ans;
    if(b == i && k == i - 1)
        ans = 0;
    else if(b == i)
        ans = 1 + c_edit_distance(b, i, k - 1);
    else if(k == i - 1)
        ans = 1 + c_edit_distance(b + 1, i, k);
    else{
        ans = (necklace[b] != necklace[k]) + c_edit_distance(b + 1, i, k - 1);
        ans = min(ans, 1 + c_edit_distance(b + 1, i , k));
        ans = min(ans, 1 + c_edit_distance(b, i, k - 1));
    }
    return edit_distance[b + 1][i + 1][k + 1] = ans;
}

int main(){
    cin >> necklace, n = necklace.size();
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++)
            for(int k = 0; k <= n; k++)
                edit_distance[i][j][k] = -1;
    for(int i = n - 1; i >= 0; i--)
        for(int buffer = 0; buffer <= i; buffer++){
            dp[i][buffer] = INT_MAX;
            for(int j = i; j < n; j++)
                dp[i][buffer] = min(dp[i][buffer], 1 + c_edit_distance(buffer, i, j) + dp[j + 1][i]);
        }
    cout << dp[0][0] << endl;
}