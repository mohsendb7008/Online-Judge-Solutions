#include<bits/stdc++.h>
using namespace std;

#define num long long int

vector<pair<num, num>> v;

int main(){
    int t;
    cin >> t;
    while(t--){
        v.clear();
        int n;
        num a, x;
        cin >> n >> x;
        while(n--)
            cin >> a, v.push_back({a, 1ll});
        for(int i = 0; i < v.size(); i++){
            auto it = v[i];
            if(it.first % x)
                break;
            v.push_back({it.first / x, it.second * x});
        }
        num ans = 0;
        for(auto it : v)
            ans += it.first * it.second;
        cout << ans << endl;
    }
}