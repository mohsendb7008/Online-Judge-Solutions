#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long H;
    int n, m;
    cin >> H >> n >> m;
    vector<vector<char>> g(n, vector<char>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> g[i][j];

    vector<vector<bool>> vis(n, vector<bool>(m, false));

    int d_odd[6][2] = {{-1,0},{-1,1},{0,-1},{0,1},{1,0},{1,1}};
    int d_even[6][2] = {{-1,-1},{-1,0},{0,-1},{0,1},{1,-1},{1,0}};

    vector<int> comps;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '.' && !vis[i][j]) {
                int cnt = 0;
                queue<pair<int,int>> q;
                q.push({i,j});
                vis[i][j] = true;
                while (!q.empty()) {
                    auto [r,c] = q.front();
                    q.pop();
                    cnt++;
                    int (*d)[2] = (r % 2 ? d_odd : d_even);
                    for (int k = 0; k < 6; k++) {
                        int nr = r + d[k][0];
                        int nc = c + d[k][1];
                        if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                            g[nr][nc] == '.' && !vis[nr][nc]) {
                            vis[nr][nc] = true;
                            q.push({nr,nc});
                        }
                    }
                }
                comps.push_back(cnt);
            }
        }
    }

    sort(comps.rbegin(), comps.rend());
    long long used = 0;
    int pours = 0;
    for (int c : comps) {
        if (used >= H) break;
        pours++;
        used += c;
    }

    cout << pours << "\n";
    return 0;
}
