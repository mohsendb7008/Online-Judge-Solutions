#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> st;

void track(int i){
    if(i == n){
        for(int a : st)
            cout << a << ' ';
        cout << '\n';
        return;
    }
    for(int j = 1; j <= n; j++){
        st.push_back(j);
        track(i+1);
        st.pop_back();
    }
}

int main(){
    cin >> n;
    track(0);
}