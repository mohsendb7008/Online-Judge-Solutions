#include <bits/stdc++.h>
using namespace std;

// Simple Adjacency Maximization

int main(){
    int t;
    cin >> t;
    while(t--){
        int P, Q;
        cin >> P >> Q;
        long long int ans = 0;
        int ptr = 0;
        if(P > 2*Q){
            int rem = P - 2*Q;
            P = 2 * Q;
            while(rem--)
                ans += 1ll<<(ptr++);
        }
        while(Q--){
            if(P >= 2){
                P -= 2;
                ans += (1ll<<ptr) + (1ll<<(ptr+2));
                ptr += 3;
            }
            else if(P == 1){
                ans += 1ll<<ptr;
                break;
            }
            else break;
        }
        cout << ans << endl;
    }
}