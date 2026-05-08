/**
 * Authors: Mohsen Dehbashi, Ghazal Rabiei
 *
 * Disjoint Sets (Union-Find) data structure.
 *
 * Supports:
 *  - Union by rank
 *  - Path compression
 *  - Tracking component sizes
 *
 * Assumptions:
 *  - Elements are indexed from 0 to N-1.
 */

#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

/**
 * DisjointSets maintains a collection of disjoint components.
 * It supports merging components and querying whether two elements belong to the same component.
 */
class DisjointSets {
    vector<int> parent, ranking, setSize;

public:
    int numSets;

    /**
     * Constructs n singleton components.
     */
    explicit DisjointSets(const int n) {
        parent.assign(n, 0);
        iota(parent.begin(), parent.end(), 0);
        ranking.assign(n, 0);
        setSize.assign(n, 1);
        numSets = n;
    }

    /**
     * Returns the root (representative) of the component containing v.
     */
    int GetComponentRoot(const int v) {
        if (v == parent[v])
            return v;
        return parent[v] = GetComponentRoot(parent[v]);
    }

    /**
     * Checks whether elements u and v belong to the same component.
     */
    bool Connected(const int u, const int v) {
        return GetComponentRoot(u) == GetComponentRoot(v);
    }

    /**
     * Returns the size of the component containing v.
     */
    int GetComponentSize(const int v) {
        return setSize[GetComponentRoot(v)];
    }

    /**
     * Merges the components containing u and v.
     * Returns true if a merge occurred, false otherwise.
     */
    bool UniteComponents(int u, int v) {
        u = GetComponentRoot(u);
        v = GetComponentRoot(v);
        if (u != v) {
            if (ranking[u] < ranking[v])
                swap(u, v);
            parent[v] = u;
            if (ranking[u] == ranking[v])
                ranking[u]++;
            setSize[u] += setSize[v];
            setSize[v] = 0;
            numSets--;
            return true;
        }
        return false;
    }
};

#include <set>
set<pair<int, int>> dir;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    DisjointSets disjointSets(N);
    while (Q--) {
        char c;
        int a, b;
        cin >> c >> a >> b;
        if (c == 'f') {
            dir.insert({min(a, b), max(a, b)});
            disjointSets.UniteComponents(a, b);
        }
        if (c == 's') {
            if (dir.find({min(a, b), max(a, b)}) != dir.end()) {
                cout << a << " + " << b << endl;
            } else if (disjointSets.Connected(a, b)) {
                cout << a << " - " << b << endl;
            } else {
                cout << a << " ? " << b << endl;
            }
        }
    }
}
