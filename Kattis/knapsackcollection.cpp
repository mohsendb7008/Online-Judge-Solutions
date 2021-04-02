#include <bits/stdc++.h>
using namespace std;

// Knapsack Collection

#define num long long int

const int maxs = 1e7 + 3;

int n, s, t, a[2003];
set<int> knapsacks;
multiset<int> carousel;
num ans[maxs], sum = 0;

inline num gcd(num a, num b){
    if(!b)
        return a;
    return gcd(b, a % b);
}

int main(){
    cin >> n >> s >> t;
    for(int i = 0; i < n; i++)
        cin >> a[i], knapsacks.insert(a[i]);
    for(int i : knapsacks){
        for(int i = 0; i < n; i++)
            carousel.insert(a[i]);
        int k = i;
        while(!carousel.empty()){
            auto it = carousel.lower_bound(k);
            if(it == carousel.end())
                ans[i] += s - k, k = 0;
            else
                ans[i] += *it - k + t, k = (*it + t) % s, carousel.erase(it);
        }
        sum += ans[i];
    }
    for(int i = 0; i < s; i++)
        if(!ans[i]){
            auto it = knapsacks.upper_bound(i);
            if(it == knapsacks.end())
                ans[i] = s - i + *knapsacks.begin() + ans[*knapsacks.begin()];
            else
                ans[i] = *it - i + ans[*it];
            sum += ans[i];
        }
    sort(ans, ans + s);
    cout << ans[0] << endl;
    cout << ans[s-1] << endl;
    num ss = s;
    num g = gcd(max(sum, ss), min(sum, ss));
    cout << sum / g << "/" << ss / g << endl;
}