#include <bits/stdc++.h>
using namespace std;

// Quick Brown Fox

string s;
bool p[29];

int main(){
    int n;
    cin >> n;
    getline(cin, s);
    while(n--){
        for(int i = 0; i < 29; i++)
            p[i] = 0;
        getline(cin, s);
        string ss = "";
        for(int i = 0; i < s.size(); i++)
            if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
                ss += tolower(s[i]);
        for(int i = 0; i < ss.size(); i++)
            p[ss[i] - 'a'] = 1;
        bool b = true;
        for(int i = 0; i < 26; i++)
            if(!p[i]){
                b = false;
                break;
            }
        if(b)
            cout << "pangram";
        else{
            cout << "missing ";
            for(int i = 0; i < 26; i++)
                if(!p[i])
                    cout << char(i + 'a');   
        }
        cout << endl;
    }
}