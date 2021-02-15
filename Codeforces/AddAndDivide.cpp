#include <bits/stdc++.h>
using namespace std;

inline int solve(int a, int b){
    int ans = 0;
    while(a)
        a /= b, ans++;
    return ans;
}

int main(){
    int t, a, b;
    cin >> t;
    while(t--){
        cin >> a >> b;
        int adds = 0;
        if(b == 1)
            adds = 1, b = 2;
        int divides = solve(a, b);
        while(1){
            int nexty = solve(a, b + 1);
            if(adds + 1 + nexty > adds + divides)
                break;
            b++, adds++, divides = nexty;
        }
        cout << adds + divides << endl;
    }
}