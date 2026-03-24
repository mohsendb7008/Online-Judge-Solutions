#include <iostream>
#include <vector>
#include <queue>

#define inf numeric_limits<int>::max()

using namespace std;

vector<int> s, sa, ra;
vector<pair<pair<int, int>, int> > tmp;
pair<int, int> prevy, nil = {-1, -1};

inline void suffix_array() {
    const int n = static_cast<int>(s.size());
    sa.assign(n, 0);
    ra.assign(n, 0);
    for (int i = 0; i < n; i++)
        sa[i] = i, ra[i] = s[sa[i]];
    for (int k = 1; k < n; k *= 2) {
        tmp.clear();
        for (int i = 0; i < n; i++)
            tmp.push_back({{ra[sa[i]], sa[i] + k >= n ? 0 : ra[sa[i] + k]}, sa[i]});
        sort(tmp.begin(), tmp.end());
        int cnt = -1;
        prevy = nil;
        for (int i = 0; i < n; i++) {
            sa[i] = tmp[i].second;
            if (tmp[i].first != prevy)
                cnt++;
            ra[sa[i]] = cnt;
            prevy = tmp[i].first;
        }
        if (ra[sa[n - 1]] == n - 1)
            break;
    }
}

struct Compare {
    bool operator()(const int a, const int b) const {
        return ra[a] > ra[b];
    }
};

priority_queue<int, vector<int>, Compare> pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int l;
        cin >> l;
        while (l--) {
            int x;
            cin >> x;
            s.push_back(x);
        }
        s.push_back(inf);
    }
    suffix_array();
    n = static_cast<int>(s.size());
    bool add = true;
    for (int i = 0; i < n; i++) {
        if (add) {
            pq.push(i);
            add = false;
        }
        else if (s[i] == inf) {
            add = true;
        }
    }
    while (!pq.empty()) {
        int u = pq.top();
        pq.pop();
        cout << s[u] << " ";
        u++;
        if (s[u] != inf) {
            pq.push(u);
        }
    }
    cout << endl;
}