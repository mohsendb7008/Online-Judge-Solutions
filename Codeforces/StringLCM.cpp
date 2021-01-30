#include <bits/stdc++.h>
using namespace std;

string s, t, lc;

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        cin >> s >> t;
        if(s.size() < t.size())
            swap(s, t);
        lc = "";
        bool ans = 1;
        int ptr = 0;
        while(1){
            lc += s;
            for(int i = int(lc.size()) - int(s.size()); i < int(lc.size()); i++){
                if(lc[i] != t[ptr]){
                    ans = 0;
                    break;
                }
                ptr = (ptr + 1) % int(t.size());
            }
            if(!ans || !ptr)
                break;
        }
        if(ans)
            cout << lc << endl;
        else
            cout << -1 << endl;
    }
}
