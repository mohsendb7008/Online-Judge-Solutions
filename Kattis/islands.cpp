#include <bits/stdc++.h>
using namespace std;

// 	Islands in the Data Stream

int a[12];

int main(){
    int t;
    cin >> t;
    while(t--){
        int k;
        cin >> k;
        cout << k << " ";
        for(int i = 0; i < 12; i++)
            cin >> a[i];
        int ans = 0;
        for(int i = 1; i <= 10; i++)
            for(int j = i; j <= 10; j++){
                bool p = true;
                for(int k = i; k <= j; k++)
                    if(a[i-1] >= a[k] || a[j+1] >= a[k])
                        p = false;
                if(p)
                    ans++;
            }
        cout << ans << endl;
    }
}