#include <bits/stdc++.h>
using namespace std;

// Cryptographer's Conundrum

char help[4] = "PER";

int main(){
    string ridic;
    cin >> ridic;
    int ans = 0;
    for(int i = 0; i < ridic.size(); i++)
        if(ridic[i] != help[i%3])
            ans++;
    cout << ans << endl;
}