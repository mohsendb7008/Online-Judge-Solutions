#include <bits/stdc++.h>
using namespace std;

// Card Trick

int n, ans[15];
deque<int> pack;

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++)
            pack.push_back(i);
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < i; j++)
                pack.push_back(pack.front()), pack.pop_front();
            ans[pack.front()] = i;
            pack.pop_front();
        }
        for(int i = 0; i < n; i++)
            cout << ans[i] << " \n"[i == n-1];
    }
}