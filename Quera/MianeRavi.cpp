#include <bits/stdc++.h>
using namespace std;

priority_queue<int> l;
priority_queue<int, vector<int>, greater<int>> r;
int q, x;

int main(){
    cin >> q;
    for(int i = 0; i < q; i++){
        cin >> x;
        if(i == 0)
            l.push(x);
        else if(i == 1){
            if(x >= l.top())
                r.push(x);
            else
                r.push(l.top()), l.pop(), l.push(x);
        }
        else if(i % 2 == 0){
            if(x <= l.top())
                l.push(x);
            else
                r.push(x), l.push(r.top()), r.pop();
        }
        else{
            if(x > l.top())
                r.push(x);
            else
                l.push(x), r.push(l.top()), l.pop();
        }
        cout << l.top() << endl;
    }
}