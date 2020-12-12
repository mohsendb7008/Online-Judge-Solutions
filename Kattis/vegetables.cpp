#include <bits/stdc++.h>
using namespace std;

// Boiling Vegetables

int n, ans = INT_MAX;
double t, w[1003];

int main(){
    cin >> t >> n;
    for(int i = 0; i < n; i++)
        cin >> w[i];
    for(int i = 0; i < n; i++)
        for(int c = 0; c < 500; c++){
            double pmax = w[i] / (c + 1), pmin = pmax;
            int cnt = c;
            if(cnt >= ans)
                continue;
            for(int j = 0; j < n; j++)
                if(j != i){
                    int k = ceil(w[j] / pmax) - 1;
                    cnt += k;
                    if(cnt >= ans)
                        break;
                    pmin = min(pmin, w[j] / (k + 1));
                }
            if(pmin / pmax > t)
                ans = min(ans, cnt);
        }
    cout << ans << endl;
}