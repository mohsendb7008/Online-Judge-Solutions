#include <bits/stdc++.h>
using namespace std;

#define num long long int

const int maxn = 1e5 + 3;

int n;
num A, B, a[maxn], b[maxn], k[maxn], kasum;

inline bool solve(){
    for(int last = 0; last < n; last++){
        num tmp = kasum - k[last] * a[last];
        if(B - tmp > (k[last] - 1) * a[last])
            return true;
    }
    return false;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> A >> B >> n;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        for(int i = 0; i < n; i++)
            cin >> b[i];
        kasum = 0;
        for(int i = 0; i < n; i++)
            k[i] = b[i] / A + ((b[i] % A) ? 1 : 0), kasum += k[i] * a[i];
        cout << (solve() ? "YES" : "NO") << endl;
    }
}