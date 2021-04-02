#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 3;

int n;
map<int, int> cnt;
int a[maxn];
priority_queue<int> b;
vector<int> tmp;

int main(){
    int x;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> x, cnt[x]++;
    x = 0;
    for(auto it : cnt)
        a[x++] = it.second;
    sort(a, a + x);
    cnt.clear();
    int y;
    for(int i = 0; i < n; i++)
        cin >> y, cnt[y]++;
    for(auto it : cnt)
        b.push(it.second);
    int ans = 0;
    for(int i = x - 1; i >= 0; i--){
        tmp.clear();
        while(!b.empty() && a[i]--){
            int u = b.top();
            b.pop();
            if(u > 1)
                tmp.push_back(u - 1);
            ans++;
        }
        for(int u : tmp)
            b.push(u);
    }
    cout << ans << endl;
}