#include <iostream>
#include <numeric>
#include <vector>
#include <unordered_map>
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

unordered_map<string, int> id;
vector<pair<int, int>> bridge;

inline int getId(const string& s) {
    const auto it = id.find(s);
    if (it != id.end())
        return it->second;
    return id[s] = id.size();
}

int main() {
    int m;
    cin >> m;
    while (m--) {
        string a, b;
        cin >> a >> b;
        bridge.emplace_back(getId(a), getId(b));
    }
    const int n = id.size();
    auto sets = DisjointSets(n);
    for (const auto p : bridge) {
        sets.UniteComponents(p.first, p.second);
        cout << sets.GetComponentSize(p.first) << endl;
    }
}