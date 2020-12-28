#include <bits/stdc++.h>
using namespace std;

int n, q, ans = 0;
string tmp;
set<string> st;

int main(){
    cin >> n;
    cin.ignore();
    for(int i = 0; i < n; i++)
        getline(cin, tmp);
    cin >> q;
    cin.ignore();
    for(int i = 0; i < q; i++){
        getline(cin, tmp);
        st.insert(tmp);
        if(st.size() == n)
            ans++, st.clear(), st.insert(tmp);
    }
    cout << ans << endl;
}