#include <bits/stdc++.h>
using namespace std;

// Wordle with Friends

int n, w;
map<int, char> exact;
map<int, set<char> > nt;
vector<pair<char, pair<int, int> > > cond;

int main(){
    cin >> n >> w;
    while(n--){
        string g, f;
        cin >> g >> f;
        for(int i = 0; i < 5; i++){
            if(f[i] == 'G'){
                exact[i] = g[i];
            }
            else{
                nt[i].insert(g[i]);
            }
        }
        map<char, pair<int, pair<int, int> > > cnt;
        for(int i = 0; i < 5; i++){
            if(f[i] == 'G'){
                cnt[g[i]].first++;
            }else if(f[i] == 'Y'){
                cnt[g[i]].second.first++;
            }else if(f[i] == '-'){
                cnt[g[i]].second.second++;
            }
        }
        for(auto it : cnt){
            int lower = it.second.first + it.second.second.first;
            if(it.second.second.second){
                cond.push_back(make_pair(it.first, make_pair(lower, lower)));
            }else{
                cond.push_back(make_pair(it.first, make_pair(lower, INT_MAX)));
            }
        }
    }
    while(w--){
        string s;
        cin >> s;
        bool ok = true;
        for(int i = 0; i < 5; i++){
            if(exact.find(i) != exact.end() && exact[i] != s[i]){
                ok = false;
                break;
            }
            if(nt.find(i) != nt.end() && nt[i].find(s[i]) != nt[i].end()){
                ok = false;
                break;
            }
        }
        if(!ok){
            continue;
        }
        map<char, int> cnt;
        for(int i = 0; i < 5; i++){
            cnt[s[i]]++;
        }
        for(auto it : cond){
            if(cnt[it.first] >= it.second.first && cnt[it.first] <= it.second.second){
                continue;
            }
            ok = false;
            break;
        }
        if(!ok){
            continue;
        }
        cout << s << endl;
    }
}