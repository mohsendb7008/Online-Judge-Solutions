#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> v;

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        v.push_back(i);
    int ans = 0;
    do{
        int inv = 0;
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
                if(v[i] > v[j])
                    inv++;
        if(inv == k)
            ans++;
    }while(next_permutation(v.begin(), v.end()));
    cout << ans << endl;
}