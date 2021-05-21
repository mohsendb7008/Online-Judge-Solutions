#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 3;

int n, a[maxn];
vector<int> b;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    if(n <= 2){
        cout << 0 << endl;
        return 0;
    }
    long long int ans = 0;
    b.push_back(a[0]);
    b.push_back(a[1]);
    for(int i = 2; i < n; i++){
        int ptr = b.size()-1;
        if(ptr >= 1 && b[ptr] <= b[ptr-1] && b[ptr] <= a[i]){
            ans += min(b[ptr-1], a[i]);
            b.pop_back();
            i--;
            continue;
        }
        b.push_back(a[i]);
    }
    sort(b.begin(), b.end());
    for(int i = 0; i < b.size() - 2; i++)
        ans += b[i];
    cout << ans << endl;
}