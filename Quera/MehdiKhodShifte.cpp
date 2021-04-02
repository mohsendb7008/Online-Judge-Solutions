#include <bits/stdc++.h>
using namespace std;

int n, m;

bool f(int x1, int y1, int x2, int y2){
    if((x1 + x2 <= n && max(y1, y2) <= m) || (y1 + y2 <= m && max(x1, x2) <= n))
        return true;
    return false;
}

int main(){
    cin >> n >> m;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if(f(x1, y1, x2, y2) || f(x1, y1, y2, x2) || f(y1, x1, x2, y2) || f(y1, x1, y2, x2))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;   
}