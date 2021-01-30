#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 3;

int n, k, ans[maxn];

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        cin >> n >> k;
        for(int i = 1; i <= k; i++)
            ans[i] = i;
        for(int i = 1; i < k; i++)
            if(2 * k - i <= n){
                reverse(ans + i, ans + k + 1);
                break;
            }
        for(int i = 1; i <= k; i++)
            cout << ans[i] << " ";
        cout << endl;
    }
}
