#include <bits/stdc++.h>
using namespace std;

// Saving the Universe

int q, n, m;
string x;
set<string> s;

int main(){
    cin >> q;
    for(int t = 1; t <= q; t++){
        s.clear();
        cin >> n;
        cin.ignore();
        for(int i = 0; i < n; i++)
            getline(cin, x);
        int ans = 0;
        cin >> m;
        cin.ignore();
        while(m--){
            getline(cin, x);
            s.insert(x);
            if(s.size() == n)
                ans++, s.clear(), s.insert(x);
        }
        cout << "Case #" << t << ": " << ans << endl;
    }
}