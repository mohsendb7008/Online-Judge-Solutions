#include <bits/stdc++.h>
using namespace std;

// Circuit Math

int n;
bool a[30];
stack<bool> st;

int main(){
    cin >> n;
    char c;
    for(int i = 0; i < n; i++){
        cin >> c;
        a[i] = c == 'T';
    }
    while(cin >> c){
        if(c == '*'){
            bool b1 = st.top();
            st.pop();
            bool b2 = st.top();
            st.pop();
            st.push(b1 && b2);
        }
        else if(c == '+'){
            bool b1 = st.top();
            st.pop();
            bool b2 = st.top();
            st.pop();
            st.push(b1 || b2);
        }
        else if(c == '-'){
            bool b = st.top();
            st.pop();
            st.push(!b);
        }
        else st.push(a[c-'A']);
    }
    cout << (st.top() ? 'T' : 'F') << endl;
}