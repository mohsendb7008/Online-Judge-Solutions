#include <bits/stdc++.h>
using namespace std;

// Stand on Zanzibar

int t, x, ans;
vector<int> turt;

int main(){
    cin >> t;
    while(t--){
        ans = 0;
        turt.clear();
        cin >> x;
        while(x){
            turt.push_back(x);
            cin >> x;
        }
        for(int i = 1; i < turt.size(); i++)
            ans += max(0, turt[i] - 2 * turt[i-1]);
        cout << ans << endl;
    }
}