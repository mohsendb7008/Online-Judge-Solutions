#include <bits/stdc++.h>
using namespace std;

// A Match Making Problem

int main(){
    int b, s;
    int test = 1;
    while(cin >> b){
        cin >> s;
        if(b + s == 0)
            break;
        int minb = INT_MAX;
        for(int i = 0; i < b; i++){
            int x;
            cin >> x;
            minb = min(minb, x);
        }
        for(int i = 0; i < s; i++){
            int x;
            cin >> x;
        }
        cout << "Case " << test++ << ": ";
        if(b <= s) cout << 0 << endl;
        else cout << b - s << " " << minb << endl;
    }
}