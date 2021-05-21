#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 3;

int n, a[maxn];
vector<int> lis;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++){
        auto it = upper_bound(lis.begin(), lis.end(), a[i]);
        if(it == lis.end())
            lis.push_back(a[i]);
        else
            *it = a[i];
    }
    cout << lis.size() << endl;
}