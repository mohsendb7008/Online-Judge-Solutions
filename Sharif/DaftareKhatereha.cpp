#include <bits/stdc++.h>
using namespace std;

#define num long long int

const num mod = 1e9 + 7;

int n, b[1003], r[1003], taken[1003];

int main(){
    int sum = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> b[i] >> r[i], sum += b[i];
    if(n == 1){
        cout << 1 << endl;
        return 0;
    }
    num ans = 1;
    int i = 0, j = n - 1, lsum = 0, rsum = 0;
    while(i <= j){
        if(lsum == rsum)
            ans = (ans * 2) % mod;
        if(lsum <= rsum){
            for(int k = 0; k < n; k++)
                if(!taken[k] && (r[k] == sum - lsum || r[k] - b[k] == lsum)){
                    lsum += b[k];
                    taken[k] = 1;
                    break;
                }
            i++;
        }
        else{
            for(int k = 0; k < n; k++)
                if(!taken[k] && (r[k] == sum - rsum || r[k] - b[k] == rsum)){
                    rsum += b[k];
                    taken[k] = 1;
                    break;
                }
            j--;
        }
    }
    cout << ans << endl;
}