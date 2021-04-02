#include<bits/stdc++.h>
using namespace std;

// Racing Around the Alphabet

map<char, int> m;

int main(){
    for(char a = 'A'; a <= 'Z'; a++)
        m[a] = a - 'A';
    m[' '] = 26, m['\''] = 27;
    cout << fixed << setprecision(10);
    int n;
    cin >> n;
    cin.ignore();
    while(n--){
        string s;
        getline(cin, s);
        double ans = s.size();
        for(int i = 0; i < s.size() - 1; i++){
            int d = min((m[s[i]] - m[s[i + 1]] + 28) % 28, (m[s[i + 1]] - m[s[i]] + 28) % 28);
            ans  += (double(d) / 7) * M_PI;
        }
        cout << ans << endl;
    }
}