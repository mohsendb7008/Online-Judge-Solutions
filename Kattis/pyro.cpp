#include <bits/stdc++.h>
using namespace std;

// Pyro Tubes

#define num long long int

const num maxn = 25e4 + 1;

bitset<maxn> tubes; 
vector<num> v, a;

int main(){
    tubes.reset();
    num x;
    while(1){
        cin >> x;
        if(x == -1)
            break;
        tubes[x] = 1;
        v.push_back(x);
    }
    for(num x : v){
        num ans = 0;
        for(num i = 0; i < 18; i++){
            num now1 = x;
            if(now1 & (1ll << i))
                now1 -= (1ll << i);
            else
                now1 += (1ll << i);
            if(now1 > x && now1 < maxn && tubes[now1])
                ans++;
            for(num j = i + 1; j < 18; j++){
                num now2 = now1;
                if(now2 & (1ll << j))
                    now2 -= (1ll << j);
                else
                    now2 += (1ll << j);
                if(now2 > x && now2 < maxn && tubes[now2])
                    ans++;
            }
        }
        a.push_back(ans);
    }
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << ":" << a[i] << endl;
}