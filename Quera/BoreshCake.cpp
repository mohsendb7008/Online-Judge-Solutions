#include <bits/stdc++.h>
using namespace std;

int n[2], q, x, i;
set<int> cuts[2];
multiset<int> pieces[2];
char c;

int main(){
    cin >> n[0] >> n[1] >> q;
    cuts[0].insert(0), cuts[0].insert(n[0]), pieces[0].insert(n[0]);
    cuts[1].insert(0), cuts[1].insert(n[1]), pieces[1].insert(n[1]);
    while(q--){
        cin >> c >> x, i = (c == 'H');
        if(x > 0 && x < n[i]){
            auto hi = cuts[i].upper_bound(x), lo = prev(hi);
            pieces[i].erase(pieces[i].find(*hi - *lo));
            pieces[i].insert(x - *lo), pieces[i].insert(*hi - x);
            cuts[i].insert(x);
        }
        cout << ((long long int) *prev(pieces[0].end())) * ((long long int) *prev(pieces[1].end())) << endl;
    }
}