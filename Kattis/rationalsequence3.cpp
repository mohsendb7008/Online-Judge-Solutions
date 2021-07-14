#include <bits/stdc++.h>
using namespace std;

// A Rational Sequence (Take 3)

vector<char> path;

int main(){
    int t;
    cin >> t;
    while(t--){
        int k, n;
        cin >> k >> n;
        cout << k << " ";
        path.clear();
        while(n != 1){
            if(n % 2)
                path.push_back('R');
            else
                path.push_back('L');
            n /= 2;
        }
        reverse(path.begin(), path.end());
        int p = 1, q = 1;
        for(char c : path){
            if(c == 'L')
                q += p;
            else if(c == 'R')
                p += q;
        }
        cout << p << "/" << q << endl;
    }
}