#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>

using namespace std;

class trie {
public:
    trie *adj[52]{};
    trie() {
        fill_n(adj, 52, nullptr);
    }
};

inline void trie_insert(trie* t, const vector<int> &s, int &nodes) {
    for (const int ind: s) {
        if (t->adj[ind] == nullptr) {
            t->adj[ind] = new trie();
            nodes++;
        }
        t = t->adj[ind];
    }
}

vector<int> v;
map<char, int> h {
    {'C', 0},
    {'D', 1},
    {'H', 2},
    {'S', 3},
    {'A', 0},
    {'2', 1},
    {'3', 2},
    {'4', 3},
    {'5', 4},
    {'6', 5},
    {'7', 6},
    {'8', 7},
    {'9', 8},
    {'1', 9},
    {'J', 10},
    {'Q', 11},
    {'K', 12}
};

int main() {
    while (true) {
        int n;
        cin >> n;
        if (!n)
            break;
        const auto t = new trie();
        int ans = 0;
        while (n--) {
            int m;
            cin >> m;
            v.clear();
            while (m--) {
                string str;
                cin >> str;
                v.push_back(h[str[0]] * 4 + (str[1] == '0' ? h[str[2]] : h[str[1]]));
            }
            reverse(v.begin(), v.end());
            trie_insert(t, v, ans);
        }
        cout << ans << endl;
        delete t;
    }
}