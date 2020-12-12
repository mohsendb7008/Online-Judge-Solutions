#include <bits/stdc++.h>
using namespace std;

// Electrical Outlets

int n, k, x;
int main(){
    cin >> n;
    while(n--){
        int ans = 0;
        cin >> k;
        for(int i = 0; i < k; i++)
            cin >> x, ans += x;
        cout << ans - k + 1 << endl;
    }
}