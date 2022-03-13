// Permuted Arithmetic Sequence

#include <bits/stdc++.h>
using namespace std;

inline bool is_arithmeticc(vector<int>& v){
    int n = v.size();
    int d = v[1] - v[0];
    for(int i = 2; i < n; i++){
        if(v[i] - v[i-1] != d){
            return false;
        }
    }
    return true;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, x;
        vector<int> v;
        cin >> n;
        while(n--){
            cin >> x;
            v.push_back(x);
        }
        if(is_arithmeticc(v)){
            cout << "arithmetic" << endl;
        }
        else{
            sort(v.begin(), v.end());
            if(is_arithmeticc(v)){
                cout << "permuted arithmetic" << endl;
            }
            else{
                cout << "non-arithmetic" << endl;
            }
        }
    }
}