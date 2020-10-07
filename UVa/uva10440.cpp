#include <bits/stdc++.h>
using namespace std;

// Ferry Loading II

int T, n, m;
long long int t, cars[1443], ncars[2443];

int main(){
    cin >> T;
    while(T--){
        cin >> n >> t >> m;
        for(int i = 0; i < m; i++)
            cin >> cars[i];
        if(m % n){
            for(int i = 0; i < n - m % n; i++)
                ncars[i] = 0;
            for(int i = 0; i < m; i++)
                ncars[n - m % n + i] = cars[i];
            m += n - m % n;
        }
        else copy(cars, cars+m, ncars);
        long long int ans = 0, trips = m / n;
        for(int i = 1; i <= trips; i++)
            ans = max(ans, ncars[i * n - 1]) + 2 * t;
        cout << ans - t << " " << trips << endl;
    }
}