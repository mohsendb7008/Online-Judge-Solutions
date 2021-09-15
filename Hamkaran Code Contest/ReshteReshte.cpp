#include <bits/stdc++.h>
using namespace std;

int n, k;
string s[53], t[53];

inline bool add(const string& a, const string& b){
    for(int i = 0; i < a.size(); i++){
        string s = a.substr(0, i) + a.substr(i + 1);
        if (s == b)
            return true;
    }
    return false;
}

inline bool same(const string& a, const string& b){
    if(a.size() == b.size()) {
        int diff = 0;
        for(int i = 0; i < a.size(); i++)
            if(tolower(a[i]) != tolower(b[i]))
                diff++;
        if (!diff)
            return true;
        diff = 0;
        for(int i = 0; i < a.size(); i++)
            if(a[i] != b[i])
                diff++;
        return diff <= 1;
    }
    if(a.size() == b.size() + 1)
        return add(a, b);
    if(a.size() + 1 == b.size())
        return add(b, a);
    return false;
}

int main() {
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> s[i];
    for(int i = 0; i < k; i++)
        cin >> t[i];
    for(int i = 0; i < k; i++){
        int ans = 0;
        for(int j = 0; j < n; j++)
            if(same(t[i], s[j]))
                ans++;
        cout << ans << endl;
    }
}