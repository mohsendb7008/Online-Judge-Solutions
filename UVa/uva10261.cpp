#include <bits/stdc++.h>
using namespace std;

// Ferry Loading

int C;
vector<int> cars;
vector<int> psum;
map<pair<int, int>, int> memo;
map<pair<int, int>, char> trace;

int dp(int i, int t){
    if(i == cars.size())
        return 0;
    pair<int, int> p = {i, t};
    if(memo.find(p) != memo.end())
        return memo[p];
    int C1 = C - t;
    int C2 = C - ((i > 0 ? psum[i-1] : 0) - t);
    int ans = 0;
    char tr = 'n';
    if(cars[i] <= C1){
        int subp = dp(i+1, t + cars[i]) + 1;
        if(subp > ans){
            ans = subp;
            tr = 'p';
        }
    }
    if(cars[i] <= C2){
        int subp = dp(i+1, t) + 1;
        if(subp > ans){
            ans = subp;
            tr = 's';
        }
    }
    trace[p] = tr;
    return memo[p] = ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cars.clear();
        psum.clear();
        memo.clear();
        trace.clear();
        cin >> C;
        C *= 100;
        int car;
        while(1){
            cin >> car;
            if(car == 0)
                break;
            cars.push_back(car);
        }
        partial_sum(cars.begin(), cars.end(), back_inserter(psum));
        int ans = dp(0, 0);
        cout << ans << endl;
        int it = 0;
        for(int i = 0; i < cars.size(); i++){
            char tr = trace[{i, it}];
            if(tr == 'n')
                break;
            else
                 cout << (tr == 'p' ? "port" : "starboard") << endl;
            if(tr == 'p')
                it += cars[i];
        }
        if(t != 0)
            cout << endl;
    }

}