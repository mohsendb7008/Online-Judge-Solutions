#include <bits/stdc++.h>
using namespace std;

// Digits

int main(){
    while(true){
        string str;
        cin >> str;
        if(str == "END")
            break;
        if(str == "1"){
            cout << 1 << endl;
            continue;
        }
        int ans = 2, seq = str.size();
        while(seq > 1)
            seq = to_string(seq).size(), ans++;
        cout << ans << endl;
    }
}