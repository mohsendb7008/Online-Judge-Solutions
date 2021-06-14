#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 3;

int n, v, ksum[maxn], csum[maxn];
vector<pair<int, int>> kayak, catamaran;

int main(){
    cin >> n >> v;
    for(int i = 0; i < n; i++){
        int t, p;
        cin >> t >> p;
        if(t == 1)
            kayak.push_back({p, i});
        else
            catamaran.push_back({p, i});
    }
    sort(kayak.begin(), kayak.end());
    reverse(kayak.begin(), kayak.end());
    sort(catamaran.begin(), catamaran.end());
    reverse(catamaran.begin(), catamaran.end());
    int k = kayak.size(), c = catamaran.size();
    for(int i = 1; i <= k; i++)
        ksum[i] = ksum[i-1] + kayak[i-1].first;
    for(int i = 1; i <= c; i++)
        csum[i] = csum[i-1] + catamaran[i-1].first;
    int ans = -1, best_catamaran;
    for(int i = 0; i <= c; i++){
        if(2 * i > v)
            break;
        int curr = csum[i] + ksum[min(v - 2 * i, k)];
        if(curr > ans)
            ans = curr, best_catamaran = i;
    }
    cout << ans << endl;
    for(int i = 0; i < best_catamaran; i++)
        cout << catamaran[i].second + 1 << " ";
    for(int i = 0; i < min(v - 2 * best_catamaran, k); i++)
        cout << kayak[i].second + 1 << " "; 
    cout << endl;
}