#include <bits/stdc++.h>
using namespace std;

// DVDs

int n;

int main(){
    int k, x;
    cin >> k;
    while(k--){
        cin >> n;
        int ptr = 1, ans = 0;
        for(int i = 0; i < n; i++){
            cin >> x;
            if(x == ptr)
                ptr++;
            else ans++;
        }
        cout << ans << endl;
    }
}