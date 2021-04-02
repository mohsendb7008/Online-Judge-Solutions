#include <bits/stdc++.h>
using namespace std;

// Where is the Marble?

vector<int> seq;

int main(){
    int n, q;
    int test = 1;
    while(1){
        cin >> n >> q;
        if(n + q == 0)
            break;
        cout << "CASE# " << test++ << ":" << endl;
        seq.clear();
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            seq.push_back(x);
        }
        sort(seq.begin(), seq.end());
        for(int i = 0; i < q; i++){
            int x;
            cin >> x;
            auto it = lower_bound(seq.begin(), seq.end(), x);
            if(it != seq.end() && *it == x)
                cout << x << " found at " << it - seq.begin() + 1 << endl;
            else cout << x << " not found" << endl;
        }
    }
}