#include <bits/stdc++.h>
using namespace std;

string s1, s2, s3, s4, s;

int main(){
    while(1){
        cin >> s1 >> s2 >> s3 >> s4;
        if(s1 == "0000" && s2 == "0000" && s3 == "0000" && s4 == "0000")
            break;
        s = s1 + s2 + s3 + s4;
        int ans = 0;
        for(int i = 0; i < 16; i++){
            int d = s[i] - '0';
            if(!(i % 2))
                d *= 2;
            if(d > 9)
                d -= 9;
            ans += d;
        }
        cout << (ans % 10 ? "No" : "Yes") << endl;
    }
}