#include <bits/stdc++.h>
using namespace std;

// Statistics

int n;
int a[33];

int main(){
    int test = 1;
    while(cin >> n){
        for(int i = 0; i < n; i++)
            cin >> a[i];
        auto ans = minmax_element(a, a+n);
        cout << "Case " << test++ << ": " << *ans.first << " " << *ans.second << " " << *ans.second - *ans.first << endl;
    }
}