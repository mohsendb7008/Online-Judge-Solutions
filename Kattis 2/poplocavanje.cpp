#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

class trie {
public:
    trie *adj[26]{};
    trie *link = nullptr;
    vector<int> suffix;

    trie() {
        fill_n(adj, 26, nullptr);
    }
};

auto root = new trie();

inline void trie_insert(const string &s) {
    trie *t = root;
    for (const char c: s) {
        const int ind = c - 'a';
        if (t->adj[ind] == nullptr)
            t->adj[ind] = new trie();
        t = t->adj[ind];
    }
    t->suffix.push_back(static_cast<int>(s.size()));
}

queue<trie*> bfs;

inline void build() {
    root->link = root;
    for (auto & i : root->adj) {
        if (i != nullptr) {
            i->link = root;
            bfs.push(i);
        } else {
            i = root;
        }
    }
    while (!bfs.empty()) {
        trie* u = bfs.front();
        bfs.pop();
        for (int i = 0; i < 26; i++) {
            if (u->adj[i] != nullptr) {
                trie* v = u->adj[i];
                v->link = u->link->adj[i];
                for (int x : v->link->suffix) {
                    v->suffix.push_back(x);
                }
                bfs.push(v);
            } else {
                u->adj[i] = u->link->adj[i];
            }
        }
    }
}

int n, m, a[300000], b[300000];
string t;

inline void explore() {
    const trie *it = root;
    for (int r = 0; r < n; r++) {
        it = it->adj[t[r] - 'a'];
        for (const int len : it->suffix) {
            const int l = r - len + 1;
            if (l >= 0) {
                a[l]++;
                b[r]++;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> t >> m;
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        trie_insert(s);
    }
    build();
    explore();
    int coverage = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        coverage += a[i];
        if (!coverage) {
            ans++;
        }
        coverage -= b[i];
    }
    cout << ans << endl;
}