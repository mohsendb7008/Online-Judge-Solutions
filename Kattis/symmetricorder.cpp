#include <bits/stdc++.h>
using namespace std;

// Symmetric Order

int n;
stack<string> st;

int main(){
    int i = 1;
    while(1){
        cin >> n;
        if(!n)
            break;
        cout << "SET " << i++ << '\n';
        for(int i = 0; i < n; i++){
            string s;
            cin >> s;
            if(i % 2)
                st.push(s);
            else
                cout << s << '\n';
        }
        while(!st.empty())
            cout << st.top() << '\n', st.pop();
    }
}