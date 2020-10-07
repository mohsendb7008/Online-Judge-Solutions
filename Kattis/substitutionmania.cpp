#include <bits/stdc++.h>
using namespace std;

// Substitution Mania!

int n, a[12 + 3];
string source, target, tmps, q, codes[12 + 3], rcodes[12 + 3];
set<char> uni;
set<int> indices;
map<char, char> tmp; 

inline string decode(string& s, string& code){
    string ans = "";
    for(char c : s){
        if(c >= 'a' && c <= 'z')
            ans += code[c - 'a'];
        else ans += c;
    }
    return ans;
}

inline bool feasible(vector<int>& v1, vector<int>& v2){
    fill_n(a, n, 0);
    for(int i : v1)
        a[i]++;
    for(int i : v2)
        a[i]++;
    for(int i = 0; i < n; i++)
        if(a[i] != 1)
            return false;
    return true;
}

unordered_map<string, vector<int>> leftt, rightt;

inline void produce(int mask){
    vector<int> v;
    for(int i = 0; i < n; i++)
        if(mask & (1 << i))
            v.push_back(i);
    do{
        string it = source;
        for(int i : v)
            it = decode(it, codes[i]);
        leftt[it] = v;
        it = target;
        for(int i : v)
            it = decode(it, rcodes[i]);
        rightt[it] = v;
    }while(next_permutation(v.begin(), v.end()));
}

int main(){
    getline(cin, source);
    uni.clear();
    for(int i = 0; i < source.size(); i++)
        if(source[i] >= 'a' && source[i] <= 'z' && uni.find(source[i]) == uni.end())
            uni.insert(source[i]), indices.insert(i);
    getline(cin, target);
    uni.clear();
    for(int i = 0; i < target.size(); i++)
        if(target[i] >= 'a' & target[i] <= 'z' && uni.find(target[i]) == uni.end())
            uni.insert(target[i]), indices.insert(i);
    tmps = "";
    for(int i = 0; i < source.size(); i++)
        if(indices.find(i) != indices.end())
            tmps += source[i];
    source = tmps;
    tmps = "";
    for(int i = 0; i < target.size(); i++)
        if(indices.find(i) != indices.end())
            tmps += target[i];
    target = tmps;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> codes[i];
        tmp.clear();
        for(int j = 0; j < codes[i].size(); j++)
            tmp[codes[i][j]] = 'a' + j;
        rcodes[i] = "";
        for(pair<char, char> c : tmp)
            rcodes[i] += c.second;
    }
    cin.ignore();
    getline(cin, q);
    if(n == 1)
        cout << decode(q, rcodes[0]) << endl;
    else{
        for(int mask = 0; mask < (1 << n); mask++){
            int cnt = 0, cp = mask;
            while(cp){
                if(cp % 2)
                    cnt++;
                cp /= 2;
            }
            if(cnt == n / 2 || (n % 2 && cnt == n / 2 + 1))
                produce(mask);
        }
        for(auto p : leftt){
            auto f = rightt.find(p.first);
            if(f != rightt.end())
                if(feasible(p.second, f->second)){
                    for(int i : f->second)
                        q = decode(q, rcodes[i]);
                    for(int i = p.second.size() - 1; i >= 0; i--)
                        q = decode(q, rcodes[p.second[i]]);
                    cout << q << endl;
                    return 0;
                }
        }
    }
}


