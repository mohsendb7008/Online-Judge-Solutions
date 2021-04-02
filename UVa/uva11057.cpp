#include <bits/stdc++.h>
using namespace std;

// Exact Sum

int n;
vector<int> seq;

int main(){
    seq.reserve(10001);
    while(cin >> n){
        seq.clear();
        for(int i = 0; i < n; i++){
            int x; 
            cin >> x;
            seq.push_back(x);
        }
        int k;
        cin >> k;
        sort(seq.begin(), seq.end());
        pair<int, int> ans = {0, INT_MAX};
        for(int item : seq)
            if(k - item >= 0){
                auto ptr = lower_bound(seq.begin(), seq.end(), k-item);
                if(ptr != seq.end() && *ptr == k-item){
                    int a = min(item, k-item);
                    int b = max(item, k-item);
                    if(b - a < ans.second - ans.first)
                        ans = {a, b};
                }
            }
        cout << "Peter should buy books whose prices are " << ans.first << " and " << ans.second << "." << endl << endl;
    }
}