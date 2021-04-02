#include <bits/stdc++.h>
using namespace std;

// Bing It On

class trie{
    public:
    trie* adj[26+3];
    trie* parent = nullptr;
    bool terminal = false;
    int cnt = 0;

    trie(){
        fill_n(adj, 26, nullptr);
    }

    trie(trie* parent){
        fill_n(adj, 26, nullptr);
        this->parent = parent;
    }
};

trie* root = new trie();

int trie_insert(string s){
    trie* t = root;
    for(int i = 0; i < s.size(); i++){
        int ind = s[i] - 'a';
        if(t->adj[ind] == nullptr)
            t->adj[ind] = new trie(t);
        t = t->adj[ind];
        t->cnt++;
    }
    t->terminal = true;
    return t->cnt - 1;
}

int n;
string s;

int main(){
    cin >> n;
    while(n--)
        cin >> s, cout << trie_insert(s) << endl;
}