#include <bits/stdc++.h>
using namespace std;

vector<string> gray(int n){
    vector<string> ans;
    if(n == 1){
        ans.push_back("0");
        ans.push_back("1");
        return ans;
    }
    vector<string> subp = gray(n-1);
    for(string a : subp)
        ans.push_back("0" + a);
    reverse(subp.begin(), subp.end());
    for(string a : subp)
        ans.push_back("1" + a);
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<string> ans = gray(n);
    for(string a : ans)
        cout << a << endl;
}