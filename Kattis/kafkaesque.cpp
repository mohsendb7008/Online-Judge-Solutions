// Kafkaesque

#include <bits/stdc++.h>
using namespace std;

int k, a[103];

int main(){
    cin >> k;
    for(int i = 0; i < k; i++){
        cin >> a[i];
    }
    int ans = k;
    for(int i = 0; i < k-1; i++){
        if(a[i] < a[i+1]){
            ans--;
        }
    }
    cout << ans << endl;
}