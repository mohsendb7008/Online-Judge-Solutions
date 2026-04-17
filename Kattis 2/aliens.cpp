#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> build_sa(const string &s) {
    const int n = static_cast<int>(s.size());
    vector<int> sa(n), rank(n), tmp(n);
    for (int i = 0; i < n; i++) {
        sa[i] = i;
        rank[i] = static_cast<unsigned char>(s[i]);
    }
    for (int k = 1; k < n; k *= 2) {
        auto cmp = [&](const int i, const int j) {
            if (rank[i] != rank[j])
                return rank[i] < rank[j];
            const int ri = i + k < n ? rank[i + k] : -1;
            const int rj = j + k < n ? rank[j + k] : -1;
            return ri < rj;
        };
        sort(sa.begin(), sa.end(), cmp);
        tmp[sa[0]] = 0;
        for (int i = 1; i < n; i++) {
            tmp[sa[i]] = tmp[sa[i - 1]] + (cmp(sa[i - 1], sa[i]) ? 1 : 0);
        }
        rank = tmp;
        if (rank[sa[n - 1]] == n - 1)
            break;
    }
    return sa;
}

vector<int> build_lcp(const string& s, const vector<int>& sa)
{
    const int n = static_cast<int>(s.size());
    vector<int> rank(n), lcp(n);
    for (int i = 0; i < n; i++) {
        rank[sa[i]] = i;
    }
    int h = 0;
    for (int i = 0; i < n; i++) {
        if (rank[i] == 0)
            continue;
        const int j = sa[rank[i] - 1];
        while (i + h < n && j + h < n && s[i + h] == s[j + h]) {
            h++;
        }
        lcp[rank[i]] = h;
        if (h > 0)
            h--;
    }
    return lcp;
}

string s;

constexpr int maxn = 1e5;
int t[2][4 * maxn + 3];

vector<int> sa, lcp;

void build(const int v, const int tl, const int tr, const bool b){
    if(tl == tr)
        t[b][v] = b ? lcp[tl] : sa[tl];
    else{
        const int tm = (tl + tr) / 2;
        build(2 * v, tl, tm, b);
        build(2 * v + 1, tm + 1, tr, b);
        t[b][v] = b ? min(t[b][2 * v], t[b][2 * v + 1]) : max(t[b][2 * v], t[b][2 * v + 1]);
    }
}

int query(const int v, const int tl, const int tr, const int l, const int r, const bool b){
    if(l > r)
        return b ? numeric_limits<int>::max() : numeric_limits<int>::min();
    if(l == tl && r == tr)
        return t[b][v];
    const int tm = (tl + tr) / 2;
    const int left = query(2 * v, tl, tm, l, min(tm, r), b);
    const int right =  query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, b);
    return b ? min(left, right) : max(left, right);
}

int main() {
    int m;
    while (cin >> m && m) {
        cin >> s;
        const int n = static_cast<int>(s.size());
        if (m == 1) {
            cout << n << " " << 0 << endl;
            continue;
        }
        sa = build_sa(s);
        lcp = build_lcp(s, sa);
        build(1, 0, n - 1, true);
        build(1, 0, n - 1, false);
        int ans = 0, index = 0;
        for (int i = 0; i + m - 1 < n; i++) {
            const int c = query(1, 0, n - 1, i + 1, i + m - 1, true);
            const int d = query(1, 0, n - 1, i, i + m - 1, false);
            if (c > ans) {
                ans = c;
                index = d;
            } else if (c == ans && d > index) {
                index = d;
            }
        }
        if (ans)
            cout << ans << " " << index << endl;
        else
            cout << "none" << endl;
    }
}