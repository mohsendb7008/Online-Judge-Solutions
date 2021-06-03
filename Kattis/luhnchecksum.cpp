#include <bits/stdc++.h>
using namespace std;

// Luhn's Checksum Algorithm

int luhn[10]{0, 2, 4, 6, 8, 1, 3, 5, 7, 9};

int main(){
    int t;
    cin >> t;
    while(t--){
        string n;
        cin >> n;
        reverse(n.begin(), n.end());
        int sum = 0;
        for(int i = 0; i < n.size(); i++){
            if(i % 2)
                sum += luhn[n[i]-'0'];
            else
                sum += n[i]-'0';
        }
        cout << ((sum % 10) ? "FAIL" : "PASS") << endl;
    }
}