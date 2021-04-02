#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 3;

int n, x, a[maxn];
set<int> ans;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++){
        cin >> x;
        if(x)
            ans.insert(a[i]);
    }
    for(int it : ans)
        cout << it << " ";
    cout << endl;
}