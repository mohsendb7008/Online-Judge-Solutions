#include <bits/stdc++.h>
using namespace std;

struct cmd{
    string str;
    int index;
    char value;
};

vector<char> v;
stack<cmd> st;

int main(){
    int q;
    cin >> q;
    while(q--){
        string s;
        cin >> s;
        if(s == "insert"){
            cmd c;
            c.str = s;
            cin >> c.index;
            cin >> c.value;
            st.push(c);
        }
        else if(s == "delete"){
            cmd c;
            c.str = s;
            cin >> c.index;
            st.push(c);
        }
        else if(s == "undo"){
            st.pop();
        }
    }
    stack<cmd> s2;
    while(!st.empty()){
        s2.push(st.top());
        st.pop();
    }
    while(!s2.empty()){
        cmd cm = s2.top();
        if(cm.str == "insert")
            v.insert(v.begin()+cm.index-1, cm.value);
        else if(cm.str == "delete")
            v.erase(v.begin()+cm.index-1);
        s2.pop();
    }
    for(char c: v)
        cout << c;
    cout << endl;
}