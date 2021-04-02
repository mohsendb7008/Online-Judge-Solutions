#include<bits/stdc++.h>
using namespace std;

#define num long long int

const int maxn = 3e5 + 3;

int n, m, k[maxn];
num c[maxn];

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 0; i < n; i++)
            cin >> k[i], k[i]--;
        for(int i = 0; i < m; i++)
            cin >> c[i];
        sort(k, k + n, greater<int>());
        int ptr = 0;
        num ans = 0;
        for(int i = 0; i < n; i++){
            if(ptr < k[i])
                ans += c[ptr++];
            else
                ans += c[k[i]];
        }
        cout << ans << endl;
    }
}