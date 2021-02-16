#include <bits/stdc++.h>
using namespace std;

int n, q;
set<int> a[2003];

int main(){
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
        a[i].insert(i);
    while(q--){
        int c;
        cin >> c;
        if(c == 1){
            int s, t;
            cin >> s >> t;
            for(int i : a[s])
                a[t].insert(i);
            a[s].clear();
        }else if(c == 2){
            int s;
            cin >> s;
            cout << a[s].size() << endl;
        }else if(c == 3){
            int s;
            cin >> s;
            if(a[s].size()){
                for(int i : a[s])
                    cout << i << " ";
                cout << endl;
            }
            else cout << -1 << endl;
        }
    }
}