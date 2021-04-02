#include <bits/stdc++.h>
using namespace std;

// Get to Work

vector<int> towns[103];
int ans[103];

int main(){
    int tc;
    cin >> tc;
    for(int z = 1; z <= tc; z++){
        int n, t, e;
        cin >> n >> t >> e, t--;
        for(int i = 0; i < n; i++)
            towns[i].clear(), ans[i] = 0;
        while(e--){
            int h, p;
            cin >> h >> p, h--;
            towns[h].push_back(p);
        }
        bool ok = 1;
        for(int i = 0; i < n; i++){
            if(i == t || towns[i].empty())
                continue;
            sort(towns[i].begin(), towns[i].end(), greater<int>());
            int psum = 0;
            for(int j : towns[i]){
                psum += j, ans[i]++;
                if(psum >= towns[i].size())
                    break;
            }
            if(psum < towns[i].size()){
                ok = 0;
                break;
            }
        }
        cout << "Case #" << z << ": ";
        if(!ok)
            cout << "IMPOSSIBLE";
        else for(int i = 0; i < n; i++)
            cout << ans[i] << " ";
        cout << endl;
    }
}