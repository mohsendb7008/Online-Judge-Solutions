#include <iostream>
using namespace std;

#define rank rrank

int parent[1000001], rank[1000001], sets = 0;

void make_set(const int v) {
    parent[v] = v;
    rank[v] = 0;
    sets++;
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
        sets--;
    }
}

int n, m, q, grid[1001][1001], ans[10001];
struct stroke {
    int x1, y1, x2, y2;
} strokes[10001];

int adjR[4]{0, 0, -1, 1};
int adjC[4]{-1, 1, 0, 0};

inline void activate(const int u, const int v) {
    make_set(u * m + v);
    for (int k = 0; k < 4; k++) {
        const int p = u + adjR[k];
        const int t = v + adjC[k];
        if (p >= 0 && p < n && t >= 0 && t < m && grid[p][t] == 0 && parent[p * m + t] != -1) {
            union_sets(u * m + v, p * m + t);
        }
    }
}

inline void apply_strokes() {
    for (int i = 0; i < q; i++) {
        if (strokes[i].x1 == strokes[i].x2) {
            for (int j = strokes[i].y1; j <= strokes[i].y2; j++) {
                grid[strokes[i].x1-1][j-1]++;
            }
        }
        else if (strokes[i].y1 == strokes[i].y2) {
            for (int j = strokes[i].x1; j <= strokes[i].x2; j++) {
                grid[j-1][strokes[i].y1-1]++;
            }
        }
    }
}

inline void reverse_strokes() {
    for (int i = q-1; i >= 0; i--) {
        ans[i] = sets;
        if (strokes[i].x1 == strokes[i].x2) {
            for (int j = strokes[i].y1; j <= strokes[i].y2; j++) {
                grid[strokes[i].x1-1][j-1]--;
                if (grid[strokes[i].x1-1][j-1] == 0) {
                    activate(strokes[i].x1-1, j-1);
                }
            }
        }
        else if (strokes[i].y1 == strokes[i].y2) {
            for (int j = strokes[i].x1; j <= strokes[i].x2; j++) {
                grid[j-1][strokes[i].y1-1]--;
                if (grid[j-1][strokes[i].y1-1] == 0) {
                    activate(j-1, strokes[i].y1-1);
                }
            }
        }
    }
}

int main() {
    cin >> n >> m >> q;
    for (int i = 0; i < q; i++) {
        cin >> strokes[i].x1 >> strokes[i].y1 >> strokes[i].x2 >> strokes[i].y2;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            grid[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            parent[i * m + j] = -1;
        }
    }
    apply_strokes();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 0) {
                activate(i, j);
            }
        }
    }
    reverse_strokes();
    for (int i = 0; i < q; i++) {
        cout << ans[i] << endl;
    }
}
