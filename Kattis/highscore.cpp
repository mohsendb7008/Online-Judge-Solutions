#include <bits/stdc++.h>
using namespace std;

// High Score

#define num long long int

num a, b, c, d;

num inc[4];
num ans;

void track(int i, num d){
    if(i == 3){
        if(d == 0)
            ans = max(ans, (a + inc[0]) * (a + inc[0]) + (b + inc[1]) * (b + inc[1]) + (c + inc[2]) * (c + inc[2]) + 7 * min(a + inc[0], min(b + inc[1], c + inc[2])));
        return;
    }
    for(num j = 0; j <= d; j++){
        inc[i] = j;
        track(i+1, d-j);
    }
}

num solve(){
    if(d > 10)
        return (c + d) * (c + d) + b * b + a * a + 7 * min(c + d, min(a, b));
    ans = 0;
    track(0, d);
    return ans;
}

vector<num> tmp;

int main(){
    int n;
    cin >> n;
    while(n--){
        cin >> a >> b >> c >> d;
        tmp.clear();
        tmp.push_back(a);
        tmp.push_back(b);
        tmp.push_back(c);
        sort(tmp.begin(), tmp.end());
        a = tmp[0];
        b = tmp[1];
        c = tmp[2];
        cout << solve() << endl;
    }
}