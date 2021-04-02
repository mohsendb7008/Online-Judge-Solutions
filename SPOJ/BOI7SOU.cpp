#include <bits/stdc++.h>
using namespace std;

// Sound

#define first(s) *s.begin()
#define last(s) *(--s.end())

const int maxn = 1e6 + 3;

int n, m, c, a[maxn];
multiset<int> sounds;
vector<int> ans;

int main(){
    cin >> n >> m >> c;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < m; i++)
        sounds.insert(a[i]);
    if(last(sounds) - first(sounds) <= c)
        ans.push_back(0);
    for(int i = 1; i + m <= n; i++){
        sounds.erase(sounds.find(a[i-1]));
        sounds.insert(a[i+m-1]);
        if(last(sounds) - first(sounds) <= c)
            ans.push_back(i);
    }
    if(ans.empty())
        cout << "NONE" << endl;
    for(int it : ans)
        cout << it + 1 << endl;
}