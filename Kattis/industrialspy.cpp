#include <bits/stdc++.h>
using namespace std;

// An Industrial Spy

#define num long long int

const int maxn = 1e7;

bitset<maxn> pf;
int tc, n;
string s, t;
set<int> ans;

int main(){
    pf.set();
    pf[0] = pf[1] = 0;
    for(num p = 2; p < maxn; p++)
        if(pf[p])
            for(num q = p * p; q < maxn; q += p)
                pf[q] = 0;
    cin >> tc;
    while(tc--){
        cin >> s;
        n = s.size();
        ans.clear();
        for(int mask = 1; mask < (1 << n); mask++){
            t = "";
            for(int i = 0; i < n; i++)
                if(mask & (1 << i))
                    t.push_back(s[i]);
            sort(t.begin(), t.end());
            do{
                int x = stoi(t);
                if(pf[x])
                    ans.insert(x);
            }while(next_permutation(t.begin(), t.end()));
        }
        cout << ans.size() << endl;
    }
}