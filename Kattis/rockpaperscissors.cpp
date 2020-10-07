#include <bits/stdc++.h>
using namespace std;

// Rock-Paper-Scissors Tournament

bool who(string p1, string p2){
    if(p1 == "rock"){
        if(p2 == "paper")
            return false;
        if(p2 == "scissors")
            return true;
    }
    if(p1 == "paper"){
        if(p2 == "rock")
            return true;
        if(p2 == "scissors")
            return false;
    }
    if(p1 == "scissors"){
        if(p2 == "rock")
            return false;
        if(p2 == "paper")
            return true;
    }
}

int n, k;
int win[103], lose[103];

bool first = true;

int main(){
    cout << fixed << setprecision(3);
    while(1){
        cin >> n;
        if(!n)
            break;
        if(!first)
            cout << endl;
        first = false;
        cin >> k;
        if(n == 1){
            cout << "-" << endl;
            continue;
        }
        fill_n(win, n, 0), fill_n(lose, n, 0);
        int p1, p2;
        string m1, m2;
        k = (k * n * (n - 1)) / 2;
        while(k--){
            cin >> p1 >> m1 >> p2 >> m2;
            if(m1 == m2)
                continue;
            p1--, p2--;
            if(who(m1, m2))
                win[p1]++, lose[p2]++;
            else win[p2]++, lose[p1]++;
        }
        for(int i = 0; i < n; i++){
            if(win[i] + lose[i] == 0)
                cout << "-" << endl;
            else
                cout << double(win[i]) / (win[i] + lose[i]) << endl;
        }
    }
}