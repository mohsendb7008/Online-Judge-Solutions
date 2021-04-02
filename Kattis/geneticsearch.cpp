#include <bits/stdc++.h>
using namespace std;

// Genetic Search

int n, m;
string a, b;
set<string> s;

inline int sub(string a){
    int ans = 0, n = a.size();
    for(int i = 0; i <= m - n; i++)
        if(b.substr(i, n) == a)
            ans++;
    return ans;
}

string dna[4]{"A", "C", "G", "T"};

int main(){
    while(cin >> a){
        if(a == "0")
            break;
        cin >> b;
        n = a.size(), m = b.size();
        int ans = sub(a), ansd = 0, ansi = 0;
        s.clear();
        for(int d = 0; d < n; d++){
            string c = a.substr(0, d) + a.substr(d + 1);
            if(s.find(c) == s.end())
                ansd += sub(c), s.insert(c);
        }
        if(n < m){
            for(int i = 0; i < 4; i++){
                string c = a + dna[i];
                if(s.find(c) == s.end())
                    ansi += sub(c), s.insert(c);
                for(int j = 0; j < n; j++){
                    string c = a.substr(0, j) + dna[i] + a.substr(j);
                    if(s.find(c) == s.end())
                        ansi += sub(c), s.insert(c);
                }
            }
        }
        cout << ans << " " << ansd << " " << ansi << endl;
    }
}