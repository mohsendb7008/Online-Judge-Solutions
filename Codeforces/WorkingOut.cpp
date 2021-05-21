#include <bits/stdc++.h>
using namespace std;

#define num long long int

int n, m;
num a[1003][1003], dp1[1003][1003], dp2[1003][1003], dp3[1003][1003], dp4[1003][1003];

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            if(!i && !j)
                dp1[i][j] = a[i][j];
            else if(!i)
                dp1[i][j] = dp1[i][j-1] + a[i][j];
            else if(!j)
                dp1[i][j] = dp1[i-1][j] + a[i][j];
            else
                dp1[i][j] = max(dp1[i-1][j], dp1[i][j-1]) + a[i][j];
        }
    for(int i = n-1; i >= 0; i--)
        for(int j = m-1; j >= 0; j--){
            if(i == n-1 && j == m-1)
                dp2[i][j] = a[i][j];
            else if(i == n-1)
                dp2[i][j] = dp2[i][j+1] + a[i][j];
            else if(j == m-1)
                dp2[i][j] = dp2[i+1][j] + a[i][j];
            else
                dp2[i][j] = max(dp2[i+1][j], dp2[i][j+1]) + a[i][j];
        }
    for(int i = n-1; i >= 0; i--)
        for(int j = 0; j < m; j++){
            if(i == n-1 && !j)
                dp3[i][j] = a[i][j];
            else if(i == n-1)
                dp3[i][j] = dp3[i][j-1] + a[i][j];
            else if(!j)
                dp3[i][j] = dp3[i+1][j] + a[i][j];
            else
                dp3[i][j] = max(dp3[i+1][j], dp3[i][j-1]) + a[i][j];
        }
    for(int i = 0; i < n; i++)
        for(int j = m-1; j > 0; j--){
            if(!i && j == m-1)
                dp4[i][j] = a[i][j];
            else if(!i)
                dp4[i][j] = dp4[i][j+1] + a[i][j];
            else if(j == m-1)
                dp4[i][j] = dp4[i-1][j] + a[i][j];
            else
                dp4[i][j] = max(dp4[i][j+1], dp4[i-1][j]) + a[i][j];
        }
    num ans = 0;
    for(int i = 1; i < n-1; i++)
        for(int j = 1; j < m-1; j++){
            ans = max(ans, dp1[i-1][j] + dp3[i][j-1] + dp2[i+1][j] + dp4[i][j+1]);
            ans = max(ans, dp1[i][j-1] + dp3[i+1][j] + dp2[i][j+1] + dp4[i-1][j]);
        }
    cout << ans << endl;
}