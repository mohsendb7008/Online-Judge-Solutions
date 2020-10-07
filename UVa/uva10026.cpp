#include <bits/stdc++.h>
using namespace std;

// Shoemaker’s problem

struct work{
    int t, s, i;
};

bool cmp(const work& w1, const work& w2){
    double d1 = double(w1.s) / w1.t, d2 = double(w2.s) / w2.t;
    if(d1 == d2)
        return w1.i < w2.i;
    return d1 > d2;
}

int t, n;
work works[1003];
bool first = true;

int main(){
    cin >> t;
    while(t--){
        if(!first)
            cout << endl;
        first = false;
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> works[i].t >> works[i].s, works[i].i = i + 1;
        sort(works, works+n, cmp);
        for(int i = 0; i < n-1; i++)
            cout << works[i].i << " ";
        cout << works[n-1].i << endl;
    }
}