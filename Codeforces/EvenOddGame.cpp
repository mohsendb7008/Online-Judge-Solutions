#include <bits/stdc++.h>
using namespace std;

#define num long long int

const int maxn = 2e5 + 3;

int n, a[maxn];

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n, greater<int>());
        num alice = 0, bob = 0;
        for(int i = 0; i < n; i++){
            if(i % 2){
                if(a[i] % 2)
                    bob += a[i];
            }
            else{
                if(!(a[i] % 2))
                    alice += a[i];
            }
        }
        if(alice > bob)
            cout << "Alice" << endl;
        else if(alice < bob)
            cout << "Bob" << endl;
        else
            cout << "Tie" << endl;
    }
}
