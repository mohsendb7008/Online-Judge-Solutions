#include <bits/stdc++.h>
using namespace std;

// Train Swapping

int n;
int seq[53];

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> seq[i];
        int cnt = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n-1; j++)
                if(seq[j] > seq[j+1]){
                    swap(seq[j], seq[j+1]);
                    cnt++;
                }
        cout << "Optimal train swapping takes " << cnt << " swaps." << endl;
    }
}