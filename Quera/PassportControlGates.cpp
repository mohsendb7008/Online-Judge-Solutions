#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 3;

int q, n, k, x, last[maxn];
vector<int> que[maxn], prefix[maxn], suffix[maxn], ans;
priority_queue<pair<int, int>> oldest;

inline int front(int i){
    if(suffix[i].empty())
        return last[i];
    return suffix[i].back();
}

int main(){
    cin >> q >> n;
    for(int i = 0; i < q; i++){
        cin >> k;
        while(k--)
            cin >> x, que[i].push_back(x);
    }
    for(int i = 0; i < q; i++){
        cin >> k;
        while(k--)
            cin >> x, prefix[i].push_back(x);
    }
    for(int i = 0; i < q; i++){
        last[i] = -1;
        if(prefix[i].size() > que[i].size()){
            cout << "Impossible" << endl;
            return 0;
        }
        for(int j = 0; j < prefix[i].size(); j++){
            last[i] = prefix[i][j];
            if(prefix[i][j] != que[i][j]){
                cout << "Impossible" << endl;
                return 0;
            }
        }
        for(int j = prefix[i].size(); j < que[i].size(); j++)
            suffix[i].push_back(que[i][j]);
    }
    for(int i = 0; i < q; i++)
        if(!suffix[i].empty())
            oldest.push({suffix[i].back(), i});
    while(!oldest.empty()){
        int u = oldest.top().first, i = oldest.top().second;
        oldest.pop();
        int cand = -1;
        if(!i)
            cand = i;
        else if(i == q-1)
            cand = q;
        else if(u > front(i-1))
            cand = i;
        else if(u > front(i+1))
            cand = i+1;
        if(cand == -1){
            cout << "Impossible" << endl;
            return 0;
        }
        ans.push_back(cand);
        suffix[i].pop_back();
        if(!suffix[i].empty())
            oldest.push({suffix[i].back(), i});
    }
    cout << ans.size() << endl;
    for(int i : ans)
        cout << i << " ";
    cout << endl;
}