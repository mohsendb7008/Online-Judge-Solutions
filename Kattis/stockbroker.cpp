#include <bits/stdc++.h>
using namespace std;

// Daydreaming Stockbroker

int n;
long long days[365 + 3];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> days[i];
    long long int ans = 100;
    int prevy = 0;
    for(int i = 0; i < n; i++){
        if(i == prevy)
            continue;
        else if(days[i] <= days[prevy])
            prevy++;
        else if(i == n-1 || days[i+1] < days[i]){
            long long int share = min(ans / days[prevy], 100000ll);
            ans -= share * days[prevy];
            ans += share * days[i];
            prevy = i + 1;
        }
    }
    cout << ans << endl;
}