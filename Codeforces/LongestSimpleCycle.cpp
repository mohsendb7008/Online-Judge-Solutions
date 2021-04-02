#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 3;

#define num long long int

int n, a[maxn], b[maxn];
num c[maxn];

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> c[i];
        for(int i = 0; i < n; i++)
            cin >> a[i];
        for(int i = 0; i < n; i++)
            cin >> b[i];
        for(int i = 0; i < n; i++)
            if(a[i] > b[i])
                swap(a[i], b[i]);
        num ans = 0;
        num best_start = b[1] - a[1];
        num progress = 0;
        for(int i = 1; i < n; i++){
            if(a[i] == b[i]){
                best_start = 0;
                progress = 0;
            }
            progress += 2;
            ans = max(ans, best_start + progress + c[i] - 1);
            if(i + 1 < n){
                progress += a[i + 1] - 1;
                progress += c[i] - b[i + 1];
                best_start = max(best_start, b[i + 1] - a[i + 1] - progress);
            }
        }
        cout << ans << endl;
    }
}