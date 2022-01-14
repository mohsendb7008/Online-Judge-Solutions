// Joint Jog Jam

#include <bits/stdc++.h>
using namespace std;

pair<int, int> readPoint(){
    int x, y;
    cin >> x >> y;
    return {x, y};
}

double dist(pair<int, int> p, pair<int, int> q){
    return hypot(p.first - q.first, p.second - q.second);
}

int main(){
    auto sk = readPoint();
    auto so = readPoint();
    auto ek = readPoint();
    auto eo = readPoint();
    cout << fixed << setprecision(10) << max(dist(sk, so), dist(ek, eo)) << endl;
}
