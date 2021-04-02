#include <bits/stdc++.h>
using namespace std;

// Typo

const int maxn = 1e6 + 3;

const long long int p = 31, m = 1e9 + 7;

int n;
long long int pp[maxn], hashl[maxn], hashr[maxn];
string words[maxn];
set<pair<int, long long int>> s;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> words[i];
    for(int i = 0; i < n; i++){
        long long int hash = 0;
        for(char c : words[i])
            hash = ((hash * p) % m + c - 'a' + 1) % m;
        s.insert({words[i].size(), hash});
    }
    pp[0] = 1;
    for(int i = 1; i < maxn; i++)
        pp[i] = (pp[i-1] * p) % m;
    bool typos = false;
    for(int i = 0; i < n; i++)
        if(words[i].size() > 1){
            hashl[0] = words[i].front() - 'a' + 1;
            for(int j = 1; j < words[i].size(); j++)
                hashl[j] = ((hashl[j-1] * p) % m + words[i][j] - 'a' + 1) % m;
            hashr[words[i].size()-1] = words[i].back() - 'a' + 1;
            int cnt = 1;
            for(int j = words[i].size()-2; j >= 0; j--)
                hashr[j] = (hashr[j+1] + ((words[i][j] - 'a' + 1) * pp[cnt++]) % m) % m;
            cnt = 0;
            for(int j = words[i].size()-1; j >= 0; j--){
                long long int hash = 0;
                if(j+1 < words[i].size())
                    hash = (hash + hashr[j+1]) % m;
                if(j-1 >= 0)
                    hash = (hash + (hashl[j-1] * pp[cnt++]) % m) % m;
                if(s.find({words[i].size()-1, hash}) != s.end()){
                    typos = true;
                    cout << words[i] << endl;
                    break;
                }
            }
        }
    if(!typos)
        cout << "NO TYPOS" << endl;
}