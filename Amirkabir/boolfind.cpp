#include <bits/stdc++.h>
using namespace std;

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int n;
        cin >> n;
        int lo = 0, hi = n-1;
        while(lo < hi){
            if(lo == hi - 1){
                break;
            }
            else if(lo == hi - 2){
                cout << "READ " << lo + 1 << endl;
                cout.flush();
                string s1;
                cin >> s1;
                cout << "READ " << lo + 2 << endl;
                cout.flush();
                string s2;
                cin >> s2;
                if(s1 == "true" && s2 == "false")
                    lo++;
                break;
            }
            else{
                int mid = (lo + hi) / 3;
                cout << "READ " << mid << endl;
                cout.flush();
                string s1;
                cin >> s1;
                cout << "READ " << mid + 1 << endl;
                cout.flush();
                string s2;
                cin >> s2;
                if(s1 == "true" && s2 == "true"){
                    lo = mid + 1;
                }
                else if(s1 == "false" && s2 == "false"){
                    hi = mid;
                }
                else if(s1 == "false" && s2 == "true"){
                    hi = mid;
                }
                else if(s1 == "true" && s2 == "false"){
                    lo = mid;
                    break;
                }
            }
        }
        cout << "OUTPUT " << lo << endl;
        cout.flush();
    }
}