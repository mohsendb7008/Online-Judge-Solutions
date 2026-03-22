#include <iostream>
#include <string>

using namespace std;

class trie {
public:
    trie *adj[26];
    trie *parent = nullptr;
    bool terminal = false;

    explicit trie(trie *parent = nullptr) {
        fill_n(adj, 26, nullptr);
        this->parent = parent;
    }
};

auto root = new trie();

inline void trie_insert(const string &s) {
    trie *t = root;
    for (const char c: s) {
        const int ind = c - 'a';
        if (t->adj[ind] == nullptr)
            t->adj[ind] = new trie(t);
        t = t->adj[ind];
    }
    t->terminal = true;
}

inline bool trie_find(const string &s) {
    const trie *t = root;
    for (const char c: s) {
        const int ind = c - 'a';
        if (t->adj[ind] == nullptr)
            return false;
        t = t->adj[ind];
    }
    return t->terminal;
}

pair<char, int> tiles[10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        trie_insert(s);
    }
    cin >> n;
    while (n--) {
        int p;
        cin >> p;
        for (int i = 0; i < p; i++) {
            cin >> tiles[i].first >> tiles[i].second;
        }
        sort(tiles, tiles + p);
        int ans = 0;
        for (int mask = 0; mask < 1 << p; mask++) {
            string s;
            int score = 0;
            for (int i = 0; i < p; i++) {
                if (mask & 1 << i) {
                    s.push_back(tiles[i].first);
                    score += tiles[i].second;
                }
            }
            if (trie_find(s)) {
                ans = max(ans, score);
            }
        }
        cout << ans << endl;
    }
}