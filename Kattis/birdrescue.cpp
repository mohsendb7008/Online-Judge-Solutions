#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    ll x_a, y_a;
    cin >> x_a >> y_a;

    vector<ll> mins(n), maxs(n);

    for(int i = 0; i < n; i++){
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if(x1 > x2) swap(x1, x2);
        if(y1 > y2) swap(y1, y2);

        ll x_clamped = x_a;
        if(x_a < x1) x_clamped = x1;
        else if(x_a > x2) x_clamped = x2;

        ll y_clamped = y_a;
        if(y_a < y1) y_clamped = y1;
        else if(y_a > y2) y_clamped = y2;

        ll minDist = llabs(x_clamped - x_a) + llabs(y_clamped - y_a);

        ll d1 = llabs(x1 - x_a) + llabs(y1 - y_a);
        ll d2 = llabs(x1 - x_a) + llabs(y2 - y_a);
        ll d3 = llabs(x2 - x_a) + llabs(y1 - y_a);
        ll d4 = llabs(x2 - x_a) + llabs(y2 - y_a);
        ll maxDist = max(max(d1, d2), max(d3, d4));

        mins[i] = minDist;
        maxs[i] = maxDist;
    }

    sort(mins.begin(), mins.end());
    sort(maxs.begin(), maxs.end());

    for(int qi = 0; qi < q; qi++){
        ll d;
        cin >> d;
        ll A = upper_bound(mins.begin(), mins.end(), d) - mins.begin();
        ll B = upper_bound(maxs.begin(), maxs.end(), d - 1) - maxs.begin();
        ll answer = A - B;
        cout << answer << "\n";
    }

    return 0;
}
