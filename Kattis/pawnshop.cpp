#include <bits/stdc++.h>
using namespace std;

// Pawn Shop

const int maxn = 3e5 + 3;

int n, a[maxn], b[maxn];
map<int, int> balance;
set<int> non_zeroes, ans;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    for(int i = 0; i < n; i++){
        balance[a[i]]++;
        balance[b[i]]--;
        if(balance[a[i]]){
            non_zeroes.insert(a[i]);
        }else{
            non_zeroes.erase(a[i]);
        }
        if(balance[b[i]]){
            non_zeroes.insert(b[i]);
        }else{
            non_zeroes.erase(b[i]);
        }
        if(non_zeroes.empty()){
            ans.insert(i);
        }
    }
    for(int i = 0; i < n; i++){
        cout << b[i] << " ";
        if(i != n-1 && ans.find(i) != ans.end()){
            cout << "# ";
        }
    }
    cout << endl;
}