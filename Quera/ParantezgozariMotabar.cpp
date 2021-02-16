#include <bits/stdc++.h>
using namespace std;

string str;
stack<int> s;
vector<pair<int, int>> ans;

int main(){
    cin >> str;
    for(int i = 0; i < str.size(); i++){
        if(str[i] == '(')
            s.push(i);
        else if(str[i] == ')'){
            if(s.empty()){
                cout << -1 << endl;
                return 0;
            }
            ans.push_back({s.top(), i});
            s.pop();
        }
    }
    if(!s.empty())
        cout << -1 << endl;
    else{
        for(pair<int, int> p : ans)
            cout << p.first + 1 << " " << p.second + 1 << endl;
    }
}