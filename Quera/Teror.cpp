#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 3;

int n, m;
vector<int> police[maxn];
multiset<int> endss;

int main(){
    cin >> n >> m;
    int l, r;
    while(m--)
        cin >> l >> r, police[l].push_back(r);
    int ans = 0, cover = 0;
    for(int i = 1; i <= n; i++){
        while(!endss.empty() && *endss.begin() < i)
            endss.erase(endss.begin());
        for(int j : police[i])
            endss.insert(j);
        if(i <= cover)
            continue;
        ans++;
        if(!endss.empty())
            cover = *endss.rbegin();
    }
    cout << ans << endl;
}