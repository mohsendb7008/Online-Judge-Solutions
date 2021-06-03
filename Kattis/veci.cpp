#include <bits/stdc++.h>
using namespace std;

// Veci

int main(){
    string x;
    cin >> x;
    string it = x;
    int target = stoi(x);
    int ans = INT_MAX;
    sort(it.begin(), it.end());
    do{
        int now = stoi(it);
        if(now > target)
            ans = min(ans, now);
    }while(next_permutation(it.begin(), it.end()));
    cout << (ans == INT_MAX ? 0 : ans) << endl;
}