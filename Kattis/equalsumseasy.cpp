#include <bits/stdc++.h>
using namespace std;

// Equal Sums (Easy)

int t, n, a[23], ans1, ans2;
map<int, int> sums;

int main(){
    cin >> t;
    for(int tc = 1; tc <= t; tc++){
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        ans1 = -1;
        sums.clear();
        for(int mask = 1; mask < (1 << n); mask++){
            int sum = 0;
            for(int i = 0; i < n; i++)
                if(mask & (1 << i))
                    sum += a[i];
            if(sums[sum]){
                ans1 = sums[sum], ans2 = mask;
                break;
            }
            sums[sum] = mask;
        }
        cout << "Case #" << tc << ":" << endl;
        if(ans1 == -1)
            cout << "Impossible" << endl;
        else{
            int inter = ans1 & ans2;
            ans1 -= inter, ans2 -= inter;
            for(int i = 0; i < n; i++)
                if(ans1 & (1 << i))
                    cout << a[i] << " ";
            cout << endl;
            for(int i = 0; i < n; i++)
                if(ans2 & (1 << i))
                    cout << a[i] << " ";
            cout << endl;
        }
    }
}