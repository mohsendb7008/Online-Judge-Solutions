#include <iostream>
#include <string>
#include <map>
#include <unordered_set>

#define num long long

using namespace std;

class trie {
public:
    map<char, trie*> adj;
    short deg = 0;
};

auto root = new trie();
unordered_set<trie*> check;

inline void trie_insert(const string &s) {
    trie *t = root;
    for (const char c: s) {
        auto it = t->adj.find(c);
        if (it == t->adj.end()) {
            t->adj[c] = new trie();
            t->deg++;
        }
        if (t->deg > 1)
            check.insert(t);
        t = t->adj[c];
    }
    t->deg++;
    if (t->deg > 1)
        check.insert(t);
}

num fact[28];
constexpr num mod = 1000000007;
int n, i;
string s;
num ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    fact[0] = 1;
    for (i = 1; i < 28; i++) {
        fact[i] = fact[i-1] * i % mod;
    }
    cin >> n;
    while (n--) {
        cin >> s;
        trie_insert(s);
    }
    ans = 1;
    for (const auto t : check) {
        ans = ans * fact[t->deg] % mod;
    }
    cout << ans << '\n';
}