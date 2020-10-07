#include <bits/stdc++.h>
using namespace std;

// Sum and Product

#define num long long int
const int maxn = 2e5 + 3;

num n;
vector<num> a;
num pr[maxn], ne[maxn];

int main(){
    cin >> n;
    num x, ones = 0;
    while(n--){
        cin >> x;
        if(x == 1)
            ones++;
        else{
            if(!a.empty())
                ne[a.size() - 1] = ones;
            a.push_back(x);
            pr[a.size() - 1] = ones;
            ones = 0;
        }
    }
    if(!a.empty())
        ne[a.size() - 1] = ones;
    n = a.size();
    num ans = 0;
    for(num i = 0; i < n; i++){
        num sum = a[i], mul = a[i];
        for(int j = i + 1; j < n; j++){
            sum += a[j] + pr[j], mul *= a[j];
            if(mul > 2e14)
                break;
            if(sum == mul)
                ans++;
            else if(sum < mul){
                num m = mul - sum, x = min(pr[i], ne[j]), y = max(pr[i], ne[j]);
                if(x + y >= m){
                    if(m < x)
                        ans += m + 1;
                    else 
                        ans += min(x + y - m, x) + 1;
                }
            }
        }        
    }
    cout << ans << endl;
}   