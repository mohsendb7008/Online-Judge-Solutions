#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int ans;
    cin >> n >> ans;
    n--;
    while(n--){
        int x;
        cin >> x;
        if (x < ans)
            ans = x;
    }
    cout << ans << endl;
}