#include <bits/stdc++.h>
using namespace std;

// Mr. Plow King

#define num long long int

num n, m;
num needed;
vector<num> v;
num ans = 1;

int main(){
    cin >> n >> m;
    needed = m - (n - 1);
    for(num i = 0; needed; i++){
        v.push_back(min(needed, i));
        needed -= v.back();
    }
    num ind = 1;
    for(int i = 0; i < n - 2; i++){
        ind += ((i < v.size()) ? v[i] : 0) + 1;
        ans += ind;
    }
    cout << ans << endl;
}