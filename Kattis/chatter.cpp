#include <iostream>
#include <map>

using namespace std;

#define rank rrank

int parent[10001], rank[10001];

void make_set(const int v) {
    parent[v] = v;
    rank[v] = 0;
}

int find_set(const int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
    }
}

inline int get_random(int& r, const int a, const int b, const int c) {
    return r = (r * a + b) % c;
}

int main() {
    int n, r, a, b, c;
    while (cin >> n >> r >> a >> b >> c) {
        for (int i = 0; i < n; i++) {
            make_set(i);
        }
        for (int i = 0; i < n; i++) {
            const int x = get_random(r, a, b, c) % n;
            const int y = get_random(r, a, b, c) % n;
            if (x == y) {
                i--;
                continue;
            }
            union_sets(x, y);
        }
        map<int, int> group;
        for (int i = 0; i < n; i++) {
            group[find_set(i)]++;
        }
        map<int, int> ans;
        for (auto it : group) {
            ans[it.second]++;
        }
        cout << group.size() << " ";
        for (auto it = ans.rbegin(); it != ans.rend(); ++it) {
            cout << it->first;
            if (it->second > 1) {
                cout << 'x' << it->second;
            }
            cout << " ";
        }
        cout << endl;
    }
}