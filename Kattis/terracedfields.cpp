#include <bits/stdc++.h>
using namespace std;

// Terraced Fields

#define num long long int

map<num, num> seMem;

num se(num x){
    auto it = seMem.find(x);
    if(it != seMem.end())
        return it->second;
    string str = to_string(x);
    int d = str.size();
    string niness = "";
    for(int i = 0; i < d-1; i++)
        niness += "9";
    num nines = stoll(niness);
    num ans = se(nines);
    int a = str[0] - '0';
    num b = stoll(str.substr(1));
    ans += (a == 6 || a == 8) * (b + 1) + se(b);
    for(int k = 1; k < a; k++)
        ans += (k == 6 || k == 8) * (nines + 1) + se(nines);
    return seMem[x] = ans;
}

map<num, num> sefMem;

num sef(num x){
    auto it = sefMem.find(x);
    if(it != sefMem.end())
        return it->second;
    string str = to_string(x);
    int d = str.size();
    string niness = "";
    for(int i = 0; i < d-1; i++)
        niness += "9";
    num nines = stoll(niness);
    num ans = sef(nines);
    int a = str[0] - '0';
    num b = stoll(str.substr(1));
    ans += (a == 6 || a == 8) * (b/4 + 1) + sef(b);
    for(int k = 1; k < a; k++)
        ans += (k == 6 || k == 8) * (nines/4 + 1) + sef(nines);
    return sefMem[x] = ans;
}

num f[10]{0, 1, 2, 2, 2, 2, 3, 4, 4, 4};

int main(){

    for(int i = 0; i <= 5; i++)
        seMem[i] = 0;
    seMem[6] = seMem[7] = 1;
    seMem[8] = seMem[9] = 2;

    for(int i = 0; i <= 7; i++)
        sefMem[i] = 0;
    sefMem[8] = sefMem[9] = 1;
    for(int i = 10; i <= 99; i++){
        sefMem[i] = sefMem[i-1];
        if(i % 4 == 0)
            sefMem[i] += ((i % 10 == 6) || (i % 10 == 8)) + ((i / 10 == 6) || (i / 10 == 8));
    }
    
    num t, n;
    cin >> t;
    while(t--){
        cin >> n;
        if(n < 10){
            cout << (n == 6 || n >= 8) << endl;
            continue;
        }
        num ans = 0;
        if(n % 8){
            string str = to_string(n);
            for(char c : str)
                ans += (c == '6' || c == '8');
            while(n % 8)
                n--;
        }
        ans += (n / 80) * 4 + f[(n % 80) / 8];
        ans += se(n/10);
        if(n%10 == 8)
            ans += sef(n/10);
        else
            ans += sef(n/10-1);
        cout << ans << endl;
    }

}