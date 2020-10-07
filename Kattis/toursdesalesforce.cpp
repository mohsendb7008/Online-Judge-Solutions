#include <bits/stdc++.h>
using namespace std;

// Tours de Sales Force

inline double dis(pair<int, int> f, pair<int, int> s){
    double dx = f.first - s.first, dy = f.second - s.second;
    return sqrt(dx * dx + dy * dy);
}

vector<pair<int, int>> curr;
double tsp[(1 << 16) + 3][16 + 3];

double csp(){
    int siz = curr.size() - 1;
    for(int mask = 1; mask < (1 << siz); mask++)
        for(int i = 0; i < siz; i++){
            if(mask == 1 << i)
                tsp[mask][i] = dis(curr[0], curr[i+1]);
            else if(mask & (1 << i)){
                tsp[mask][i] = INT_MAX;
                for(int j = 0; j < siz; j++)
                    if(j != i && (mask & (1 << j)))
                        tsp[mask][i] = min(tsp[mask][i], tsp[mask - (1 << i)][j] + dis(curr[j+1], curr[i+1]));
            }
        }
    double ans = INT_MAX;
    for(int i = 0; i < siz; i++)
        ans = min(ans, tsp[(1 << siz) - 1][i] + dis(curr[i+1], curr[0]));
    return ans;
}

int d;
vector<pair<int, int>> region[53];

double bipartite[53][53];

int main(){
    cout << fixed << setprecision(5);
    cin >> d;
    double ans = 0;
    for(int i = 0; i < d; i++){
        int s, x, y;
        cin >> s;
        while(s--)
            cin >> x >> y, region[i].push_back({x, y});
        curr = region[i];
        ans += csp();
    }
    cout << ans << " ";
    ans = 0;
    for(int i = 0; i < d / 2; i++)
        for(int j = d / 2; j < d; j++){
            curr.clear();
            for(pair<int, int> p : region[i])
                curr.push_back(p);
            for(pair<int, int> p : region[j])
                curr.push_back(p);
            bipartite[i][j] = bipartite[j][i] = csp();
        }
    // Learn min cost bipartite matching and continue: 
}