#include <iostream>
#include <string>
#include <map>
#include <queue>
using namespace std;

class trie {
public:
    trie *adj[26]{};
    trie *parent = nullptr;
    int dicti = numeric_limits<int>::max();

    explicit trie(trie *parent = nullptr) {
        fill_n(adj, 26, nullptr);
        this->parent = parent;
    }
};

auto root = new trie();

inline trie* trie_insert(const string &s, const int i) {
    trie *t = root;
    for (const char c: s) {
        const int index = c - 'a';
        if (t->adj[index] == nullptr)
            t->adj[index] = new trie(t);
        t = t->adj[index];
        t->dicti = min(t->dicti, i);
    }
    return t;
}

trie* dictionary[100000];
map<trie*, int> dis;
queue<trie*> bfs;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    string word;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> word;
        dictionary[i] = trie_insert(word, i);
    }
    dis[root] = 0;
    bfs.push(root);
    while (!bfs.empty()) {
        auto *u = bfs.front();
        bfs.pop();
        // type one char:
        for (auto *v : u->adj) {
            if (v != nullptr && dis.find(v) == dis.end()) {
                dis[v] = dis[u] + 1;
                bfs.push(v);
            }
        }
        // backspace:
        if (u->parent != nullptr && dis.find(u->parent) == dis.end()) {
            dis[u->parent] = dis[u] + 1;
            bfs.push(u->parent);
        }
        // jump with tab:
        if (u->dicti != numeric_limits<int>::max()) {
            auto *v = dictionary[u->dicti];
            if (dis.find(v) == dis.end()) {
                dis[v] = dis[u] + 1;
                bfs.push(v);
            }
        }
    }
    while (m--) {
        cin >> word;
        trie *t = root;
        int ans = static_cast<int>(word.size());
        for (const char c : word) {
            const int index = c - 'a';
            if (t->adj[index] == nullptr)
                break;
            t = t->adj[index];
            ans--;
        }
        ans += dis[t];
        cout << ans << endl;
    }
}