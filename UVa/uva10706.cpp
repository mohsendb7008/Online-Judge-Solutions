#include <bits/stdc++.h>
using namespace std;

// Number Sequence

#define num long long int

inline string build(num l){
    string s = "";
    for(num i = 1; i <= l; i++)
        s += to_string(i);
    return s;
}

vector<num> seq;

int main(){
    num last = 1, inc = 1, cnt = 2;
    seq.push_back(1);
    while(true){
        if(floor(log10(cnt)) == log10(cnt))
            inc++;
        num now = last + inc;
        last = now;
        now += seq[seq.size()-1];
        if(now > 3000000000)
            break;
        seq.push_back(now);
        cnt++;
    }
    int t;
    cin >> t;
    while(t--){
        num i;
        cin >> i;
        if(i == 1){
            cout << 1 << endl;
            continue;
        }
        auto lo = lower_bound(seq.begin(), seq.end(), i);
        auto hi = upper_bound(seq.begin(), seq.end(), i);
        if(*lo == i){
            num len = *lo - *prev(lo);
            string ans = build(len);
            cout << ans[ans.size()-1] << endl;
        }
        else{
            auto pr = prev(hi);
            num len = *hi - *pr;
            string ans = build(len);
            cout << ans[i - *pr - 1] << endl;
        }
    }
}