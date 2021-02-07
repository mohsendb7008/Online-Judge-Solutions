#include <bits/stdc++.h>
using namespace std;

// Shopping List

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

inline void trie_insert(string& s){
    trie* t = root;
    for(int i = 0; i < s.size(); i++){
        int ind = s[i] - 'a';
        if(t->adj[ind] == nullptr)
            t->adj[ind] = new trie(t);
        t = t->adj[ind];
    }
    t->terminal = true;
    t->cnt++;
}

string current = "";

void trie_dfs(trie* node, int n, vector<string>& res){
    if(node->terminal && node->cnt == n)
        res.push_back(current);
    for(int i = 0; i < 26; i++)
        if(node->adj[i] != nullptr){
            current.push_back('a' + i);
            trie_dfs(node->adj[i], n, res);
            current.pop_back();
        }
}

int n, m;
set<string> basket;
vector<string> ans;

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        basket.clear();
        for(int j = 0; j < m; j++){
            string s;
            cin >> s;
            basket.insert(s);
        }
        for(string s : basket)
            trie_insert(s);
    }
    trie_dfs(root, n, ans);
    cout << ans.size() << endl;
    for(string s : ans)
        cout << s << endl;
}