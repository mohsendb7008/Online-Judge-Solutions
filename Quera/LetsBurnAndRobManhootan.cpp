#include <bits/stdc++.h>
using namespace std;

#define num long long int

int n, m;
num A[203][203], H[203][203], V[203][203], V1[203][203], V2[203][203], dp1[203][203], dp2[203][203];

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> A[i][j];
    for(int i = 0; i < n + 1; i++)
        for(int j = 0; j < m; j++)
            cin >> H[i][j], H[i][j] *= -1;
    for(int j = 0; j < m + 1; j++)
        for(int i = 0; i < n; i++)
            cin >> V[j][i], V[j][i] *= -1;
    for(int j = 0; j < m + 1; j++)
        for(int i = 0; i < n; i++){
            V1[j][i] = V[j][i];
            V2[j][i] = V[j][i];
            for(int k = j; k < m; k++)
                V1[j][i] += A[i][k], V2[j][i] -= A[i][k];
        }
    for(int i = 0; i < n + 1; i++)
        for(int j = 0; j < m + 1; j++){
            if(!i && !j)
                continue;
            else if(!i)
                dp1[i][j] = dp1[i][j-1] + H[i][j-1];
            else if(!j)
                dp1[i][j] = dp1[i-1][j] + V1[j][i-1];
            else
                dp1[i][j] = max(dp1[i][j-1] + H[i][j-1], dp1[i-1][j] + V1[j][i-1]);
        }
    for(int i = n; i >= 0; i--)
        for(int j = m; j >= 0; j--){
            if(i == n && j == m)
                continue;
            else if(i == n)
                dp2[i][j] = dp2[i][j+1] + H[i][j];
            else if(j == m)
                dp2[i][j] = dp2[i+1][j] + V2[j][i];
            else
                dp2[i][j] = max(dp2[i][j+1] + H[i][j], dp2[i+1][j] + V2[j][i]);
        }
    cout << dp1[n][m] + dp2[0][0] << endl;
}