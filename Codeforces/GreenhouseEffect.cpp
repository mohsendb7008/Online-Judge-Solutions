#include <bits/stdc++.h>
using namespace std;

int n, m, s[5003];
double x[5003];
vector<int> lis;

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> s[i] >> x[i];
    for(int i = 0; i < n; i++){
        auto it = upper_bound(lis.begin(), lis.end(), s[i]);
        if(it == lis.end())
            lis.push_back(s[i]);
        else
            *it = s[i];
    }
    cout << n - lis.size() << endl;
}