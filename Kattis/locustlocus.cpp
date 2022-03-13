// Locust Locus

#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(!b){
        return a;
    }
    return gcd(b, a % b);
}

int lcm(int a, int b){
    return (a * b) / gcd(a, b);
}

int main(){
    int ans = INT_MAX;
    int k;
    cin >> k;
    while(k--){
        int y, c1, c2;
        cin >> y >> c1 >> c2;
        ans = min(ans, y + lcm(max(c1, c2), min(c1, c2)));
    }
    cout << ans << endl;
}