#include <bits/stdc++.h>
using namespace std;

// Awkward Party

int n, x;
map<int, int> ind;

int main(){
    cin >> n;
    int ans = n;
    for(int i = 0; i < n; i++){
        cin >> x;
        if(ind.find(x) != ind.end())
            ans = min(ans, i - ind[x]);
        ind[x] = i;
    }
    cout << ans << endl;
}