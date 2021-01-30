#include <bits/stdc++.h>
using namespace std;

#define num long long int

int n;
map<num, int> mp;
vector<num> u;

inline bool solve(){
    if(mp.size() != n)
        return false;
    u.clear();
    for(auto it : mp){
        if(!it.first)
            return false;
        if(it.first % 2)
            return false;
        if(it.second != 2)
            return false;
        u.push_back(it.first);
    }
    num sum = 0, last = LLONG_MAX;
    for(num i = n; i; i--){
        num curr = u[i-1] - 2 * sum;
        if(curr <= 0 || curr % (2 * i))
            return false;
        curr /= (2 * i);
        if(curr <= 0 || curr >= last)
            return false;
        sum += curr, last = curr;
    }
    return true;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        num x;
        mp.clear();
        for(int i = 0; i < 2 * n; i++)
            cin >> x, mp[x]++;
        cout << (solve() ? "YES" : "NO") << endl;
    }
}