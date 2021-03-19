#include <bits/stdc++.h>
using namespace std;

class trie{
    public:
    trie* adj[26+3], *parent;
    int edge;
    bool terminal = false;
    int rec, height;

    trie(trie* parent, int edge){
        fill_n(adj, 26, nullptr);
        this->parent = parent;
        this->edge = edge;
    }

    void update(){
        int sumh = 0, maxh = 0;
        for(int i = 0; i < 26; i++)
            if(adj[i] != nullptr)
                sumh += adj[i]->rec, maxh = max(maxh, adj[i]->height);
        this->rec = 1 + sumh;
        this->height = 1 + maxh;
    }
};

const int maxn = 1e5 + 3;

int n, q, x;
string st[maxn];

trie* root = new trie(nullptr, 0);

void dfs(trie* u, int i){
    if(i == st[x].size()){
        u->terminal = true;
        u->update();
        return;
    }
    int v = st[x][i] - 'a';
    if(u->adj[v] == nullptr)
        u->adj[v] = new trie(u, v);
    dfs(u->adj[v], i+1);
    u->update();
}

trie* find(){
    trie* t = root;
    for(int i = 0; i < st[x].size(); i++){
        int v = st[x][i] - 'a';
        if(t->adj[v] == nullptr)
            return nullptr;
        t = t->adj[v];
    }
    if(t->terminal)
        return t;
    return nullptr;
}

void backtrack(trie* u){
    if(u->parent == nullptr)
        return;
    if(u->rec == 1 && !u->terminal)
        u->parent->adj[u->edge] = nullptr;
    u->parent->update();
    backtrack(u->parent);
    if(u->rec == 1 && !u->terminal)
        delete u;
}

char tmp[100001];

int main(){
    scanf("%d %d", &n, &q);
    for(int i = 0; i < n; i++)
        scanf("%s", tmp), st[i] = string(tmp);
    while(q--){
        scanf("%d", &x);
        x--;
        trie* t = find();
        if(t == nullptr)
            dfs(root, 0);
        else
            t->terminal = false, backtrack(t);
        printf("%d\n", 2 * (root->rec - 1) - (root->height - 1));
    }
}