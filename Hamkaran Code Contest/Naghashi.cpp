#include <bits/stdc++.h>
using namespace std;

#define num long long int

int n, m, k;
num col[53][53];
set<num> ans;

int main() {
    cin >> n >> m >> k;
    for(num i = 0; i < k; i++){
        int c, r, l;
        cin >> c >> r >> l;
        c--, r--;
        for(int x = c; x < c + l; x++)
            for(int y = r; y < r + l; y++)
                col[x][y] += (1ll << i);
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(col[i][j])
                ans.insert(col[i][j]);
    cout << ans.size() << endl;
}