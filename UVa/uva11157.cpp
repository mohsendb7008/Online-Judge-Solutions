#include <bits/stdc++.h>
using namespace std;

// Dynamic Frog

int n, d, ans;
pair<char, int> frogs[103];

void compute_smalls(int start, int endd){
    int prevy = start;
    for(int i = start + 1; i < endd; i++)
        if(!(i % 2)){
            ans = max(ans, frogs[i].second - frogs[prevy].second);
            prevy = i;
        }
    ans = max(ans, frogs[endd].second - frogs[prevy].second);
    prevy = endd;
    for(int i = endd - 1; i > start; i--)
        if(i % 2){
            ans = max(ans, frogs[prevy].second - frogs[i].second);
            prevy = i;
        }
    ans = max(ans, frogs[prevy].second - frogs[start].second);
}

int main(){
    int t, m;
    char c, cc;
    cin >> t;
    for(int test = 1; test <= t; test++){
        cin >> n >> d;
        frogs[0] = {'B', 0};
        for(int i = 1; i <= n; i++){
            cin >> c >> cc >> m;
            frogs[i] = {c, m};
        }
        frogs[n+1] = {'B', d};
        n += 2;
        ans = 0;
        int prevy = 0;
        for(int i = 1; i < n; i++){
            if(frogs[i].first == 'S')
                continue;
            if(i != prevy + 1)
                compute_smalls(prevy, i);
            else 
                ans = max(ans, frogs[i].second - frogs[prevy].second);
            prevy = i;
        }
        cout << "Case " << test << ": " << ans << endl;
    }
}