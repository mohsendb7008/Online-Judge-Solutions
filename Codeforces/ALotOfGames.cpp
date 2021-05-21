#include <bits/stdc++.h>
using namespace std;

#define N true
#define P false

class trie{
    public:
    trie* adj[26];
    trie* parent = nullptr;
    bool terminal = false;

    trie(){
        fill_n(adj, 26, nullptr);
    }

    trie(trie* parent){
        fill_n(adj, 26, nullptr);
        this->parent = parent;
    }
};

trie* root = new trie();

inline void trie_insert(string s){
    trie* t = root;
    for(int i = 0; i < s.size(); i++){
        int ind = s[i] - 'a';
        if(t->adj[ind] == nullptr)
            t->adj[ind] = new trie(t);
        t = t->adj[ind];
    }
    t->terminal = true;
}

bool play(trie* t){
    for(int i = 0; i < 26; i++)
        if(t->adj[i] != nullptr && play(t->adj[i]) == P)
            return N;
    return P;
}

bool play_reverse(trie* t){
    bool leaf = true;
    for(int i = 0; i < 26; i++)
        if(t->adj[i] != nullptr){
            leaf = false;
            if(play_reverse(t->adj[i]) == P)
                return N;
        }
    if(leaf)
        return N;
    return P;
}

int main(){
    int n, k;
    cin >> n >> k;
    while(n--){
        string s;
        cin >> s;
        trie_insert(s);
    }
    if(play(root) == P){
        cout << "Second" << endl;
        return 0; 
    }
    if(k == 1){
        cout << "First" << endl;
        return 0;
    }
    if(play_reverse(root) == N){
        cout << "First" << endl;
        return 0;
    }
    if(k % 2)
        cout << "First" << endl;
    else
        cout << "Second" << endl;
}