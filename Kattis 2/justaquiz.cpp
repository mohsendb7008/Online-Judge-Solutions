#include <bits/stdc++.h>
using namespace std;

struct Node {
    unordered_map<string, int> child;
    unordered_map<int, int> freq;
    int cnt = 0, best = 0;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n;
    cin >> t >> n;
    cin.ignore();

    vector<Node> trie(1);
    unordered_map<string, int> answerId;

    for (int i = 0; i < n; i++) {
        string line, word;
        getline(cin, line);
        stringstream ss(line);

        vector<string> words;
        while (ss >> word)
            words.push_back(word);

        string answer = words.back();
        words.pop_back();

        if (!answerId.count(answer))
            answerId[answer] = answerId.size();

        int id = answerId[answer];
        int v = 0;

        auto update = [&](int u) {
            trie[u].cnt++;
            int f = ++trie[u].freq[id];
            trie[u].best = max(trie[u].best, f);
        };

        update(v);

        for (const string& w : words) {
            auto it = trie[v].child.find(w);

            if (it == trie[v].child.end()) {
                int u = trie.size();
                trie[v].child[w] = u;
                trie.emplace_back();
                v = u;
            } else {
                v = it->second;
            }

            update(v);
        }
    }

    int m = trie.size();
    vector<double> dp(m, 0), ndp(m, 0);

    for (int time = 1; time <= t; time++) {
        for (int v = 0; v < m; v++) {
            double take = (double)trie[v].best / trie[v].cnt + dp[0];
            double wait = 0;

            if (!trie[v].child.empty()) {
                for (auto& [word, u] : trie[v].child) {
                    wait += (double)trie[u].cnt / trie[v].cnt * dp[u];
                }
            }

            ndp[v] = max(take, wait);
        }

        dp.swap(ndp);
    }

    cout << fixed << setprecision(10) << dp[0] << '\n';
}
