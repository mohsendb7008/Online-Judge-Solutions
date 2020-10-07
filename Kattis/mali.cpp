#include <bits/stdc++.h>
using namespace std;

// Mali

int n;
int a[103], b[103], ta[103], tb[103];

int solve(){
    copy(a+1, a+101, ta+1);
    copy(b+1, b+101, tb+1);
    int ans = 0, i = 1, j = 100;
    while(i <= 100 && j >= 1){
        if(!ta[i])
            i++;
        else if(!tb[j])
            j--;
        else{
            ans = max(ans, i + j);
            if(ta[i] == tb[j])
                ta[i] = tb[j] = 0, i++, j--;
            else if(ta[i] < tb[j])
                tb[j] -= ta[i], ta[i] = 0, i++;
            else
                ta[i] -= tb[j], tb[j] = 0, j--;
        }
    }
    return ans;
}

int main(){
    fill(a + 1, a + 101, 0);
    fill(b + 1, b + 101, 0);
    cin >> n;
    int x, y;
    while(n--){
        cin >> x >> y;
        a[x]++, b[y]++;
        cout << solve() << endl; 
    }
}