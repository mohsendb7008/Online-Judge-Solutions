#include <bits/stdc++.h>
using namespace std;

// Difference

bitset<200000001> b;
vector<int> v;
int r, m;

int main(){
    b.reset();
    v.reserve(10000);
    cin >> r >> m;
    if(r == m){
        cout << 1 << endl;
        return 0;
    }
    b[r] = 1;
    v.push_back(r);
    int ptr = 1, ans = 2;
    while(ans <= 10000){
        while(b.test(ptr))
            ptr++;
        int k = r + ptr;
        if(k == m){
            cout << ans << endl;
            return 0;
        }
        if(k <= 200000000)
            b[k] = 1;
        ptr++;
        for(int q : v){
            int d = k - q;
            if(d == m){
                cout << ans << endl;
                return 0;
            }
            if(d < ptr)
                break;
            if(d <= 200000000)
                b[d] = 1;
        }
        v.push_back(k);
        r = k;
        ans++;
    }
}