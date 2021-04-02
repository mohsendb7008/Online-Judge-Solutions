#include <bits/stdc++.h>
using namespace std;

// Left and Right

int n;
string s;
stack<int> st;

int main(){
    cin >> n >> s;
    for(int i = 0; i < n - 1; i++){
        if(s[i] == 'R'){
            cout << i + 1 << endl;
            while(!st.empty())
                cout << st.top() + 1 << endl, st.pop();
        }
        else st.push(i);
    }
    cout << n << endl;
    while(!st.empty())
        cout << st.top() + 1 << endl, st.pop();
}