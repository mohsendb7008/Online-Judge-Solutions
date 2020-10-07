#include <bits/stdc++.h>
using namespace std;

// Dice and Ladders

int r, c, n, e, ladder[64+3];
double p;
vector<vector<double>> m;

vector<vector<double>> exp1(int k){
    if(k == 1)
        return m;
    vector<vector<double>> a = exp1(k % 2 ? k-1 : k / 2), ans;
    vector<vector<double>>& b = (k % 2 ? m : a);
    ans.resize(n);
    for(int i = 0; i < n; i++)
        ans[i].resize(n, 0.0);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            for(int k = 0; k < n; k++)
                ans[i][j] += a[i][k] * b[k][j];
    return ans;
}

int main(){
    cin >> r >> c >> e >> p, n = r * c;
    fill_n(ladder, n, -1);
    int x, y;
    while(e--)
        cin >> x >> y, ladder[x-1] = y-1;
    m.resize(n);
    for(int i = 0; i < n; i++)
        m[i].resize(n, 0.0);
    for(int i = 0; i < n; i++)
        for(int k = 1; k <= 6; k++){
            int j = min(n-1, i + k);
            if(ladder[j] != -1)
                j = ladder[j];
            m[i][j] += 1.0/6;
        }
    int lo = 1, hi = 1e8;
    while(lo < hi){
        int k = (lo + hi) / 2;
        double ans = exp1(k)[0][n-1];
        if(ans >= p)
            hi = k;
        else
            lo = k+1;
    }
    cout << lo << endl;
}