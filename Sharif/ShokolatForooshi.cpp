#include <bits/stdc++.h>
using namespace std;

bool dp[5003], tmp[5003];
int n, m, a[500003];

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    for(int i = 0; i < n; i++){
        if(!(a[i] % m)){
            cout << "YES" << endl;
            return 0;
        }
        fill_n(tmp, m, 0);
        for(int j = 0; j < m; j++)
            if(dp[j]){
                if(!((j + a[i]) % m)){
                    cout << "YES" << endl;
                    return 0;
                }
                tmp[(j + a[i]) % m] = 1;
            }
        tmp[a[i] % m] = 1;
        for(int j = 0; j < m; j++)
            dp[j] = dp[j] || tmp[j];
    }
    cout << "NO" << endl;
}