#include <bits/stdc++.h>
using namespace std;

// Random Digital Exponentiation

#define num long long int

string a;
int n, ans[13];
num b;

bool track(int i, num b, num e){
    if(i == n){
        if(!b){
            for(int i = 0; i < n; i++)
                cout << ans[i] << " ";
            cout << endl;
            return true;
        }
        return false;
    }
    num ac = 1;
    for(int c = 0; 1; c++){
        if(a[i] == '0' && c == 0){
            ac = 0;
            continue;
        }
        if(ac > b)
            break;
        num k = ac * e;
        if(k > b)
            break;
        ans[i] = c;
        if(track(i + 1, b - k, e / 10))
            return true;
        ac *= a[i] - '0';
    }
    return false;
}

int main(){
    cin >> a >> b, n = a.size();
    track(0, b, pow(10, n - 1));
}