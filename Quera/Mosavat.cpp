#include <bits/stdc++.h>
using namespace std;

int n, a[23];
set<int> s;

int main(){
    cin >> n;
    if(n >= 20){
        cout << "YAY!" << endl;
        return 0;
    }
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int mask = 1; mask < (1 << n); mask++){
        int sum = 0;
        for(int i = 0; i < n; i++)
            if(mask & (1 << i))
                sum += a[i];
        if(s.find(sum) != s.end()){
            cout << "YAY!" << endl;
            return 0;
        }
        s.insert(sum);
    }
    cout << "AWW!" << endl;
}