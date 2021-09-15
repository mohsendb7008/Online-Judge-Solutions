#include <bits/stdc++.h>
using namespace std;

int n, a, b, g[103];

inline bool evaluate(int k){
    for(int i = 2; i <= k; i++)
        if (!(g[i] > g[i-1]))
            return false;
    for(int i = 1; i <= k; i++)
        if(!(g[i] >= 0 && g[i] <= 45 + a))
            return false;
    for(int i = k + 2; i <= n; i++)
        if(!(g[i] > g[i-1]))
            return false;
    for(int i = k + 1; i <= n; i++)
        if(!(g[i] >= 45 && g[i] <= 90 + b))
            return false;
    return true;
}

int main() {
    cin >> n >> a >> b;
    for(int i = 1; i <= n; i++)
        cin >> g[i];
    for(int k = 0; k <= n; k++)
        if (evaluate(k)){
            cout << "YES" << endl;
            return 0;
        }
    cout << "NO" << endl;
}