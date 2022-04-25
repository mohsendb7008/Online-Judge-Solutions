#include<bits/stdc++.h>
using namespace std;

// Slide Count

const int maxn = 1e5 + 3;

int n, c, a[maxn], ans[maxn];
vector<int> ends_;

int main(){
    cin >> n >> c;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int s = 0, e = -1;
    int sum = 0;
    while(s < n){
        bool start_inc = false;
        if(e == n-1){
            sum -= a[s];
            s++;
            start_inc = true;
        }
        else if(sum + a[e+1] > c){
            sum -= a[s];
            s++;
            start_inc = true;
        }
        else{
            e++;
            sum += a[e];
        }
        ends_.push_back(e);
        if(start_inc){
            auto it = lower_bound(ends_.begin(), ends_.end(), s-1);
            ans[s-1] = distance(it, ends_.end()) - 1;
        }
    }
    for(int i = 0; i < n; i++){
        cout << ans[i] << endl;
    }
}