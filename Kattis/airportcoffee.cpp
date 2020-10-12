#include <bits/stdc++.h>
using namespace std;

// Airport Coffee

#define num long long int

const int maxn = 5e5 + 3;

int n, trace[maxn];
num l, a, b, t, r, coffee[maxn];
double dp[maxn];
vector<int> out;

inline double calc(num dx){
    double ans = 0;
    if(dx <= a * t)
        return double(dx) / a;
    dx -= a * t, ans += t;
    if(dx <= b * r)
        return ans + double(dx) / b;
    dx -= b * r, ans += r;
    return ans + double(dx) / a;
}

int main(){
    cin >> l >> a >> b >> t >> r >> n;
    for(int i = 0; i < n; i++)
        cin >> coffee[i];
    coffee[n] = l, dp[n] = 0;
    for(int i = n - 1; i >= 0; i--){
        dp[i] = double(coffee[i + 1] - coffee[i]) / a + dp[i + 1], trace[i] = -1;
        num drink = coffee[i] + t * a + r * b;
        int search = lower_bound(coffee, coffee + n, drink) - coffee, lo, hi;
        if(coffee[search] == drink)
            lo = hi = search;
        else
            lo = search - 1, hi = search;
        if(lo != i){
            double c = calc(coffee[lo] - coffee[i]);
            if(c + dp[lo] < dp[i])
                dp[i] = c + dp[lo], trace[i] = lo;
        } 
        double c = calc(coffee[hi] - coffee[i]);
        if(c + dp[hi] < dp[i])
            dp[i] = c + dp[hi], trace[i] = hi;
        
    }
    double ans = double(l) / a;
    cerr << ans << endl;
    if(double(coffee[0]) / a + dp[0] >= ans){
        cout << 0 << endl;
        return 0;
    }
    ans = double(coffee[0]) / a + dp[0];
    cerr << ans << endl;
    int it = 0;
    while(it != n){
        if(trace[it] == -1)
            it++;
        else
            out.push_back(it), it = trace[it];
    }
    cout << out.size() << endl;
    for(int it : out)
        cout << it << " ";
    cout << endl;
}