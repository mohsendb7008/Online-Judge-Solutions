#include <bits/stdc++.h>
using namespace std;

// Parliament

vector<int> seq;

inline int f(int n){
    return (n * (n+1)) / 2 - 1;
}

int main(){
    int i = 2;
    while(f(i) <= 10000)
        seq.push_back(f(i++));
    int t, n;
    cin >> t;
    bool first = true;
    while(t--){
        if(!first)
            cout << endl;
        first = false;
        cin >> n;
        auto it = lower_bound(seq.begin(), seq.end(), n);
        int head = it - seq.begin() + 2;
        int d = *it - n;
        if(d == 1){
            for(int i = 3; i < head; i++)
                cout << i << " ";
            cout << head + 1 << endl;
           
        }
        else{
            for(int i = 2; i < head; i++)
                if(i != d)
                    cout << i << " ";
            cout << head << endl;
        }
    }    
}