// Tajna

#include <bits/stdc++.h>
using namespace std;

string s;
char g[103][103];

int main(){
    cin >> s;
    int n = s.size();
    int r = 1, c = n;
    for(int i = 2; i <= n; i++){
        if(!(n % i)){
            int j = n / i;
            if(i <= j){
                r = i;
                c = j;
            }
        }
    }
    int ptr = 0;
    for(int j = 0; j < c; j++){
        for(int i = 0; i < r; i++){
            g[i][j] = s[ptr++];
        }
    }
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cout << g[i][j];
        }
    }
    cout << endl;
}
    