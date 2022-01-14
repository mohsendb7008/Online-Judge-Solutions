// Marko

#include <bits/stdc++.h>
using namespace std;

string t9 = "22233344455566677778889999";

int n;
string dic[1003], s;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> dic[i];
    }
    cin >> s;
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(dic[i].size() == s.size()){
            int ok = 1;
            for(int j = 0; j < s.size(); j++){
                if(t9[dic[i][j]-'a'] != s[j]){
                    ok = 0;
                    break;
                }
            }
            ans += ok;
        }
    }
    cout << ans << endl;
}