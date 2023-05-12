#include <bits/stdc++.h>
using namespace std;

int r = 1;
int cycle = 0;
int ans = 0;

inline void relax(){
    if(cycle == 20 || cycle == 60 || cycle == 100 || cycle == 140 || cycle == 180 || cycle == 220){
        ans += cycle * r;
    }
}

int main(){
    string c;
    int v;
    while(cin >> c){
        if(c == "addx"){
            cin >> v;
            cycle++;
            relax();
            cycle++;
            relax();
            r += v;
        }else if(c == "noop"){
            cycle++;
            relax();
        }
    }
    cout << ans << endl;
}