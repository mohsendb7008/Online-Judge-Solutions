#include <bits/stdc++.h>
using namespace std;

// Grapevine

int n, m, q, l, u;
vector<int> grid[503];

inline bool judge(int k){
    if(k == 0)
        return true;
    for(int x = 0; (x + k - 1) < n; x++){
       int y = lower_bound(grid[x].begin(), grid[x].end(), l) - grid[x].begin();
       if(y + k - 1 >= m)
            continue;
        if(grid[x+k-1][y+k-1] <= u)
            return true;
    } 
    return false;
}

int main(){
    while(1){
        cin >> n >> m;
        if(n + m == 0)
            break;
        for(int i = 0; i < n; i++){
            grid[i].clear();
            grid[i].reserve(m);
            for(int j = 0; j < m; j++){
                int x;
                cin >> x;
                grid[i].push_back(x);
            }
        }
        cin >> q;
        while(q--){
            cin >> l >> u;
            int start = 0, end = min(n, m);
            while(start < end){
                int mid = (start + end);
                if(mid %2 == 0)
                    mid /= 2;
                else mid = (mid / 2) + 1;
                if(judge(mid))
                    start = mid;
                else end = mid - 1;
            }
            cout << start << endl;
        }
        cout << "-" << endl;
    }
}