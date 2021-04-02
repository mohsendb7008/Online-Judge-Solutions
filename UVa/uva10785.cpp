#include <bits/stdc++.h>
using namespace std;

// The Mad Numerologist

char v[6] = "AUEOI";
char c[22] = "JSBKTCLDMVNWFXGPYHQZR";
string solve(int n){
    string str1 = "", str2 = "";
    int n1 = n / 2 + n % 2, n2 = n / 2;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < min(21, n1); j++)
            str1 += v[i];
        n1 -= min(21, n1);
    }
    for(int i = 0; i < 21; i++){
        for(int j = 0; j < min(5, n2); j++)
            str2 += c[i];
        n2 -= min(5, n2);
    }
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    string str = "";
    for(int i = 0; i < str1.size()-1; i++)
        str += str1[i], str += str2[i];
    if(n % 2)
        str += str1[str1.size()-1];
    else str += str1[str1.size()-1], str += str2[str1.size()-1];
    return str;
}

int main(){
    int N, X;
    cin >> N;
    for(int c = N; c > 0; c--){
        cin >> X;
        cout << "Case " << (N-c+1) << ": " << solve(X) << endl;
    }
}