#include <bits/stdc++.h>
using namespace std;

// I'm Thinking of a Number

int n;
vector<int> divis;

int main(){
    while(1){
        cin >> n;
        if(!n)
            break;
        divis.clear();
        string s, d;
        int x, l = 1, r = INT_MAX;
        while(n--){
            cin >> s >> d >> x;
            if(s == "less")
                r = min(r, x - 1);
            else if(s == "greater")
                l = max(l, x + 1);
            else
                divis.push_back(x);
        }
        if(r == INT_MAX){
            cout << "infinite" << endl;
            continue;
        }
        bool ans = 0;
        for(int y = l; y <= r; y++){
            bool ok = 1;
            for(int d : divis)
                if(y % d){
                    ok = 0;
                    break;
                }
            if(ok)
                ans = 1, cout << y << " ";
        }
        if(!ans)
            cout << "none";
        cout << endl;
    }
}