#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-9

const int maxn = 1003;
const double inf = LLONG_MAX;

int n;
double l, x[maxn], b[maxn];
double dp[maxn];
int trace[maxn];
vector<int> ans;

int main(){
    cin >> n >> l;
    for(int i = 1; i <= n; i++)
        cin >> x[i] >> b[i];
    double lo = 0, hi = 1e6;
    while(fabs(hi - lo) > EPS){
        double mid = (lo + hi) / 2;
        dp[n] = 0;
        for(int i = n-1; i >= 0; i--){
            dp[i] = inf;
            for(int j = i+1; j <= n; j++)
                dp[i] = min(dp[i], sqrt(abs(x[j] - x[i] - l)) - mid * b[j] + dp[j]);
        }
        if(dp[0] < 0)
            hi = mid;
        else
            lo = mid;
    }
    dp[n] = 0;
    for(int i = n-1; i >= 0; i--){
        dp[i] = inf;
        for(int j = i+1; j <= n; j++){
            double subp = sqrt(abs(x[j] - x[i] - l)) - lo * b[j] + dp[j];
            if(subp < dp[i])
                dp[i] = subp, trace[i] = j;
        }
    }
    int it = 0;
    while(it < n){
        ans.push_back(trace[it]);
        it = trace[it];
    }
    for(int i : ans)
        cout << i << " ";
    cout << endl;
}