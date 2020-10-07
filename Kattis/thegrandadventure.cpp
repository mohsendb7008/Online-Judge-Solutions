#include <bits/stdc++.h>
using namespace std;

// The Grand Adventure

int n;
string a;
stack<char> s;

int main(){
    int n;
    cin >> n;
    while(n--){
        cin >> a;
        while(!s.empty())
            s.pop();
        bool ok = true;
        for(char c : a){
            if(c == 'b'){
                if(!s.empty() && s.top() == '$')
                    s.pop();
                else{
                    ok = false;
                    break;
                }
            }
            else if(c == 'j'){
                if(!s.empty() && s.top() == '*')
                    s.pop();
                else{
                    ok = false;
                    break;
                }
            }
            else if(c == 't'){
                if(!s.empty() && s.top() == '|')
                    s.pop();
                else{
                    ok = false;
                    break;
                }
            }
            else if(c != '.')
                s.push(c);
        }
        if(!ok)
            cout << "NO" << endl;
        else if(s.empty())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}