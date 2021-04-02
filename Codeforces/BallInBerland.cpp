#include <bits/stdc++.h>
using namespace std;

const int maxk = 2e5 + 3;

int a, b, k, ma[maxk], mb[maxk];
pair<int, int> matches[maxk];

inline long long int solve(){
    long long int ans = 0;
    for(int i = 0; i < k; i++)
        ans += k - (ma[matches[i].first] + mb[matches[i].second] - 1);
    return ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> a >> b >> k;
        fill_n(ma, a, 0);
        fill_n(mb, b, 0);
        for(int i = 0; i < k; i++)
            cin >> matches[i].first, matches[i].first--, ma[matches[i].first]++;
        for(int i = 0; i < k; i++)
            cin >> matches[i].second, matches[i].second--, mb[matches[i].second]++;
        cout << solve() / 2 << endl;
    }
}