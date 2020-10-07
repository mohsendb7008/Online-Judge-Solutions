#include <bits/stdc++.h>
using namespace std;

int n, k;
string s;
set<char> st;

int main(){
    cin >> n >> k;
    cin >> s;
    for(int i = 0; i < s.size(); i++)
        st.insert(s[i]);
    string ans = "";
    if(k > n){
        cout << s;
        for(int i = 0; i < k - n; i++)
            cout << *(st.begin());
        cout << endl;
        return 0;
    }
    int indx;
    for(int i = k - 1; i >= 0; i--)
        if(s[i] != *prev(st.end())){
            indx = i;
            ans = s.substr(0, i);
            auto it = st.upper_bound(s[i]);
            ans += *it;
            break;
        }
    for(int j = indx + 1; j < k; j++)
        ans += *(st.begin());
    cout << ans << endl;
}