#include <bits/stdc++.h>
using namespace std;

// Mancala

int t, k, n;
vector<int> ans;

int main(){
    cin >> t;
    while(t--){
        cin >> k >> n;
        ans.clear();
        while(n--){
            int z = -1;
            for(int i = 0; i < ans.size(); i++){
                if(ans[i])
                    ans[i]--;
                else{
                    z = i;
                    break;
                }
            }
            if(z == -1)
                ans.push_back(ans.size() + 1);
            else
                ans[z] = z + 1;
        }
        cout << k << " " << ans.size() << endl;
        for(int i : ans)
            cout << i << " ";
        cout << endl;
    }
}