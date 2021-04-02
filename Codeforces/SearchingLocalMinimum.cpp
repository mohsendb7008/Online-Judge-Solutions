#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int lo = 0, hi = n-1;
    while(lo < hi){
        int mid = (lo + hi) / 2;
        int amid, amid1, amid2;
        cout << "? " << mid + 1 << endl;
        cout.flush();
        cin >> amid;
        if(mid){
            cout << "? " << mid << endl;
            cout.flush();
            cin >> amid1;
            if(amid > amid1){
                hi = mid - 1;
                continue;
            }
        }
        if(mid < n-1){
            cout << "? " << mid + 2 << endl;
            cout.flush();
            cin >> amid2;
            if(amid > amid2){
                lo = mid + 1;
                continue;
            }
        }
        cout << "! " << mid + 1 << endl;
        cout.flush();
        return 0;
    }
    cout << "! " << lo + 1 << endl;
    cout.flush();
}