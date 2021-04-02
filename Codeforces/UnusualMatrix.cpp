#include <bits/stdc++.h>
using namespace std;

int n, a[1003][1003];

inline bool equal(int i, int j){
    for(int k = 0; k < n; k++)
        if(a[i][k] != a[j][k])
            return false;
    return true;
}

inline bool equal_to_not(int i, int j){
    for(int k = 0; k < n; k++)
        if(1 - a[i][k] != a[j][k])
            return false;
    return true;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        char ch;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++){
                cin >> ch;
                a[i][j] = ch == '1';
            }
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++){
                cin >> ch;
                if(ch == '1')
                    a[i][j] = 1 - a[i][j];
            }
        if(n == 1){
            cout << "YES" << endl;
            continue;
        }
        bool ans = true;
        for(int i = 1; i < n; i++)
            if(!equal(0, i) && !equal_to_not(0, i)){
                ans = false;
                break;
            }
        cout << (ans ? "YES" : "NO") << endl;
    }
}