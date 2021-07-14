#include <bits/stdc++.h>
using namespace std;

// Prerequisites?

int k, m, c, r, x;
set<int> freddie;

int main(){
    while(1){
        cin >> k;
        if(!k)
            break;
        cin >> m;
        freddie.clear();
        while(k--){
            cin >> x;
            freddie.insert(x);
        }
        bool ans = 1;
        while(m--){
            cin >> c >> r;
            int cnt = 0;
            while(c--){
                cin >> x;
                if(freddie.find(x) != freddie.end())
                    cnt++;
            }
            if(cnt < r)
                ans = 0;
        }
        cout << (ans ? "yes" : "no") << endl;
    }
}